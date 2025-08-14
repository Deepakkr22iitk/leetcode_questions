class Solution {
public:
    std::string largestGoodInteger(string num) {
        char com='0';
        int start = -1;
        for (int i = 0; i < num.length() - 2; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if (com <= num[i]) {
                    start = i;
                    com = num[i];
                }
            }
        }
        if(com && start!=-1)
            return num.substr(start, 3);
        return "";
    }
};