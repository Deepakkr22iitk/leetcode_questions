// class Solution {
// public:
//     string fractionToDecimal(int numerator, int denominator) {
//         string ans="";
//         int flag=0;
//         ans+=to_string(numerator/denominator);
//         int rem=numerator%denominator;
//         if(rem)
//         {
//             ans+='.';
//             flag=1;
//             rem*=10;
//         }
//         while(flag)
//         {
//             if(rem==0) break;
//             ans+=to_string(rem);
//             rem%=denominator;
//             rem*=10;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string ans;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) ans += "-";

        long num = labs(numerator);
        long den = labs(denominator);

        // Integer part
        ans += to_string(num / den);
        long rem = num % den;
        if (rem == 0) return ans;

        ans += ".";
        unordered_map<long, int> mp; // remainder -> position in string

        while (rem) {
            if (mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }
            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }
        return ans;
    }
};
