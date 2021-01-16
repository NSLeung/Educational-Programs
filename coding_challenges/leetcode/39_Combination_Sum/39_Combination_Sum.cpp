#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
Example 4:

Input: candidates = [1], target = 1
Output: [[1]]
Example 5:

Input: candidates = [1], target = 2
Output: [[1,1]]

*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //key idea: DFS + recursion to explore combination sums
        vector<vector<int>> result(0, vector<int>(0));
        sort(candidates.begin(), candidates.begin()+candidates.size());
        findCombinations(candidates,0,target, vector<int>(), result);
        return result;
    }

    void findCombinations(vector<int> candidates, int index, int target, vector<int> current, vector<vector<int>> result){
        //base case (since you keep subtracting)
        if(target == 0){
            cout << "found target " << target << endl;
            result.push_back(vector<int>(current));
            return;
        }
        if(target < 0) {
            return;
        }

        //DFS with loop
        for(int i = index; i < candidates.size(); i++){
            if(i == index || candidates[i] != candidates[i-1]){
                current.push_back(candidates[i]);
                findCombinations(candidates, i + 1, target - candidates[i], current, result);
                current.erase(current.begin() + current.size() - 1);
            }
        }
    }
};

int main(){
	Solution sol;
	std::vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> result = sol.combinationSum(candidates,11);
    for(auto it = result.begin(); it != result.end(); it++){
        for(auto it2 = it->begin(); it2 != it->end(); it2++){
            cout << *it2;
        }
        cout << "\n" << endl;
    }
	return 0;
}