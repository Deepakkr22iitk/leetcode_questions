class Solution {
public:
    int maximumSwap(int num) {
        int temp = num, base = 1, high = 1, low = 1, lowBase = 1, highBase = 1, maxDigit = 0, maxBase = 1;
        while(temp > 0)
        {
            int current = temp % 10;
            if(current<maxDigit)
            {
                low = maxDigit;
                lowBase = maxBase;
                high = current;
                highBase = base;
            }
            if(current > maxDigit)
            {
                maxDigit = current;
                maxBase = base;
            }
            base *= 10;
            temp /= 10;
        }
        return num + (low-high)*(highBase-lowBase);
    }
};