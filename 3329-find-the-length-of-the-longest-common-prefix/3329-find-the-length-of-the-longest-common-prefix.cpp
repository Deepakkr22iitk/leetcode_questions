class Solution {
public:
    // Function to get all prefixes of a number as strings
    vector<string> getPrefixes(int num) {
        string str = to_string(num);
        vector<string> prefixes;
        
        for (int i = 1; i <= str.size(); ++i) {
            prefixes.push_back(str.substr(0, i));
        }
        return prefixes;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixSet;
        int longestPrefixLength = 0;

        // Store all prefixes from arr1 in the hash set
        for (int num : arr1) {
            vector<string> prefixes = getPrefixes(num);
            for (const string& prefix : prefixes) {
                prefixSet.insert(prefix);
            }
        }

        // Compare prefixes from arr2 with those in the hash set
        for (int num : arr2) {
            vector<string> prefixes = getPrefixes(num);
            for (const string& prefix : prefixes) {
                if (prefixSet.find(prefix) != prefixSet.end()) {
                    longestPrefixLength = max(longestPrefixLength, (int)prefix.size());
                }
            }
        }

        return longestPrefixLength;
    }
};