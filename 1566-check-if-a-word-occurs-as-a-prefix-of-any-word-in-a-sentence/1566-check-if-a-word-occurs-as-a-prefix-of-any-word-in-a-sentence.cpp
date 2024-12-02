class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int m=searchWord.size();
        int i=0;
        int cnt=1;
        while(i<n)
        {
            int j=0;
            while(j<m && i<n && searchWord[j]==sentence[i])
            {
                i++;
                j++;
            }

            if(j==m) return cnt;

            while(i<n && sentence[i]!=' ') i++;
            i++;

            cnt++;
        }
        return -1;
    }
};