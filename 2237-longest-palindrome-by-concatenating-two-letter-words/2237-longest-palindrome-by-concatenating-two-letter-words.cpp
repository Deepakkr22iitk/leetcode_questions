class Solution {
public:
    // Handle all the pairs things first and then check for the middle most element 
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        map<string,int>rk;
        for(int i=0;i<n;++i) rk[words[i]]++;
        
        int ans=0;
        for(auto i=rk.begin();i!=rk.end();++i)
        {
            string first=i->first;
            string temp=first;
            reverse(temp.begin(),temp.end());
            if(first!=temp)
            {
                int l=min(rk[first],rk[temp]);
                ans+=2*l;
                rk[first]-=l;
                rk[temp]-=l;
            }
            else if(first==temp)
            {
                int l=rk[first]/2;
                ans+=2*l;
                rk[first]-=(2*l);
            }
        }
        
        for(int i=0;i<n;++i)
        {
            string curr=words[i];
            if(curr[0]==curr[1] && rk[curr]==1) // All the pairs thing had already been sorted. Now, we are looking if any one can be placed at the middle most or not.
            {
                ans++;
                break;
            }    
        }
        return 2*ans;
    }
};