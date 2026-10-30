class Solution {
public:
    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Take advantage of symmetry: C(n, r) == C(n, n - r)

        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= (n - r + i);
            result /= i;
        }
        return result;
    }

    int numTrees(int n) {
        return nCr(2*n,n) - nCr(2*n,n-1);
    }
};