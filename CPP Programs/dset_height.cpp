/* Your code here! */
#include "dset.h"
#include <vector>
#include <iostream>
/**
 * Creates n unconnected root nodes at the end of the vector.
 * @param num The number of nodes to create
 */
void DisjointSets::addelements	(int num)	{
  //append n root nodes at end of vector  (represented by -height-1)
  for(int i = 0; i < num; i++){
    disjointSetVec.push_back(-1);
  }
}

/**
 * This function should compress paths and works as described in lecture.
 * @param  elem elt
 * @return      the index of the root of the up-tree in which the parameter element resides.
 */
int DisjointSets::find (int elem) {
  //(base case) if at root node, return
  if(disjointSetVec[elem] < 0){
    return elem;
  }

  //no path compression
  // else{
  //   int root = find(disjointSetVec[elem]);
  //   return root;
  // }

  //path compression
  else{
    int root = find(disjointSetVec[elem]);
    //recursively reassign root
    disjointSetVec[elem] = root;
    return root;
  }
}

/**
 * This function should be implemented as union-by-height.



Your setunion function SHOULD find the roots of its arguments
before combining the trees. If the two sets are the same size,
make the tree containing the second argument point to the tree
containing the first. (Note that normally we could break this
tie arbitrarily, but in this case we want to control things for grading.)
 * @param a 	Index of the first element to union
 * @param b Index of the second element to union

 */
void DisjointSets::setunion (int a, int b){
  //get roots first
  int root1 = find(a);
  int root2 = find(b);

  if(root1 == root2){
    return;
  }
  //implement union by height
  // int newSize = disjointSetVec[root1] + disjointSetVec[root2];

  int newHeight = 0;
  //if root2 is deeper
  if(disjointSetVec[root2] < disjointSetVec[root1]){
    disjointSetVec[root1] = root2; //make root2 new root
  }
  else{
    //if both same height
    if(disjointSetVec[root1] == disjointSetVec[root2]){
      disjointSetVec[root1]--;
    }
    //make root1 new root
    disjointSetVec[root2] = root1;
  }
}

/**
 * This function should return the number of nodes in the up-tree containing the element.
 * @param  elem elt
 * @return      number of nodes in the up-tree containing the element
 */
int	DisjointSets::size (int elem){
  //find root first, then calculate size
  int root = find(elem);
  if(disjointSetVec[root]!=0){

    return -disjointSetVec[root];
  }
  return 0;
}

void DisjointSets::printVec(){
  //print index above
  // std::cout << " ";
  for(unsigned i = 0; i < disjointSetVec.size();i++){
    if(i < 9)
      std::cout << i << " ";
    else if(i != disjointSetVec.size()-1){
      std::cout << i << " ";
    }
    else
      std::cout << i << " " <<std::endl;
  }
  for(unsigned i = 0; i < disjointSetVec.size(); i++){
    if(i != disjointSetVec.size()-1)
      std::cout << disjointSetVec[i] << " ";
    else
      std::cout << disjointSetVec[i] << " " <<std::endl;
  }
}
