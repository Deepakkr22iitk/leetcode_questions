class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagSq = -1;  // stores max diagonal squared
        int maxArea = -1;    // stores max area for that diagonal

        for (auto &rect : dimensions) {
            int a = rect[0], b = rect[1];
            int diagSq = a * a + b * b;
            int area = a * b;

            if (diagSq > maxDiagSq) {
                maxDiagSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagSq) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};