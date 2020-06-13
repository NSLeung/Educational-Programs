#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }   
    int pos_erase;
    cin >> pos_erase;
    vec.erase(vec.begin() + pos_erase - 1);
    int range_erase_start;
    int range_erase_end;
    cin >> range_erase_start >> range_erase_end;
        vec.erase(vec.begin() + range_erase_start - 1, vec.begin() + range_erase_end - 1);
    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

