class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> batches;
        int n=s.size();
        int count=0;
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                // cout<<"Incremented at "<<i<<endl;
                count++;
            }
            
            else if(count>0){
                // cout<<"Pushed at "<<i<<endl;
                    batches.push_back(count);
                    count=0;
                    ones++;
                }
                else{
                    ones++;
                }
            
        }
        if(count>0){
            // cout<<"0 at last "<<endl;
            batches.push_back(count);
            count=0;
        }
        if(batches.size()<2){
            // cout<<"Hitted here"<<endl;
            return ones;
        }
        // for(int c:batches){
        //     cout<<c<<endl;
        // }
        int maxi=0;
       
        for(int c=0;c<batches.size()-1;c++){
            maxi=max(maxi,batches[c]+batches[c+1]);
        }
        return ones+maxi;
        return 0;
    }
};