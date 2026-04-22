class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string>ans;
        int l=q[0].size();
        for(int i=0;i<q.size();i++){
            for(int j=0;j<d.size();j++){
                int c=0;
                for(int k=0;k<l;k++){
                    if(q[i][k]!=d[j][k])c++;
                }
                if(c<=2){
                    ans.push_back(q[i]);
                    // avoid duplicates
                    break;
                }
            }
        }return ans;
    }
};