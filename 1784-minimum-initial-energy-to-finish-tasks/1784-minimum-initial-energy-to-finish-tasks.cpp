class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(),tasks.end(),[](vector<int> &a,vector<int> &b)
        {
            return a[1]-a[0] > b[1]-b[0];
        });

        int n = tasks.size();

        int res=0;
        int left=0;

        for(int i=0;i<n;i++)
        {
            int req = tasks[i][1];
            int used = tasks[i][0];

            if(left<req)
            {
                res+=(req-left);
                left=(req);

                left-=used;
            }
            else
            {
                left-=used;
            }
        }

        return res;
    }
};