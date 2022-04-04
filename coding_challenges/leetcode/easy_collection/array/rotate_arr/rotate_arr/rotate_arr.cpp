#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
//rotate right, try to use O(1) extra space
//probably O(n)?
    void rotate(vector<int>& nums, int k) {

        int temp;
        //use iterators?
        for(int j = 0; j < k; j++){
            temp = nums[nums.size()-1];
            for(int i = nums.size()-1; i >0; i--){
                //shift things right
                nums[i] = nums[i-1];                
            }
            nums[0] = temp;
        }
    }

    /*
    reverse solution
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
    }       

    */

};

int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    Solution sol;
    sol.rotate(vec, 2);
    for(auto it = vec.begin(); it != vec.end(); it++){
        cout << *it << " " << endl;
    }
    return 0;
}