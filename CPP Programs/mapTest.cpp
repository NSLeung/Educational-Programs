#include <unordered_map>
#include <iostream>
#include <string>
int main(){

std::unordered_map<std::string, int> map;
map.insert(std::pair<std::string, int>("hello", 3));
map.insert(std::pair<std::string, int>("die", 4));
map.insert({"wot", 5});

  for(auto it : map){
    std::cout << it.first << std::endl;
  }

  return 0;
}
