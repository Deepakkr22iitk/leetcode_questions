class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k) {
            string sb;
            int sum = 0;

            for(int i = 0; i < s.length(); i++) {
                sum += (s[i] - '0');

                if((i + 1) % k == 0) {
                    sb += to_string(sum);
                    sum = 0;
                }
            }

            if(s.length() % k != 0) {
                sb += to_string(sum);
            }

            s = sb;
        }

        return s;
    }
};