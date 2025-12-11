class Solution {
public:

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        n ++;
        vector<int> leftMostBuildingOnY(n, n+1);
        vector<int> rightMostBuildingOnY(n, -1);
        vector<int> lowestBuildingOnX(n, n+1);
        vector<int> highestBuildingOnX(n, 0);

        int res = 0;

        for(auto building: buildings) {
            int x = building[0];
            int y = building[1];

            leftMostBuildingOnY[y] = min(x, leftMostBuildingOnY[y]);
            rightMostBuildingOnY[y] = max(x, rightMostBuildingOnY[y]);

            lowestBuildingOnX[x] = min(y, lowestBuildingOnX[x]);
            highestBuildingOnX[x] = max(y, highestBuildingOnX[x]);
        }

        for(auto building: buildings) {
            int x = building[0];
            int y = building[1];

            if (y > lowestBuildingOnX[x] && y < highestBuildingOnX[x] 
            && x > leftMostBuildingOnY[y] && x < rightMostBuildingOnY[y]) {
                res ++;
            }
        }

        return res;
    }
};