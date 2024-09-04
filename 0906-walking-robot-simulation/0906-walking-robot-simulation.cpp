class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>st;
        for(auto &x:obstacles)
        {
            st.insert({x[0],x[1]});
        }

        vector<int>dr={0,1,0,-1,0};
        int d=0,x=0,y=0;
        int ans=0;
        for(auto &c:commands)
        {
            if(c == -1)
            {
                d=(d+1)%4;
            }
            else if(c==-2)
            {
                d=(d-1+4)%4;
            }
            else
            {
                while(c-- >0 && st.find({x+dr[d],y+dr[d+1]})==st.end())
                {
                    x+=dr[d];
                    y+=dr[d+1];
                }

                ans=max(ans,(x*x + y*y));
            }
        }
        return ans;
    }
};