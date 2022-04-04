#include "util.h"
/* helper binary search returns index of found target, -1 if not */
// int binary_search_it(vector<int> nums, int target, int left, int right) {
//     while(left <= right) {
//         //compute mid
//         int mid = left + (right - left)/2;

//         if(nums[mid] == target)
//             return mid;
//         if(nums[mid] < target) {
//             //ignore left half
//             left = mid + 1;
//         }
//         else{
//             //ignore right half
//             right = mid - 1;
//         }
//     }
//     return -1;
// }

/* unsorted */
vector<int> Solution::twoSum(vector<int>& nums, int target) {
    //runtime O(nlogn)? -> this assumes sorted array, O(n^2 if not)
    //runtime O(nlogn) if sort first
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++) {
        int toSearch = target - nums[i];
        unordered_map<int, int>::iterator find = m.find(toSearch);
        if(find != m.end())
            return {find->first, find->second};
        m[nums[i]] = i;
        
    }

}

