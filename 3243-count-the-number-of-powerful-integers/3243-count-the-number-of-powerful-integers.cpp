int64_t memoization[17][2];

class Solution {
public:
    // Using Digit DP to count all the Powerful Integers till x
    long long countPowerfulIntegers(long long x, int limit, string suffix) {
        // Convert 'x' to a string representation
        string xStr = to_string(x);
        const int xSize = (int)xStr.size();
        
        // Initialize memoization array with -1 current_digits
        memset(memoization, -1, sizeof memoization);
        
        // Calculate the difference in lengths between 'x' and the suffix
        int indexDifference = xSize - (int)suffix.size();
        
        // If 'x' is shorter than the suffix, there are no powerful integers
        if (indexDifference < 0)
            return 0;
        
        // Define a recursive function to compute the count of powerful integers
        function<int64_t(int, int)> countRecursive = [&](int index, int tight) -> int64_t {
            if (index == xSize)
                return 1;
            
            // Retrieve the current_digit from memoization if previously calculated
            int64_t& answer = memoization[index][tight];
            if (answer != -1)
                return answer;
            
            answer = 0;
            if (index >= indexDifference) {
                int current_digit = suffix[index - indexDifference] - '0';
                if (current_digit <= limit) {
                    if (tight and current_digit <= xStr[index] - '0') {
                        answer += countRecursive(index + 1, current_digit == xStr[index] - '0');
                    } else if (!tight) {
                        answer += countRecursive(index + 1, 0);
                    }
                }
            } else if (tight) {
                int digit = xStr[index] - '0';
                for (int current_digit = 0; current_digit <= min(limit, digit); current_digit++) {
                    answer += countRecursive(index + 1, current_digit == digit);
                }
            } else {
                for (int current_digit = 0; current_digit <= min(limit, 9); current_digit++) {
                    answer += countRecursive(index + 1, 0);
                } 
            }
            
            return answer;
        };
        
        // Calculate the count of powerful integers in the range [0, x]
        return countRecursive(0, 1);
    }
    
    // Function to count powerful integers within a given range
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix) {
        // Calculate the count of powerful integers in the range [0, finish] and [0, start - 1]
        return countPowerfulIntegers(finish, limit, suffix) - countPowerfulIntegers(start - 1, limit, suffix);
    }
};