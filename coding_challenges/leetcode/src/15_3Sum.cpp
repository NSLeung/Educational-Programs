/* 
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //try to brute force first (doesn't handle duplicates)
        // for (int i = 0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size();j++){
        //         for(int k = j+1; k < nums.size(); k++){
        //             if(nums[i] + nums[j] + nums[k] == 0){
        //                 vector<int> v = {nums[i], nums[j], nums[k]};
        //                 res.push_back(v);
        //             }
        //         }
        //     }
        // }
        // //speed up search to O(n^2 * logn)
        // return res;

        //2 - pointer method
        std::vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }

        std::size_t n_size = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n_size; ++i) {
            // all numbers from now on will be greater than 0, no point in continuing
            if (nums[i] > 0) break;

            // we have seen this number & combo before; skip (handles duplicates)
            if (i > 0 and nums[i] == nums[i-1]) continue;

            int left = i+1, right = n_size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    int last_left = nums[left], last_right = nums[right];
                    // we have seen this number & combo before; skip
                    while (left < right && nums[left] == last_left) ++left;
                    while (left < right && nums[right] == last_right) --right;
                }
            }

        }
        return result;
    }
};

int main(){
	Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.threeSum(nums);
    for(auto it = result.begin(); it != result.end(); it++){
        for(auto it2 = it->begin(); it2 != it->end(); it2++){
            cout << *it2 << ", ";
        }
        cout << "\n" << endl;
    }
	return 0;
}