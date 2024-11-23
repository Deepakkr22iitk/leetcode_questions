class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();

        vector<vector<char>>res(m,vector<char>(n));
        for(int i=0;i<n;++i)
        {
            int empty=m-1;
            for(int j=m-1;j>=0;--j)
            {
                if(box[i][j]=='*') empty=j-1; //If the current cell contains an obstacle. so, the next available position is (j-1)

                if(box[i][j]=='#')
                {
                    box[i][j]='.';
                    box[i][empty]='#';
                    --empty;
                }
            }    
        }

        for(int i=0;i<n;++i)
        {
            for(int j=m-1;j>=0;--j)
            {
                res[j][n-i-1]=box[i][j];
            }
        }
        return res;
    }
};