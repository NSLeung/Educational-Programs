#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
//#include <string.h>
#include <limits.h>
#include <set>
using namespace std;
class Solution {
	public:
/*
		int helper(int i, int j){
			
		}
		*/
		int lengthofLongestSubstring(string s_arg) {
		
			//this just smells like a memoized backtracking problem using max
			//initialize memoized structure
			string s("A");
			
			s += s_arg;
			int n, m;
			n = s.length();
			m = n;
			cout << n << endl;
			vector<vector<int>> LIS(n + 1, vector<int> (m, 0));
			
			for(int i = n - 1; i >=0; i--){
				for(int j = 0; j < i; j++){
					if(s[i] != s[j]){
					cout << "(i, j): " << i << ", " << j<< " " << s[i] << ", " << s[j] << endl; 
						LIS[i][j] = LIS[i + 1][j];
					}
					else{

						cout << "[ELSE] (i, j): " << i << ", " << j<< " " << s[i] << ", " << s[j] << endl; 
						cout << "LIS[i + 1][j]: " << LIS[i + 1][j] << endl;
						LIS[i][j] = max(LIS[i + 1][j], 1 + LIS[i + 1][i]);
						cout << "LIS[i][j] got assigned " << LIS[i][j] << endl;
					}

				}
			}
			
			return LIS[1][0];
		}
		int lengthofLongestSubstring2(string s)
		{
			int i = 0;
			int j = 0;
			int n = s.length();
			int ret = 0;
			set<char> set;
			while(i < n && j < n){
				//try to extend
				if(!set.count(s[j])){
					set.insert(s[j++]);
					ret = max(ret, j - i);
				}
				else{
					set.erase(s[i++]);
				}
			}
			return ret;
		}
};

int main(){

	Solution sol;
	string tests = "abcabcbb";
	string test2 = "bbbbbb";
	string test3 = "pwwkew";
	cout << sol.lengthofLongestSubstring2(tests) << endl;

	cout << sol.lengthofLongestSubstring2(test2) << endl;
	cout << sol.lengthofLongestSubstring2(test3) << endl;

	return 0;
}

