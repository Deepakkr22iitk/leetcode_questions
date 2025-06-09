class Solution {
public:
    // Explaination of this height calculation using prefix1 and prefix2 is Neat.
    // Great explanation by 'Nathan'
    // Actually this is a denary tree (each node has 10 children). Find the kth element is to do a k steps preorder traverse of the tree.
    // we don't really need to do a exact k steps preorder traverse of the denary tree, the idea is to calculate the steps between 
    // curr and curr + 1 (neighbor nodes in same level), in order to skip some unnecessary moves.
    int helper(long long n,long long curr, long long next)
    {
        int nodes=0;
        while(curr<=n)
        {
            long long curr_nodes=min((long long)(n+1), next)-curr;    // This next and curr are important to calculate the
            nodes+=curr_nodes;                              // no.of nodes and we are taking minimum because at the last level
            curr*=10;                                       // the values can be less. 
            next*=10;                                       // nodes= (2-1)+(20-10)+(200-100)+(min(1361+1,2000)-1000) if n=1361 and k=400
        }
        return nodes;
    }
    int findKthNumber(int n, int k) {
        k--;  // Since, we are initially at '1' and we need to move forward now (k-1) steps to target node 'x'
        long long curr=1;

        while(k>0)
        {
            // helper function calculates how many steps 'curr' need to move to 'curr+1'    i.e., [1,10,11,12,...,100,101,...,1001,...1361],2
            int no_of_children_including_node=helper(n,curr,curr+1);
            if(no_of_children_including_node<=k)
            {
                curr++;
                k-=no_of_children_including_node;
            }
            else // If steps>k, that means the (curr+1) is actually behind the target node 'x' in pre-order path. we can't jump directly to
            {    // (curr+1). We should move only '1' step forward (so, curr*10 is always next pre-order node)
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};