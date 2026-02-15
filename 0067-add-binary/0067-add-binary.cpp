class Solution {
public:
    string addBinary(string a, string b) {
        char value;
        int sum = 0;
        int carry = 0;
        string answer = "";
        int i = a.size()-1;
        int j = b.size()-1;

        while(i>=0 or j>=0)
        {
            sum = carry;
            if(i>=0) sum = sum + a[i] - 48;
            if(j>=0) sum = sum + b[j] - 48;
            value = (sum%2) + 48;
            answer = answer + value;
            carry = sum / 2;
            i--;
            j--;
        }    
        value = carry + 48;
        if(carry) answer = answer + value;

        reverse(answer.begin(), answer.end());
        return answer;
    }
};