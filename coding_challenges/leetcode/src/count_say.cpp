#include "util.h"

string say(string s) {
        /* parse string and return the string that "says" it */
    string ret = "";

    int count = 1;
    char last = s[0];
    for (int i = 1; i < s.length(); i++) {
        if(s[i] != last) {
            ret += (to_string(count) + last); /* represent the 'count' */
            last = s[i];
            count = 1; /* reset the count once you hit a unique char */
        }
        else {
            count++;
        }
    }
    ret += (to_string(count) + last);
    return ret;
}
string Solution::countAndSay(int n) {
    /* base case */
    if (n == 1)
        return "1";
    string ret = "1";
    for(int i = 2; i <= n; i++) {
        /* use the previously stored ret starting with the "1" basecase */
        ret = say(ret);
    }
    return ret;
    
}

int main() {
    Solution s;
    cout << s.countAndSay(6) << endl;
    return 0;
}