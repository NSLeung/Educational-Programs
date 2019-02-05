#include "dset.h"
#include <iostream>
#include <algorithm>
int main(){
  DisjointSets dset;

  // dset.addelements(12);
  // // std::cout << "hi" << std::endl;
  // dset.setunion(4,10);
  // dset.setunion(10,5);
  // dset.setunion(6,5);

  //initialize dset
  std::vector<int> vec = {6, 6, 6, 8, -4, 10, 7, -3, 7, 7, 4, 5};
  // int myints[] = {6, 6, 6, 8, -4, 10, 7, -3, 7, 7, 4, 5};
  // dset.printVec();

  // dset.disjointSetVec(vec.begin(), vec.end());
  // std::copy(myints, myints + 12, dset.disjointSetVec.begin());
  dset.disjointSetVec = vec;
  dset.printVec();
  dset.setunion(4,0);
  dset.printVec();

  //after path compression
  // dset.setunion(4, 0);
  return -1;
}
