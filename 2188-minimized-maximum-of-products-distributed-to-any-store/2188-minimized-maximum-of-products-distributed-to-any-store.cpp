class Solution {
    bool isPossible(vector<int>& q,int n,int barrier){
        int cnt=0;
        for(int i=0;i<q.size();i++){
            if(q[i]<=barrier){
                cnt++;
            }
            else{
                int temp=q[i];
                while(temp>0){
                    temp-=barrier;
                    cnt++;
                }
            }
            if(cnt>n) return false;
        }
        return true;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int start=1,end=*max_element(q.begin(),q.end());
        
        int ans = INT_MAX;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(q,n,mid)){
                ans = min(ans,mid);
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};