class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int count = 0;
        int i = 0, ans = 0;
        int first = 0, second = -1;
        set<int> now;

        while (i < n) {
            if (now.size() == 0) {
                first = i;
                count = 1;
                now.insert(fruits[i]);
            } else if (now.size() == 1) {
                if (now.find(fruits[i]) == now.end()) {
                    second = i;
                    now.insert(fruits[i]);
                    count++;
                } else {
                    count++;
                    if (fruits[i] != fruits[first]) first = i;
                }
            } else {
                if (now.find(fruits[i]) == now.end()) {
                    ans = max(ans, count);
                    // find the last contiguous segment of one fruit type
                    int j = i - 1;
                    while (j > 0 && fruits[j] == fruits[j - 1]) j--;
                    // keep that segment
                    first = j;
                    count = i - j;
                    now.clear();
                    now.insert(fruits[i]);
                    now.insert(fruits[j]);
                    second = i;
                    count++;
                } else {
                    count++;
                    if (fruits[i] == fruits[first]) first = i;
                    else second = i;
                }
            }
            ans = max(ans, count);
            i++;
        }

        return ans;
    }
};
