#include "util.h"


string Solution::longestCommonPrefix(vector<string>& strs) {
    // if(strs.size()==0 || strs[0] == ""){
    //     return "";
    // }
    // if(strs.size()==1){
    //     return strs[0];
    // }
    // int idx = 1;
    // int cnt_match = 1;
    // bool found = false;
    // while(!found && idx <= strs[0].size()){
    //     for(int i = 1; i < strs.size(); i++) {
    //         string prefix = strs[0].substr(0, idx);
    //         // cout << prefix << endl;
    //         if (prefix == strs[i].substr(0,idx)){
    //             cnt_match++;
    //         }
    //         else{
    //             found = true;
    //         }

    //     }
    //     if(cnt_match == strs.size()){
    //         cnt_match = 1;
    //         idx++;
    //     }
    //     else {
    //         found = true;
    //     }
    // }
    
    // return strs[0].substr(0,idx-1);

    //cleaner solution
    if(strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string a = strs[0], b = strs.back();
    int i = 0;
    for(; i < min(a.size(), b.size()); i++) 
        if(a[i] != b[i]) 
            break;
    return a.substr(0, i);
}


int main() {
    // vector<string> v = {"flower","flow","flight"};
    vector<string> v = {"dog", "racecar", "car"};
    Solution s;
    cout << s.longestCommonPrefix(v) << endl;
    return 0;   
}