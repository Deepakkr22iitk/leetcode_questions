class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;++i)
        {
            string temp=words[i];
            int o_len=temp.size();
            bool flag=false;
            for(int j=0;j<n;++j)
            {
                if(j==i) continue;

                string curr=words[j];
                int len=curr.size();
                for(int k=0;k<=(len-o_len);++k)
                {
                    int ind=0;
                    int l=k;
                    while(ind<o_len && curr[l]==temp[ind])
                    {
                        ind++;
                        l++;
                    }
                
                    if(ind==o_len) 
                    {
                        ans.push_back(temp);
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
        return ans;
    }
};