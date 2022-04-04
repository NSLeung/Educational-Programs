#include "util.h"

int Solution::compress(vector<char>& chars) {
    vector<char> s;
    char new_char = chars[0];
    // char new_char;
    int cnt = 1;
    for(int i = 1; i < chars.size(); i++) {
        // new_char = chars[i-1];
        if(chars[i] != new_char){
                        
            s.push_back(new_char);
            if(cnt>1){
                string str = to_string(cnt);
                //push back cnt (by digits)
                for(int j = 0; j < str.size(); j++) {
                    s.push_back(str[j]);
                }
            }
            new_char = chars[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }

    s.push_back(new_char);
    if(cnt>1){
        string str = to_string(cnt);
        //push back cnt (by digits)
        for(int j = 0; j < str.size(); j++) {
            s.push_back(str[j]);
        }
    }

    // Solution sol;
    // sol.printVector(s);

    chars.clear();
    for(int i = 0; i < s.size(); i++) {
        chars.push_back(s[i]);
    }

    return s.size();

}

int main() {
    Solution s;
    vector<char> c = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << "s return: " << s.compress(c) << endl;
    s.printVector(c);
}