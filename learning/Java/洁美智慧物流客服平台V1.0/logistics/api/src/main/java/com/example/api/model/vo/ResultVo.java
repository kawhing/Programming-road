package com.example.api.model.vo;

public class ResultVo<T> {
    private int code;
    private boolean status;
    private String msg;
    private T data;

    public ResultVo() {}

    public ResultVo(int code, boolean status, String msg, T data) {
        this.code = code;
        this.status = status;
        this.msg = msg;
        this.data = data;
    }

    public static <T> ResultVo<T> success(T data) {
        return new ResultVo<>(200, true, "success", data);
    }

    public static <T> ResultVo<T> success() {
        return new ResultVo<>(200, true, "success", null);
    }

    public static <T> ResultVo<T> error(String msg) {
        return new ResultVo<>(500, false, msg, null);
    }

    public int getCode() { return code; }
    public void setCode(int code) { this.code = code; }
    public boolean isStatus() { return status; }
    public void setStatus(boolean status) { this.status = status; }
    public String getMsg() { return msg; }
    public void setMsg(String msg) { this.msg = msg; }
    public T getData() { return data; }
    public void setData(T data) { this.data = data; }
}

