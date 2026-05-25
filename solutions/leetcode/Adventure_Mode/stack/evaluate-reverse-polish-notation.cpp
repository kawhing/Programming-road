class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string i : tokens){
            if(i == "/" || i == "*" || i == "+" || i == "-"){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                
                int intermediateResult;
                if(i == "/"){
                    intermediateResult = a / b;
                }else if(i == "*"){
                    intermediateResult = a * b;
                }else if(i == "+"){
                    intermediateResult = a + b;
                }else if(i == "-"){
                    intermediateResult = a - b;
                }

                stk.push(intermediateResult);
            }else{
                stk.push(stoi(i));
            }
        }
        return stk.top();
    }
};