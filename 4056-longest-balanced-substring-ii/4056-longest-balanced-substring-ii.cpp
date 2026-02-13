class Solution {
public:
    #define debug(x) cout<<#x<<" is; "<<x<<endl;
    int longestBalanced(string s) {
        int ans = 1;
        int n = s.length();
        if(n==1) return 1;

        int curr = 1;
        //only 1 type of characters
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                ans = max(ans,curr);
                curr = 1;
            }
        }
        ans = max(ans,curr);

        //for 2 characters
        //ignore c
        curr = 0;
        map<int,int> m1;//diff (a-b), ind
        int a = 0, b = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='c'){
                m1.clear();
                a = 0; b = 0; continue;
            }
            if(s[i]=='a') a++;
            else b++;
            if(a==b){
                ans = max(ans,a+b);//total length of substr=a+b
            }
            //kya a-b already hai??
            auto ptr = m1.find(a-b);
            if(ptr != m1.end()){
                int idx = ptr->second;
                ans = max(ans,i-idx);
            }else{
                m1[a-b] = i;
            }
        }
        m1.clear();
        //ignore b
        curr = 0;
        // map<int,int> m1;//diff ind
        a = 0; int c = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='b'){
                m1.clear();
                a = 0; c = 0; continue;
            }
            if(s[i]=='a') a++;
            else c++;
            if(a==c){
                ans = max(ans,a+c);
            }
            //kya a-c already hai??
            auto ptr = m1.find(a-c);
            if(ptr != m1.end()){
                int idx = ptr->second;
                ans = max(ans,i-idx);
            }else{
                m1[a-c] = i;
            }
        }

        //ignore a
        curr = 0;
        m1.clear();
        // map<int,int> m1;//diff ind
        b = 0, c = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                m1.clear();
                c = 0; b = 0; continue;
            }
            if(s[i]=='c') c++;
            else b++;
            if(c==b){
                ans = max(ans,c+b);
            }
            //kya b-c already hai??
            auto ptr = m1.find(b-c);
            if(ptr != m1.end()){
                int idx = ptr->second;
                ans = max(ans,i-idx);
            }else{
                m1[b-c] = i;
            }
        }
        // debug(ans)
        //for 3 characters

        map<vector<int>,int> mp;//a-b,b-c,c-a
        
        a = 0, b = 0, c = 0;
        if(s[0]=='a') a++;
        else if(s[0]=='b') b++;
        else c++;
        vector<int> tm;
        tm.push_back(a-b);//a-b
        tm.push_back(a-c);//a-c
        tm.push_back(b-c);//b-c
        mp[tm] = 0;
        
        for(int i=1; i<n; i++){
            if(s[i]=='a') a++;
            else if(s[i]=='b') b++;
            else c++;
            bool check = true;
            
            //base case check if all are equal??
            int var = max({a,b,c});
            if(a>0 && a != var){
                check = false;
            }
            if(b>0 && b != var){
                check = false;
            }
            if(c>0 && c != var){
                check = false;
            }
            
            if(check){
                ans = max(ans,i+1);
            }
            vector<int> tmp;
            tmp.push_back(a-b);//a-b
            tmp.push_back(a-c);//a-c
            tmp.push_back(b-c);//b-c
            auto ptr = mp.find(tmp);
            if(ptr != mp.end()){
                int idx = ptr->second;
                ans = max(ans,i-idx);
            }else{
                mp[tmp] = i;
            }
            
        }
        bool check = true;
        int var = max({a,b,c});
        if(a>0 && a != var){
            check = false;
        }
        if(b>0 && b != var){
            check = false;
        }
        if(c>0 && c != var){
            check = false;
        } 
        if(check){
            ans = n;
        }
        
        
        return ans;
    }
};