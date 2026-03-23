	class Solution {

	public:

	    int maxProductPath(vector<vector<int>>& grid) {

	        const int MOD = 1e9 + 7;

	        int m = grid.size(), n = grid[0].size();

	        vector<vector<long long>> max_prod(m, vector<long long>(n, 0));

	        vector<vector<long long>> min_prod(m, vector<long long>(n, 0));

	        max_prod[0][0] = min_prod[0][0] = grid[0][0];

	        for (int i = 0; i < m; ++i) {

	            for (int j = 0; j < n; ++j) {

	                if (i == 0 && j == 0) continue;

	                long long max_val = LLONG_MIN, min_val = LLONG_MAX;

	                if (i > 0) {

	                    max_val = max(max_val, max_prod[i-1][j]);

	                    min_val = min(min_val, min_prod[i-1][j]);

	                }

	                if (j > 0) {

	                    max_val = max(max_val, max_prod[i][j-1]);

	                    min_val = min(min_val, min_prod[i][j-1]);

	                }

	                if (grid[i][j] >= 0) {

	                    max_prod[i][j] = max_val * grid[i][j];

	                    min_prod[i][j] = min_val * grid[i][j];

	                } else {

	                    max_prod[i][j] = min_val * grid[i][j];

	                    min_prod[i][j] = max_val * grid[i][j];

	                }

	            }

	        }

	        long long result = max_prod[m-1][n-1];

	        return result >= 0 ? result % MOD : -1;

	    }

	};