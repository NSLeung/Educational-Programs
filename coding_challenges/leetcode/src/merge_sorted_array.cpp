#include "util.h"

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(nums2.size()==0)
        return;
    // int temp;
    // int j = 0;
    // for(int i = 0; i < nums1.size(); i++ ){
    //     if((nums2[j] < nums1[i] || nums1[i]==0) && j < nums2.size()){
    //         temp = nums1[i];
    //         nums1[i] = nums2[j];
    //         nums2[j] = temp;
    //         if(temp == 0) {
    //             j++;
    //         }
    //     }
        
    // }
    // cout << "here" << endl;
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0&&j>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
    //fills in the rest
    while(i>=0)
        nums1[k--]=nums1[i--];
    while(j>=0)
        nums1[k--]=nums2[j--];

}

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution s;
    s.merge(nums1, nums1.size(), nums2, nums2.size());
    s.printVector(nums1);
    s.printVector(nums2);
    return 0;
}