class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<char> st;

        for(int i=0;i<n;i++)
        {
            char curr=s[i];

            if(st.empty())
            {
                st.push(curr);
            }
            else
            {
                if(curr=='B' && st.top()=='A')
                {
                    st.pop();
                }
                else if(curr=='D' && st.top()=='C')
                {
                    st.pop();
                }
                else st.push(curr);
            }
        }

        return st.size();
    }
};