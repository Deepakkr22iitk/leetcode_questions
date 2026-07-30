class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alph(26,0);
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            alph[word[i]-'a']++;
        }
        vector<int> v;
        for(int i=0;i<26;i++)
        {
            if(alph[i]>0) v.push_back(alph[i]);
        }
        sort(v.begin(),v.end());
        int ans=0;
        int times=1;
        for(int i=v.size()-1;i>=0;--i)
        {
            int j=i;
            while(j>=0 && j>i-8)
            {
                ans+=(times*v[j]);
                j--;
            }
            times++;
            i=j+1;
        }
        return ans;
    }
};