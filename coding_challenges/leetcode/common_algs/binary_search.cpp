// #include <vector>
// #include <iostream>
// using namespace std;

#include "util.h"

//assumptions: array is sorted
//iterative, returns index of found target
int Algorithms::binary_search_it(vector<int> nums, int target, int left, int right) {
    while(left <= right) {
        //compute mid
        int mid = left + (right - left)/2;

        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target) {
            //ignore left half
            left = mid + 1;
        }
        else{
            //ignore right half
            right = mid - 1;
        }
    }
    return -1;
}


int Algorithms::binary_search_r(vector<int> nums, int target, int left, int right){
    if(right >= left) {
        int mid = left + (right - left) / 2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid] < target){
            return binary_search_r(nums, target, mid+1, right);
        }
        return binary_search_r(nums,target, left, mid-1);

    }
    return -1;
    

}

int main(){
    Algorithms a;
    vector<int> nums = { 2, 3, 4, 10, 40 };
    cout << a.binary_search_it(nums, 10, 0, nums.size()-1) << endl;
    return 0;
}