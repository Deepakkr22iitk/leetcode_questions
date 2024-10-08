class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int ans=0,count=0;
        int start=0,end=n-1;
        while(s[end]!='[') end--;
        while(start<end)
        {
            if(s[start]=='[') count++;
            else count--;

            if(count<0)
            {
                ans++;
                count+=2;
                swap(s[start],s[end]);
                while(end>start && s[end]!='[') end--;
            }
            start++;
        }
        return ans;
    }
};