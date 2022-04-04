#include "util.h"

void Solution::reverseString(vector<char>& s) {
    /* try using 2 pointer approach */
    for(int i = 0; i < s.size()/2; i++){
        char temp = s[s.size()-1 - i];
        s[s.size()-1 - i] = s[i];
        s[i] = temp;
    }
}

int main(){
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    Solution s;
    s.printVector(str);
    s.reverseString(str);
    s.printVector(str);
    return 0;
}