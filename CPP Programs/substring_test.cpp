#include <string>
#include <iostream>
#include <tuple>

#include <algorithm>
#include <vector>
#include <cctype>
#include <clocale>
int main(){
  // std::string str;
  // std::string str2 = "hello";
  //
  // str = str2.substr(0, 3) + "hi";
  // std::cout << str << std::endl;
  // std::cout << "using indexer" << str[3] << std::endl;
  //
  // std::tuple<std::string, int, int> tuple("hi", 1, 2);
  // // std::cout << tuple.begin()->first << tuple.begin()->second << tuple.begin()->third << std::endl
  // std::cout << std::get<0>(tuple) << std::endl;
  //
  // std::string test_string = "test";
  // // char substr = (char) test_string.substr(0,1);
  // // unsigned char substr = test_string[0];
  // unsigned char substr = 'a';
  // std::transform(test_string.begin(), test_string.end(), test_string.begin(),  [](unsigned char c) -> unsigned char { return std::toupper(c); });
  // std::cout << test_string << std::endl;
  //
  // std::vector<std::tuple<int, int, int>> vec;
  // vec.push_back(std::tuple<int, int, int>(1,1,1));
  // std::cout << std::get<0>(vec[0]) <<std::endl;

  std::string str = "dcba";
  std::sort(str.begin(), str.end());
  std::cout << str << std::endl;
}
