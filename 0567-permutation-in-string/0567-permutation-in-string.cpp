class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        if(n>m) return false;

        map<char,int>first;
        for(int i=0;i<n;++i) first[s1[i]]++;

        int i=0,j=0;
        map<char,int>temp;
        while(j<m)
        {
            temp[s2[j]]++;
            
            if((j-i+1)==n)
            {
                if(temp==first) return true;

                else
                {
                    temp[s2[i]]--;
                    if(temp[s2[i]]==0) temp.erase(s2[i]);
                    i++;
                }
            }
            j++;
        }
        return false;
    }
};