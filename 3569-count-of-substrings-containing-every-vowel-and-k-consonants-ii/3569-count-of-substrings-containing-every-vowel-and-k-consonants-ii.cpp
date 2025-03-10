class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    long long countOfSubstrings(string word, int k) {
        int len=word.size();
        map<char,int>freq;
        int cnt=0;
        long long ans=0;

        // Build the index of next consonant position
        vector<int>next_ind(len);
        int last_consonant=len;
        for(int i=len-1;i>=0;--i)
        {
            next_ind[i]=last_consonant;
            if(!isVowel(word[i])) last_consonant=i;
        }

        int i=0,j=0;
        while(j<len)
        {
            if(isVowel(word[j])) freq[word[j]]++;
            else cnt++;

            while(i<j && cnt>k)
            {
                if(isVowel(word[i]))
                {
                    freq[word[i]]--;
                    if(freq[word[i]]==0) freq.erase(word[i]);
                }
                else cnt--;

                i++;
            }

            while(i<j && freq.size()==5 && cnt==k)
            {
                int nxt=next_ind[j];

                ans+=(nxt-j);
                if(isVowel(word[i]))
                {
                    freq[word[i]]--;
                    if(freq[word[i]]==0) freq.erase(word[i]);
                }
                else cnt--;

                i++;
            }
            j++;
        }
        return ans;
    }
};