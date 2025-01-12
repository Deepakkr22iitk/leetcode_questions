class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2==1) return false;

        int right_open=0;   // count of '('
        int free=0;
        for(int i=0;i<n;++i)
        {
            int val=locked[i]-'0';
            if(val==0) free++;
            else if(s[i]=='(') right_open++;
            else if(s[i]==')') 
            {
                if(right_open>0) right_open--;
                else if(free>0) free--;
                else return false;
            }
        }
        int balance=0;
        // Match remaining open brackets with free cnt
        for(int i=(n-1);i>=0;--i)
        {
            if(locked[i]=='0')
            {
                balance--;
                free--;
            }
            else if(s[i]=='(')
            {
                balance++;
                right_open--;
            }
            else if(s[i]==')')
            {
                balance--;
            }

            if(balance>0) return false;

            if(free==0 && right_open==0) break;
        }

        if(right_open>0) return false;

        return true;
    }
};