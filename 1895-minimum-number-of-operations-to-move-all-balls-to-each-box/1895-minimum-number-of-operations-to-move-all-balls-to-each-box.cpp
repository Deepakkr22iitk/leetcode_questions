class Solution {
public:
    // here in this problem what I am trying to do is to maintain 2 varible which
    // takes care of number of balls before and after that index. 
    // and accordingly we are updating the steps for each index, let me elaborate 
    // little more once we calculated the total steps required for every ball 
    // to come to 0th index by running a loop from 1 to n-1, and also counting the  
    // number of balls present

    // and then we again run a loop and this time we are keeping our count for number 
    // of balls before that index and accordingly we are UPDATING our count for 
    // number of balls after that index. and all this will contribute to the 
    // steps/operation (line :- 36,37)
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n=boxes.size();
        int steps=0;
        int fromLast=0;
        for(int i=1;i<n;++i)
        {
            if(boxes[i]=='1') 
            {
                steps+=i;
                fromLast++;
            }
        }
        int tillNow=0;
        for(int i=0;i<n;++i)
        {
            if(boxes[i]=='1') 
            {
                tillNow++;
                if(i>0) fromLast--;
            }
            ans.push_back(steps);
            steps-=fromLast;
            steps+=tillNow;
        }
        return ans;
    }
};