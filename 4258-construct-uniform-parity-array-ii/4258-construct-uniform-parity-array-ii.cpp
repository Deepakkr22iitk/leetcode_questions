// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//         int n=nums1.size();
//         int oddCnt=0;
//         int mnOdd=1e9+1;
//         int mnEven=1e9;
//         for(int i=0;i<n;++i)
//         {
//             if(nums1[i]%2==1) 
//             {
//                 oddCnt++;
//                 mnOdd=min(mnOdd,nums1[i]);
//             }
//             else mnEven=min(mnEven,nums1[i]);
//         }
//         // if(oddCnt==n || oddCnt==0) return true;

//         // int flag=1;
//         // // if we try for all odd
//         // for(int i=0;i<n;++i)
//         // {
//         //     if(nums1[i]%2==1) continue;
//         //     else if(mnOdd>nums1[i]) flag=0;
//         // }

//         // // we are not trying for all even
//         // // Because this is not possible, at this point, we are looking for an array 
//         // // consisting of both(odd & even) so in this [how will we change the mnOdd?]
        
//         // return flag==1;

//         if(oddCnt!=0 && oddCnt!=n && mnEven<mnOdd) return false;
//         return true;
//     }
// };

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // int n=nums1.size();
        // int mnEven=1e9+2,mnOdd=1e9+1;
        // for(int i=0; i<n; i++){
        //    if(nums1[i]%2!=0)
        //    {
            
        //    }
        //    else
        //    {
            
        //    }
        // }
        // if()
        // {
        //     return true;
        // }
        // else
        // {
        //     if(mnEven>mnOdd)
        //     {
        //         return true;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }
        // return false;

        int n=nums1.size();
        vector<int>O(n,INT_MAX);
        vector<int>E(n,INT_MAX);
        int a=0;
        int b =0;
        for(int i=0; i<n; i++){
           if(nums1[i]%2!=0){
            O[a]=nums1[i];
            a++;
           }else{
            E[b]=nums1[i];
            b++;
           }
        }
        sort(nums1.begin(),nums1.end());//1,4,7
        sort(O.begin(),O.end());//
        sort(E.begin(),E.end());
        if(a==n || a==0){
            return true;
        }else{
            if(E[0]>O[0]){
                return true;
                }
                else{
                return false;
            }
        }
        // return false;
    }
};