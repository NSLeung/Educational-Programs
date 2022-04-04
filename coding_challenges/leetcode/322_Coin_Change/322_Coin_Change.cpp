#include <vector>
#include <iostream>
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        //DP problem?
        //subproblem - smallest number of coins to make amount 0
        //DP[n] - number of coins to make n amount, fill from 0 to n
        // int *dp = new int[amount + 1];
        std::vector<int> dp(amount + 1,amount+1);

        //bottom up approach
        dp[0] = 0;
        for(int i = 0; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++){
                //simulate taking coins
                if(coins[j] <= i) {
                    printf("taking this coin: dp[%d] = %d\n", i, dp[i]);
                    //utilize dp array to look for previous solved subproblem, 1 + means use the coin
                    dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
                }

            }
            printf("dp[%d] = %d\n", i, dp[i]);
        }
        return dp[amount] > amount ? -1 : dp[amount];

    }
};

int main(){
	Solution sol;
	std::vector<int> coins = {1, 2, 5};
	std::cout << sol.coinChange(coins, 11) << std::endl;
	return 0;
}