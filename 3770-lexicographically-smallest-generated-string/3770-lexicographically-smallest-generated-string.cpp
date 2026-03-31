class Solution {
public:
    typedef int ll ; 
    string generateString(string str1, string str2) {
       string ans = "" ; 
       for(ll i = 0 ; i<str1.size() ; i++){
        if(str1[i] == 'T'){
            if(i == 0){
               ans = ans + str2 ; 
            }
            else {
               
              
                ll tp = 0 ; 
               
                for(ll j = i ; j<min(str2.size()+i , ans.size()) ; j++){
                    if(ans[j] == str2[j-i]){
                       tp ++ ; 
                       
                    }
                    else {
                      
                        return "" ;
                    }
                }

                if(tp != str2.size()){
                    for(ll j = tp ; j<str2.size() ; j++){
                         ans = ans + str2[j] ; 
                    }
                }
               
            }
        }
        else {
      
            if(i == 0){
                ans = ans + '?' ;
            }
            else {
                if(ans.size() < (i+1)){
                if(str1[i-1] == 'F' ){
                    ans = ans + '?' ; 
                }

                if((str2.size() == 1 && str1[i-1]!='F')){
                    ans = ans + '?' ;
                }
                }
            }
        
        }
       }
       
       ll y = str1.size() + str2.size() -1;
    
       ll k = y - ans.size() ; 
       for(ll i = 0 ; i<k ; i++){
       
              ans = ans + '?' ; 
        
       }
    
       
      for(ll i = 0 ; i < ans.size() ; i++){
    if(ans[i] == '?'){
        ans[i] = 'a';  

      
        bool bad = false;

        for(ll start = max(0, i - (ll)str2.size() + 1);
            start <= min(i, (ll)str1.size() - 1);
            start++){

            if(str1[start] == 'F'){
                bool same = true;

                for(ll j = 0; j < str2.size(); j++){
                    if(ans[start + j] != str2[j]){
                        same = false;
                        break;
                    }
                }

                if(same){
                    bad = true;
                    break;
                }
            }
        }

        if(bad) ans[i] = 'b';
    }
}
       
       for(ll i = 0 ; i<str1.size() ; i++){
        if(str1[i] == 'T'){
            bool p = true ; 
            for(ll j = 0 ; j<str2.size() ; j++){
      {         if(ans[j+i] != str2[j]){
                   p = false ; 
                   return "" ; 
               } 
            }
            
        }
        }
        else {
        bool p = true ; 
            for(ll j = 0 ; j<str2.size() ; j++){
      {         if(ans[j+i] != str2[j]){
                   p = false ; 
                  
               } 
            }
            
        }

        if(p){
            return "" ; 
        }

        

        }
       }

       return ans; 
       
    }
};