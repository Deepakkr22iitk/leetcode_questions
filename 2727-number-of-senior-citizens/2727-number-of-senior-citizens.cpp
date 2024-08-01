class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            string temp="";
            temp+=details[i][11];
            temp+=details[i][12];
            int num=stoi(temp);
            if(num>60) ans++;
        }
        return ans;
    }
};