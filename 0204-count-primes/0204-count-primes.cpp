class Solution {
public:
int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n / 2, true);
        int limit = sqrt(n - 1);
        for (int i = 3; i <= limit; i += 2) {
            if (isPrime[i / 2]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j / 2] = false;
                }
            }
        }
        int count = 1; 
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i / 2]) count++;
        }
        return count;
    }
};