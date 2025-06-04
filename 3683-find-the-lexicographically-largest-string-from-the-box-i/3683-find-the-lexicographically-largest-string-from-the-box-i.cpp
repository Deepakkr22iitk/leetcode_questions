class Solution {
public:
    // Idea is get the highest value char and try to get the maxm substring
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n=word.size();
        char c=word[0];
        for(auto &x:word) c=max(c,x);

        string ans="";
        ans+=c;
        for(int i=0;i<n;++i)
        {
            if(word[i]==c)
            {
                int rem_len=(n-i);
                int req=numFriends-i; //Here 'i' number of prev characters can be assigned to each friend and then we require (numFriends-i-1) from the rem_len in front

                if(req>=1) rem_len-=(req-1);
                ans=max(ans,word.substr(i,rem_len));
            }
        }
        return ans;
    }
};