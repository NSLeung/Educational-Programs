#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <string>
// #include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm> /* for std::min */
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// int valid_seq(string s, int idx, int stride){
//     if(stoi(s.substr(idx, stride)) == 0){
//         for(int i = 0; i < stride; i++){
//             s[idx + i] = "1";
//             valid_seq(s, idx + 1, stride);
//         }
//     }
// }

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER d
 */

int minimumMoves(string s, int d) {
    int cnt = 0;
    for(int i = 0; i < s.length() - d + 1; i++){
        if(stoi(s.substr(i, d)) == 0){
            s[i+d-1] = '1';
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    // string s;
    // getline(cin, s);

    // string d_temp;
    // getline(cin, d_temp);

    // int d = stoi(ltrim(rtrim(d_temp)));

    // int result = minimumMoves(s, d);

    // fout << result << "\n";

    // fout.close();

    string s;
    cin >> s;
    int d_temp;
    cin >> d_temp;
    int result = minimumMoves(s,d_temp);
    cout << result << endl;

    

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
