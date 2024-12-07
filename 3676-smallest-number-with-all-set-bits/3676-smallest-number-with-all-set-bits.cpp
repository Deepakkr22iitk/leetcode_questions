class Solution {
public:
    int smallestNumber(int n) {
        int num=1,least=0;
        while(n/num!=0) 
        {
            num*=2;
            least++;
        }
        return pow(2,least)-1;
    }
};