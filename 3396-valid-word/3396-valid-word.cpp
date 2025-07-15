class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return 0;
        // int i=0;
        // int ans=1;
        // while(i<n)
        // {
        //     if((word[i]>64 && word[i]<91) || (word[i]>96 && word[i]<123) || )
        // }
        
        int vow=0, con=0;
        int i=0;
        while(i<n)
        {
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u' || word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U') vow++;
            
            else if(word[i] >= '0' && word[i] <= '9') { }
            else if(word[i]=='@' || word[i]=='#' || word[i]=='$') return 0;
            else con++;
            i++;
        }
        if(vow>0 && con>0) return true;
        return false;
    }
};