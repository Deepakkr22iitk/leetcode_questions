class Solution {
public:
    // The idea is to use Backtracking to try out all the possibilities and generate the lexi maxm.
    // Due to backtracking, we will skip lots of the cases. O(N!) is a very loose upper bound which corresponds to visiting 
    // all the permutations. We actually only visit cases far less than that.
    
    vector<int>vis;
    bool recursion(int n,int idx,vector<int>&ans)
    {
        if(idx==ans.size()) return true;
        if(ans[idx]>0) return recursion(n,idx+1,ans);  // If already set then move to the next index

        for(int i=n;i>=1;--i)
        {
            if(vis[i]==1) continue;

            if(i!=1 && (i+idx>=ans.size() || ans[i+idx])) continue;

            vis[i]=1;   
            ans[idx]=i;  
            if(i!=1) ans[idx+i]=i;
			
            if(recursion(n,idx+1,ans)) return true;  
            
			vis[i]=0;  
            ans[idx]=0; 
            if(i!=1) ans[idx+i]=0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vis.resize(n+1,0);
        int m=2*(n-1)+1;
        vector<int>ans(m);
        recursion(n,0,ans);
        return ans;
    }
};