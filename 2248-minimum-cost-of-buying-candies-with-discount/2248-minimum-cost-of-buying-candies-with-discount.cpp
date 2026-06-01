class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int sum = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            sum += cost[i];
            if (i + 1 < cost.size()) sum += cost[i + 1];
        }
        return sum;
    }
};