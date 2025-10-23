package com.example.api.handler;

import com.example.api.annotation.DisableBaseResponse;
import com.example.api.model.support.ResponseResult;
import org.springframework.core.MethodParameter;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.http.server.ServerHttpRequest;
import org.springframework.http.server.ServerHttpResponse;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.servlet.mvc.method.annotation.ResponseBodyAdvice;

/**
 * 统一拦截Controller中所有方法的返回值
 * 封装后返回ResponseResult<T>
 */
@ControllerAdvice(value = "com.example.api.controller")
public class GlobalResponseHandler implements ResponseBodyAdvice<Object> {


    @Override
    public boolean supports(MethodParameter methodParameter, Class c) {
        // If method or class annotated with DisableBaseResponse, skip
        if (methodParameter.getMethod() != null && methodParameter.getMethod().isAnnotationPresent(DisableBaseResponse.class)) {
            return false;
        }
        if (methodParameter.getDeclaringClass() != null && methodParameter.getDeclaringClass().isAnnotationPresent(DisableBaseResponse.class)) {
            return false;
        }
        // If controller method returns ResponseEntity or String, skip wrapping
        if (methodParameter.getMethod() != null) {
            Class<?> returnType = methodParameter.getMethod().getReturnType();
            if (ResponseEntity.class.isAssignableFrom(returnType) || String.class.equals(returnType)) {
                return false;
            }
        }
        return true;
    }

    @Override
    public Object beforeBodyWrite(Object o, MethodParameter methodParameter, MediaType mediaType, Class aClass,
                                  ServerHttpRequest serverHttpRequest, ServerHttpResponse serverHttpResponse) {
        // If already a ResponseResult, don't wrap again
        if (o instanceof ResponseResult) {
            ResponseResult<?> rr = (ResponseResult<?>) o;
            Integer code = rr.getCode();
            try {
                if (code != null && code >= 100 && code <= 599) {
                    serverHttpResponse.setStatusCode(HttpStatus.valueOf(code));
                }
            } catch (Exception ex) {
                // ignore invalid status code
            }
            return o;
        }
        ResponseResult<?> result = o == null ? new ResponseResult<>() : new ResponseResult<>(o);
        // Ensure the HTTP status reflects the result.code
        Integer code = result.getCode();
        try {
            if (code != null && code >= 100 && code <= 599) {
                serverHttpResponse.setStatusCode(HttpStatus.valueOf(code));
            }
        } catch (Exception ex) {
            // ignore invalid status code
        }
        return result;
    }

}
