#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Input n=2
(())
()()

n=4


*/



class Solution {
public:
    //maybe some sort of backtracking to explore different possibilities? use helper function?
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        //start by adding right paren (n>0)
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};

int main(){
	Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for(auto it = result.begin(); it != result.end(); it++){
        for(auto it2 = it->begin(); it2 != it->end(); it2++){
            cout << *it2;
        }
        cout << "\n" << endl;
    }
	return 0;
}