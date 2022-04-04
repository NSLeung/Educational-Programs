#include "util.h"

int Solution::numWaterBottles(int numBottles, int numExchange) {
    // return numBottles + numBottles/numExchange + 
    int drank = numBottles;
    while(numBottles > 0 && numBottles >= numExchange) {
        int exchanged = (numBottles / numExchange)*numExchange;
        cout << "exchanged " << exchanged << endl;
        int returned = exchanged/numExchange;
        numBottles = numBottles - exchanged + returned;
        drank += returned;
        cout << numBottles << endl;
    }
    return drank;
}

int main() {
    Solution s;
    int ret = s.numWaterBottles(9,3);
    cout << "numWaterBottles " << ret << endl;
}