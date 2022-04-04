#include "util.h"
/*
 find the number of index triplets i, j, k with 0 <= i < j < k < n 
 that satisfy the condition nums[i] + nums[j] + nums[k] < target
*/
int threeSumSmaller(vector<int> nums, int target) {

    //use similar 2-pointer method
    int result = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int j = i+1;    //left pointer
        int k = nums.size() - 1; //right pointer

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < target){
                result += (k-j);
                j++;
            }
            else
                k--;
        }

    }
    return result;
}

