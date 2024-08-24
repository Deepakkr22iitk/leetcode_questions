class Solution {
public:
    long long otherhalf(long long left, bool is_even_len)
    {
        long long res=left;
        if(is_even_len==false) left=left/10;  // In case of odd length, we'll reverse after the middle element 

        while(left)
        {
            long long rem=left%10;
            res=res*10 + rem;
            left/=10;
        }
        return res;
    }
    string nearestPalindromic(string n) {
        int len=n.size();
        int sz=len/2;
        bool even_len=false;
        if(len%2==0) 
        {
            sz--;
            even_len=true;
        }
        long long firstHalf=stoll(n.substr(0,sz+1));   
        vector<long long> ans;
        ans.push_back(otherhalf(firstHalf, even_len));  // Replicating the first half
        ans.push_back(otherhalf(firstHalf+1,even_len));  // Cases like: 139 --> 141
        ans.push_back(otherhalf(firstHalf-1,even_len));  // Cases like: 990 --> 989

        ans.push_back((long)pow(10,len-1)-1);  // To handle cases like 99, 999, 9999
        ans.push_back((long)pow(10,len) + 1);  // To handle the cases like 101, 1001, 10001

        long long diff=1e18;
        long long res=0;
        long long orig_num=stoll(n); 

        for(int i=0;i<5;++i)
        {
            long long val=ans[i];
            if(val==orig_num) continue;
            long long curr_diff=abs(orig_num-val);
            if(curr_diff<diff)
            {
                diff=curr_diff;
                res=val;
            }
            else if(curr_diff==diff)
            {
                res=min(res,val);
            }
        }
        return to_string(res);
    }
};