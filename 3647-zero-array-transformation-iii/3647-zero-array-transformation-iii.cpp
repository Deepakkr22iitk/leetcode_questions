class Solution {
public:
    // The idea is that I'll sort the queries. 
    // For any nums[i] to become '0' there must be atleast nums[i] queries covering this particular i'th index. 
    // I can greedily choose these number of queries such that this particular i'th index is covered and corresponding
    // 'r' is largest.
    // I'm also making sure that if I'm at i'th index then all the values before i i.e., (i-1) till '0' is already reduced
    // to zero.
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q_len=queries.size();
        sort(queries.begin(),queries.end());
        priority_queue<int>candidates;          // Max Heap to store the larger values
        priority_queue<int,vector<int>,greater<int>>chosen;    

        int pick=0;
        int j=0;

        for(int i=0;i<n;++i)
        {
            while(j<q_len && queries[j][0]==i) // While i'th index is covered in the query, candidate should be built up
            {
                candidates.push(queries[j][1]);
                j++;
            }

            nums[i]-=chosen.size();    // previous contribution covering this particular index too.

            while(nums[i]>0 && !candidates.empty() && candidates.top()>=i)
            {
                pick++;
                auto temp=candidates.top();
                candidates.pop();
                chosen.push(temp);
                nums[i]--;
            }

            if(nums[i]>0) return -1; // Even after adding all the queries having start as 'i' and previous contribution then not possible

            while(!chosen.empty() && chosen.top()==i) chosen.pop();   // If the 'r' of chosen equals 'i' only then It can't be used for (i+1) in next iteration. so, simply removing them.

        }

        return (q_len-pick);
    }
};