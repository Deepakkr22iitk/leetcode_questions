class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        int right = 0, left = 0 , none = 0;
        for(int i = 0 ; i < moves.size() ; i++) {
            if(moves[i] == 'L') left++;
            else if(moves[i] == 'R') right++;
            else none++;
        }
        return abs(left-right) + none;
    }
};