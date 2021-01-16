#include <vector>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //use set to keep track of unique elements?
        int num_duplicates = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++num_duplicates;
            } else {
                //shuffle in unique element
                nums[i - num_duplicates] = nums[i];
            }
        }
        //delete num duplicates from end in place
        nums.erase(nums.end() - num_duplicates, nums.end());
        return nums.size();
    }
};


int main(){
	Solution sol;
    vector<int> nums = {1, 2, 3, 3};
    cout <<  sol.removeDuplicates(nums) << endl;
    for(auto it = nums.begin(); it != nums.end(); it++){
        // for(auto it2 = it->begin(); it2 != it->end(); it2++){
        //     cout << *it2;
        // }
        cout << *it << " " << endl;
    }
	return 0;
}