class Solution {
public:
   set<int>st;
   int solve(string no,vector<bool>used,vector<int>&digits){
      if(no.size()==3){
           if(no[0]=='0')return 0;
           int ns=stoi(no);
           if(ns%2==0 && st.find(ns)==st.end()){
            st.insert(ns);
            return 1;
           }
           return 0;
      }
      int ans=0;
      for(int i=0;i<digits.size();i++){
        if(used[i]==false){
            used[i]=true;
            no+=to_string(digits[i]);
            ans+=solve(no,used,digits);
            no.pop_back();
            used[i]=false;
        }
      }
      return ans;
   }
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<bool>used(n,false);
       return solve("",used,digits); 
    }
};