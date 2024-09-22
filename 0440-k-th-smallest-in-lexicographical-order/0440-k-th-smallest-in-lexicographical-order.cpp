class Solution {
public:
    int helper(long long n,long long curr, long long next)
    {
        int nodes=0;
        while(curr<=n)
        {
            long long curr_nodes=min((long long)(n+1), next)-curr;    // This next and curr are important to calculate the
            nodes+=curr_nodes;                                   // no.of nodes and we are taking minimum because at the last level
            curr*=10;                                          // the values can be less 
            next*=10;                                       // nodes= (2-1)+(20-10)+(200-100)+(1361-1000+1) if n=1361 and k=400
        }
        return nodes;
    }
    int findKthNumber(int n, int k) {
        k--;
        long long curr=1;

        while(k>0)
        {
            int no_of_children_including_node=helper(n,curr,curr+1);

            if(no_of_children_including_node<=k)
            {
                curr++;
                k-=no_of_children_including_node;
            }
            else 
            {
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};