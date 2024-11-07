class Solution {
public:
    string convert(string s, int numRows) {
        // int n=numRows;
        // string ans="";
        // int first=2*(n-1);
        // for(int i=0;i<n;++i)
        // {
        //     int now=i;
        //     ans+=s[now];
        //     while(now<s.size())
        //     {
        //         int next=(now+first);
        //         if(next<s.size() && next!=now)
        //             now=next;
        //             ans+=s[now];
        //         }
        //         next=(now+((2*(n-1))-first));
        //         if(next<s.size() && next!=now)
        //         {
        //             now=next;
        //             ans+=s[now];
        //         }
        //         first-=2;
        //     }
        // }
        // return ans;

        if (numRows == 1) return s;  // Handle edge case where numRows is 1

        string ans = "";
        int n = numRows;
        int first = 2 * (n - 1);

        for (int i = 0; i < n; ++i) {
            int now = i;
            if (now < s.size()) {  // Ensure the first character of the row is valid
                ans += s[now];
            }

            int step1 = first - 2 * i;  // Step to the next character in the same row
            int step2 = 2 * i;          // Step for the zig-zag

            while (true) {
                if (step1 > 0) {
                    now += step1;       // Apply the first step
                    if (now >= s.size()) break;
                    ans += s[now];
                }

                if (step2 > 0) {
                    now += step2;       // Apply the second step
                    if (now >= s.size()) break;
                    ans += s[now];
                }
            }
        }

        return ans;
    }
};