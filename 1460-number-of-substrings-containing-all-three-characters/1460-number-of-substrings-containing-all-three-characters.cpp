class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int n=s.size();
        bool flag=false;
        map<char,int>temp;
        int i=0;
        int j=2;
        temp[s[0]]++;
        temp[s[1]]++;
        while(j<n)
        {
            if(temp.size()!=3) temp[s[j]]++;

            if(temp.size()==3)
            {
                if(flag==false)            // Only for one Time, I would have to consider the previous elements too 
                {
                    int prev=(i+1);
                    int end=(n-j);
                    ans+=(prev*end);
                    flag=true;
                }
                else      // After the first time I encountered all three characters, I can take up all of the further substrings starting from the particular 'j'th index
                {
                    ans+=(n-j);
                }
                temp[s[i]]--;
                if(temp[s[i]]==0)
                {
                    temp.erase(s[i]);
                    j++;
                }
                i++;
            }
            else j++;
        }
        return ans;
    }
};