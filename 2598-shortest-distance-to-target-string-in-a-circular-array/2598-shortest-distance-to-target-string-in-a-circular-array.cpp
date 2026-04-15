class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int rightDist = (i - startIndex + n) % n;
                int leftDist  = (startIndex - i + n) % n;
                minDistance = min(minDistance, min(rightDist, leftDist));
            }
        }

        return minDistance == INT_MAX ? -1 : minDistance;
    }
};