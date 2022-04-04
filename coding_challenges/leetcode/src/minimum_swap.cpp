#include "util.h"

int Solution::minimumSwap(string s1, string s2) {
    /* smells like a backtracking minimum edit distance problem */
    /* it is actually not, just handle the 2-3 main cases */
    // if(s1.size() != s2.size()) return -1;
    int num_xy=0, num_yx=0;
    for(int i=0; i<s1.size(); i++){
        /* obtain the pair counts */
        if(s1[i]=='x' && s2[i]=='y') num_xy++;
        else if(s1[i]=='y' && s2[i]=='x') num_yx++;
    }
    /* this is required */
    if(num_xy%2 != num_yx%2) return -1;
    /* mod handles the even */
    return num_xy/2 + num_yx/2 + (num_xy%2) * 2;
    
}

int main() {

    return 0;
}