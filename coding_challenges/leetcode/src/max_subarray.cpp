#include "util.h"


int Solution::maxSubArray(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
    int max_sum = nums[nums.size()-1];
    vector<int> v(nums.size(),0); //holds largest continguous sum at index
    v[nums.size()-1] = nums[nums.size()-1];
    for(int i = nums.size()-2;i>=0;i--){
        v[i] = max(nums[i] + v[i+1], nums[i]);
        max_sum = max(max_sum, v[i]);
    }
    // Solution s;
    // s.printVector(v);
    // cout << max_sum << endl;
    return max_sum;
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(v) << endl;
}