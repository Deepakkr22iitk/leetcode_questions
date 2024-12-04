class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.length() > str1.length()) return false;
        int i = 0 , j = 0;
        while(i < str1.length() && j < str2.length()) {
            if(str1[i] == str2[j]) j++;
            else {
                if(str1[i] != 'z') str1[i]++;
                else str1[i] = 'a';
                if(str1[i] == str2[j]) j++;
            }
            i++;
        }
        if(j == str2.length()) return true;
        return false;
    }
};