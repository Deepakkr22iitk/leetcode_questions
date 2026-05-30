class Solution {
public:
    vector<int> seg;
    int MAXI = 50000;

    void update(int node,int l,int r,int idx,int val){
        if(l == r){
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if(idx <= mid){
            update(2 * node,l,mid,idx,val);
        }
        else{
            update(2 * node + 1,mid + 1,r,idx,val);
        }

        seg[node] = max(seg[2 * node],seg[2 * node + 1]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr < l || ql > r)return 0;

        if(ql <= l && r <= qr){
            return seg[node];
        }

        int mid = (l + r) / 2;

        return max(
            query(2 * node,l,mid,ql,qr),
            query(2 * node + 1,mid + 1,r,ql,qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        seg.resize(4 * (MAXI + 1),0);

        set<int> barriers;
        barriers.insert(0);

        for(auto &q:queries){
            if(q[0] == 1){
                barriers.insert(q[1]);
            }
        }

        vector<int> positions(barriers.begin(),barriers.end());

        for(int i=1;i<positions.size();i++){
            update(1,0,MAXI,positions[i],positions[i] - positions[i - 1]);
        }

        vector<bool> ans;

        for(int i=queries.size()-1;i>=0;i--){

            if(queries[i][0] == 2){
                int x = queries[i][1];
                int sz = queries[i][2];

                auto it = prev(barriers.upper_bound(x));

                int prevBarrier = *it;
                int bestGap = query(1,0,MAXI,0,prevBarrier);

                bestGap = max(bestGap,x - prevBarrier);
                ans.push_back(bestGap >= sz);
            }
            else{
                int x = queries[i][1];
                auto it = barriers.find(x);
                int leftBarrier = *prev(it);

                update(1,0,MAXI,x,0);

                auto rightIt = next(it);

                if(rightIt != barriers.end()){
                    int rightBarrier = *rightIt;
                    update(1,0,MAXI,rightBarrier,rightBarrier - leftBarrier);
                }

                barriers.erase(it);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};