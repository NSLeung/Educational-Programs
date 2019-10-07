#include <stack>
#include <iostream>
#include <vector>
int main(){
  std::stack<int> s;
  std::vector<int> v;
  if(!s.empty()){
    std::cout << "popping empty stack" << s.top() << std::endl;

  }
  std::cout << "size of empty v" << v.size();
  return 0;
}
