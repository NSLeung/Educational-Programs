#include <vector>
#include <iostream>
int main(){
  std::vector<int> vec(3, 0);
  for(unsigned i = 0; i < vec.size(); i++){
    std::cout << "vec value " << vec[i] << std::endl;
  }
  return 0;
}
