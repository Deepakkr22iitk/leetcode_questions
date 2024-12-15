class Solution {
public:
    // For example, even though 1/2 and 10/20 has the same ratio. However, 1/2's delta is equal to (1+1)/(2+1)-1/2, 
    // which is much greater than (10+1)/(20+1)-10/20.Therefore, we always greedily select the one with the greatest delta.
    // We can acheive this using a max heap. In C++, we can use the priority queue.
    // If you keep adding students, what happens to the change in pass ratio? The more students you add to a class, 
    // the smaller the change in pass ratio becomes.
    struct cmp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            double ad = (a.first+1)/(double)(a.second+1) - (a.first)/(double)a.second;
            double bd = (b.first+1)/(double)(b.second+1) - (b.first)/(double)b.second;
            return (ad<bd);
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double n=classes.size();
        double acc=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>pq; // It will prioritize such that the largest delta is at top

        for(vector<int> &x: classes) pq.push({x[0],x[1]});

        // while(!pq.empty()) 
        // {
        //     auto temp=pq.top();
        //     pq.pop();
        //     cout<<temp.first<<" "<<temp.second<<"\n";
        // }

        while(extraStudents--)
        {
            pair<int,int> cur=pq.top(); 
            pq.pop();
            cur.first++, cur.second++;
            pq.push(cur);
        }
        while(!pq.empty())
        {
            pair<int,int> cur=pq.top(); 
            pq.pop();
            acc+= cur.first / (double) cur.second;
        }
        return acc/n;
    }
};