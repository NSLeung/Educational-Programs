#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
	public:
		string longestPalindrome(string s) {
			//ok this seems like an actual backtracking one
			
			//string LPS = s;
			int n = s.length();
			vector<vector<int>> LPS(n, vector<int>(n, 0));

			cout << s << endl;
			for(int i = 0; i < n; i++){
				for(int j = n - 1; j >= i; j--){
					cout << "analyzing (i, j): " << i << " , " << j << " " << s[i] << " " << s[j] << endl;
					if((s[i] == s[j]) && (i==j)){
						LPS[i][j] = 1;
					}
					else if(s[i] == s[i+1]){
						LPS[i][i+1] = (s[i] == s[i+1]);
					}
					else{
						LPS[i][j] = ((s[i] == s[j]) && LPS[i+1][j-1]);
					}
				}
			}
			int max_range = 0;
			int start_idx = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if (LPS[i][j] == 1){
						if(j - i > max_range){
							max_range = j - i;
							start_idx = i;
						}
					}
				}
			}
			cout << "hello, world!" << endl;
			return s.substr(start_idx, max_range + 1);
		}
};

int main(){
	Solution sol;
	string test1 = "dabcbap";
	cout << sol.longestPalindrome(test1) << endl;
	return 0;
}

