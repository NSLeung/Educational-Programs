#include "util.h"

int Solution::numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int count = 0;
        int n = nums.size();
        int start = 0, end = 0;
        int product = 1;
        while(end < n){
            product *= nums[end];
            while( start < n and product >= k){	    	//If  product is greater than K value then divide the value at 
                product /= nums[start];                 //the START index from the "nums" array and then increment the start value 
                start++;
            }
            if(product < k) count += end - start + 1;	// If product is less than K value then increase COUNT value

            end++;
        }
        return count;

}

int main() {

    return 0;
}