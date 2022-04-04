#include "util.h"

int Solution::maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int sz;
    //stores max length at top corner
    vector<vector<int>> dp(m, vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';  //keep the value (but store as an int)
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                //keep track of max sz seen so far
                sz = max(dp[i][j], sz);
        }
    }
    return sz * sz;
}

int main() {
// std::vector<std::vector<int> > fog { { 1, 1, 1 },
//                                     { 2, 2, 2 } };
    // vector<vector<char>> m {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};
    Solution s;
    // cout << s.maximalSquare(m) << endl;
    return 0;
}