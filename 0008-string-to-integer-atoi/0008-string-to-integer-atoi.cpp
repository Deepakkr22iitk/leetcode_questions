class Solution {
public:
    int myAtoi(string s) {
        double ans = 0;
        int n = s.size();
        int idx=0;
        while(s[idx]==' '){
            idx++;
        }
        bool pos=s[idx]=='+';
        pos==true?idx++:idx;
        bool neg=s[idx]=='-';
        neg==true?idx++:idx;
        if(pos && neg) return ans;
        while(idx<n && s[idx]>='0' && s[idx]<='9')
        {
            ans*=10;
            ans+=(s[idx]-'0');
            idx++;
        }
        ans=neg?-ans:ans;
        ans=(ans>INT_MAX)?INT_MAX:ans;
        ans=(ans<INT_MIN)?INT_MIN:ans;
        return int(ans);
    }
};