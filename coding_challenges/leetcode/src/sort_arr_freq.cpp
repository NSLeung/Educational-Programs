#include "util.h"
// Comparator function to sort pairs 
// according to second value 
bool cmp(pair<int, int>& a, 
         pair<int, int>& b) 
{ 
    return a.second < b.second; 
} 
  
vector<int> Solution::frequencySort(vector<int>& nums) {
    // map<int, int> freq_map;
    // vector<pair<int, int>> v;
    // for(int i = 0; i < nums.size(); i++){
    //     if(freq_map.find(nums[i]) != freq_map.end()) {
    //         freq_map[nums[i]]++;
    //     }
    //     else {
    //         freq_map[nums[i]] = 0;
    //     }
    // }
    // for(auto &it : freq_map){
    //     v.push_back(it);
    // }
    // sort(v.begin(), v.end(), cmp);
    // vector<int> ret;
    // for(auto it : v){
    //     ret.push_back(it.first);
    // }
    // return ret;

    //shorter soln
     unordered_map<int,int> mp;        // count the values and no need of ordering
        
    for(int i = 0;i < arr.size();i++){
        mp[nums[i]]++;
    }
    
    map<int,vector<int>> temp;       
    
    for(auto it : mp){          // reverse the map 'mp' and order based on count
        temp[it.second].push_back(it.first);
    }
    
    nums = {};
    for(auto it : temp){
        sort(it.second.begin(),it.second.end());        // sort the same counted numbers and start adding it to new array
        for(int i = it.second.size() - 1;i >= 0;i--){
            for(int j = 0;j < it.first;j++)
                nums.push_back(it.second[i]);
        }
    }
    
    return nums;
}

int main() {
    vector<int> nums = {1,1,2,2,2,3};
    Solution s;
    s.printVector(s.frequencySort(nums));
    return 0;
}