#include "util.h"


/* check if the number sum */
// bool check(string num1, string num2, string num3) {
//     cout << "check" << endl;
//     /* if any operand contains leading 0, return false */
//     if (num3.size() > 1 && num3[0] == '0') {
//         cout << "ERR 1" << endl;
//         return false;
//     }
//     long sum = stol(num1) + stol(num2);
//     long len = (long)(log10(sum)) + 1;
//     if (stol(num3) == sum) return true;
//     if (stol(num3) < sum || sum != stol(num3.substr(0, len))) {
//         cout << "ERR 2" << endl;

//         return false;
//     }
//     else return check(num2, to_string(sum), num3.substr(len));

// }
string add(string n, string m){
    string res;
    int i=n.size()-1, j=m.size()-1, carry=0;
    while(i>=0 || j>=0){
        int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
        res.push_back(sum%10+'0');
        carry=sum/10;
    }
    if(carry) res.push_back(carry+'0');
    reverse(res.begin(), res.end());
    return res;
}

bool check(string num1, string num2, string num){
    if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
    string sum=add(num1, num2);
    if(num==sum) return true;
    if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
    else return check(num2, sum, num.substr(sum.size()));
} 


bool Solution::isAdditiveNumber(string num) {
    /* simple case basically fibonacci */
    /* challenge is separating the numbers */
    // facts - know that there are at least 3 numbers so length of first 2 numbers can't be longer than half the string
    for(int i = 1; i <= num.size()/2; i++) {
        for(int j = 1; j <= (num.size()-i)/2;j++){
            if(check(num.substr(0,i), num.substr(i, j), num.substr(i+j))) return true;
        }
    }
    cout << "got here" << endl;
    return false;
}


int main() {
    string str = "123";
    Solution s;
    cout << s.isAdditiveNumber(str) << endl;
    return 0;
}
