class Solution {
public:
    int countOdds(int low, int high) {
        int diff=(high-low);
        return diff&1?(diff+1)/2:low&1?diff/2+1:diff/2;
    }
};