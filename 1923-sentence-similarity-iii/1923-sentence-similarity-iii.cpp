class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1==sentence2) return true;

        stringstream ss1(sentence1), ss2(sentence2);   //  |
        string word;                                   //  |
        vector<string>s_words1, s_words2;              //  | This thing creates each of the word in a space separated string 
        while(ss1>>word) s_words1.push_back(word);     //  |
        while(ss2>>word) s_words2.push_back(word);     //  |

        int len1=s_words1.size();
        int len2=s_words2.size();
        if(len1 > len2) 
        {
            s_words1.swap(s_words2); // Always assuming size(sentence1) < size(sentence2)
            swap(len1,len2);
        }
        int start=0, end1=len1-1, end2=len2-1;

        //Maximum word matching from start
        while(start<len1 && s_words1[start]==s_words2[start]) start++;

        // Maximum word matching from end side
        while(end1>=0 && s_words1[end1]==s_words2[end2])
        {
            end1--;
            end2--;
        }

        return (end1<start);  // Then only similarity is possible
    }
};