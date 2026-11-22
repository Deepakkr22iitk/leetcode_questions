class Solution {
public:
    bool checkString(string s) {
        int a=s.size()-1;
        int b=0;
        while(a>=0 && s[a]=='b') a--;
        while(b<s.size() && s[b]=='a') b++;

        return a<b;
    }
};