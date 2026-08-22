class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        
        for (int temp = n; temp > 0; temp /= 10) {
            int digit = temp % 10;
            sum += digit;
            prod *= digit;
        }
        
        return n % (sum + prod) == 0;
    }
};