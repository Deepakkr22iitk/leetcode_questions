class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        
        // Remove blanks and ensure relative order matches
        while (i < n || j < n) {
            // Skip blanks in start and target
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            
            // If one reaches the end but the other doesn't
            if (i == n || j == n) return i == n && j == n;
            
            // If the characters differ
            if (start[i] != target[j]) return false;

            // Check movement constraints
            if (start[i] == 'L' && i < j) return false; // 'L' cannot move right
            if (start[i] == 'R' && i > j) return false; // 'R' cannot move left

            i++;
            j++;
        }
        
        return true;
    }
};