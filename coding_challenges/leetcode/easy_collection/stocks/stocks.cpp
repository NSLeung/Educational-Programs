#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
//basically buy low sell high
//think causally, can only search / pan right, seems like a DP combination question

//return profit, tricky part is that you can buy and sell multiple times
    int maxProfit(vector<int>& prices) {
        
        //subproblem: dp holds best profit up to that day
        // vector<int> dp(prices.size()+1, prices.size()+1);
        // dp[0] = prices[0];
        // for(int i = 1; i < prices.size();i++){
        //     dp[i] =  max(prices[i] - dp[i-1]);
        // }

        //single pass, capitalizes on finding all possible peaks and valleys
        // O(n) runtime, O(1) space
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            //keep advancing to find the first valley
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};

int main(){

    return 0;
}