class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n1=words1.size(),n2=words2.size();
        vector<string>ans;
        vector<int>words2_freq(26);
        for(int i=0;i<n2;++i)
        {
            string curr=words2[i];
            vector<int>temp(26);
            int curr_len=curr.size();
            for(int j=0;j<curr_len;++j) temp[curr[j]-'a']++;

            for(int j=0;j<26;++j) words2_freq[j]=max(words2_freq[j],temp[j]);
        }

        for(int i=0;i<n1;++i)
        {
            string curr=words1[i];
            int curr_len=curr.size();
            vector<int>temp(26);
            for(int j=0;j<curr_len;++j) temp[curr[j]-'a']++;

            bool flag=true;
            for(int j=0;j<26;++j)
            {
                if(words2_freq[j]>temp[j]) 
                {
                    flag=false;
                    break;
                }
            } 
            if(flag) ans.push_back(curr);
        }
        return ans;
    }
};