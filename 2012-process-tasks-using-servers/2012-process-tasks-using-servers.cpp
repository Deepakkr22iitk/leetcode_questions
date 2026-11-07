class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>ans(m);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>available;
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>busy;
        for(int i=0;i<n;i++){
            available.push({servers[i],i});
        }
    
        for(int i=0;i<m;i++){
            while(!busy.empty() && busy.top().first<=i){
                auto [freeTime,server]=busy.top();
                busy.pop();
                available.push(server);
            }
            if(!available.empty()){
                auto [server,idx]=available.top();
                available.pop();
                ans[i]=idx;
                busy.push({i+tasks[i],{server,idx}});
            }
            else{
                auto[freeTime,serverr]=busy.top();
                busy.pop();
                auto [server,idx]=serverr;
                ans[i]=idx;
                busy.push({freeTime+tasks[i],{server,idx}});
            }
        }
        return ans;
    }
};