class Solution {
public:
    string clearDigits(string s) {
//         int n=s.length();
//         while(1)
//         {
//             bool mila=false;
//             for(int i=0;i<n;i++)
//             {
//                 if(isdigit(s[i]))
//                 {
//                     mila=true;
                    
//                     for(int j=i-1;j>=0;j--)
//                     {
//                         if(!isdigit(s[j]))
//                         {
//                             s.erase(j,1);
//                             s.erase(i,1);
//                             break; 
//                         }
//                     }
//                     break;
//                 }
//             }
//             if(!mila) break;
//         }
//         return s;

        stack<char>st;
        for(int i=0;i<s.size();i++) 
        { 
            if(s[i]>='0'&&s[i]<='9') 
            { 
                if(st.size()>0) st.pop();
            } 
            else st.push(s[i]); 
        } 
        string answer; 
        while(!st.empty()) 
        { 
            char ch=st.top();
            st.pop();
            answer+=ch;
        } 
        reverse(answer.begin(),answer.end()); 
        return answer;
    }
};