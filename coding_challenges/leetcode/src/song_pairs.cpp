#include "util.h"

int Solution::numPairsDivisibleBy60(vector<int>& time) {
    
    vector<int> v(60,0);
    for(int i =0;i<time.size();i++){
        int index = time[i] % 60;
        v[index] += 1;
    }
    int ans = 0;
    for (int i = 0; i <= 30; ++i) {
        if (i == 0 || i== 30) {
            ans += (v[i] * (v[i] - 1)) / 2;
        } else {
            ans += (v[i] * v[60-i]);
        }
    }
    return ans;


}

int main() {

}