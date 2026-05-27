class Solution {
public:
    vector<int> proc(string log){
        vector<int> procInfo;
        int flag = -1;
        for(int i = 0; i < log.size(); ++i){
            if(log[i] == ':' && flag == -1){
                string temp = log.substr(0, i);
                flag = i;
                procInfo.push_back(stoi(temp));
            }else if(log[i] == ':' && flag != -1){
                string temp = log.substr(flag + 1, i - flag - 1);
                if(temp == "start"){
                    procInfo.push_back(0);
                }else if(temp == "end"){
                    procInfo.push_back(1);
                }
                flag = i;
            }
        }
        string temp = log.substr(flag + 1, log.size() - flag - 1);
        procInfo.push_back(stoi(temp));
        return procInfo;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> runTime(n, 0);
        stack<vector<int>> runLog;
        for(string log : logs){
            vector<int> funInfo = proc(log);
            if(funInfo[1] == 0){
                if(runLog.size() != 0){
                    runTime[runLog.top()[0]] += funInfo[2] - runLog.top()[1];
                    runLog.top()[1] = funInfo[2];
                }
                runLog.push({funInfo[0], funInfo[2]});
            }else if(funInfo[1] == 1){
                vector<int> temp = runLog.top();
                runLog.pop();
                runTime[temp[0]] += funInfo[2] - temp[1] + 1;
                if(runLog.size() != 0){
                    runLog.top()[1] = funInfo[2] + 1;
                }
            }
        }
        return runTime;
    }
};