#include "util.h"

int Solution::lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(),0); //holds subproblem : longest increasing subsequence starting at index i
    int ret=0;
    for(int j = nums.size()-1; j >= 0; j--){
        dp[j] = 1;
        for(int i = j+1; i < nums.size(); i++) {
            if(nums[j] < nums[i]){
                //add 1 to represent "adding" to the sequence / confirming it is increasing
                dp[j] = max(dp[j], 1 + dp[i]);
            }
        }
        ret = max(ret, dp[j]);
    }
    Solution s;
    s.printVector(dp);
    return ret;
}

int main() {
    vector<int> v = {6,3,5,2,7,8,1};
    Solution s;
    cout << s.lengthOfLIS(v) << endl;
}