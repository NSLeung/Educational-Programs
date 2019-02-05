#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 *
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  //local variables
  // std::stack<Point> s;
  // std::vector<Point> visited_vec;
  bool visited = false;

  //initialize private variables so other helper functions can use
  startPoint = start;
  maxTolerance = tolerance;
  Point toAdd = start;
  Point neighbor;
  double currTolerance = 0;
  img = png;

//initialize 2D vector visitedVec
  visitedVec = std::vector<std::vector<bool>>(img.width(), std::vector<bool>(img.height(),0));
//add starting point to visited_vec
// visitedVec.push_back(toAdd);
// traversalVec.push_back(start);
//mark start as visited
visitedVec[start.x][start.y] = true;
neighborStack.push(start);
  //2. pixel at point is >= tolerance
  // if(!neighborStack.empty()){
// while(numNeighbors()!=0){
//
//
//       add(toAdd);
    // for(int j = 0; j < 4; j++){
    //   if(j==0){
    //     Point neighbor(toAdd.x + 1, toAdd.y);
    //     //add pixel right
    //     add(neighbor);
    //   }
    //   else if(j==1){
    //     Point neighbor(toAdd.x, toAdd.y  + 1);
    //
    //     //add below
    //    add(neighbor);
    //   }
    //   else if(j==2){
    //     Point neighbor(toAdd.x - 1, toAdd.y);
    //
    //     //add left
    //     add(neighbor);
    //   }
    //   else{
    //     Point neighbor(toAdd.x, toAdd.y  - 1);
    //
    //     //add above
    //     add(neighbor);
    //   }
    // }
      //after adding all neighbors, visit the recent one (top of stack)
      // if(!neighborStack.empty()){
      //   toAdd = neighborStack.top();
      //   //add to traversal vec
      //   traversalVec.push_back(toAdd);
      //   //pop off stack because visited (optional)
      //   // neighborStack.pop();
      // }
      //if there are no neighbors left, check rest of stack and pop if necessary
      // if(validNeighborCount == 0){
      //   for(unsigned long i=0; i<visitedVec.size(); i++){
      //     for(unsigned long j=0;j<visitedVec[i].size();j++){
      //       if(!neighborStack.empty()){
      //         int neighborX = neighborStack.top().x;
      //         int neighborY = neighborStack.top().y;
      //         if(visitedVec[neighborX][neighborY]){
      //           neighborStack.pop();
      //           //reset indices to check remaining stack elements  (until empty..)
      //           i=0;
      //           j=0;
      //           break;
      //         }
      //       }
      //     }
      //   }
      // }//end of if
      //iterate to next
      // if(!neighborStack.empty()){
      //   toAdd = neighborStack.top();
      // }

  // }
  }
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  ImageTraversal::Iterator* dfs = new DFS();
  return *dfs;
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  if(!inBounds(point)){return;}
  //right neighbor
  if(inBounds(Point(point.x+1, point.y)) && !visitedVec[point.x + 1][point.y] ){
    if(ImageTraversal::calculateDelta(img.getPixel(point.x + 1, point.y), img.getPixel(startPoint.x, startPoint.y)) < maxTolerance){
      neighborStack.push(Point(point.x + 1, point.y));
      validNeighborCount++;
    }
    else{
      visitedVec[point.x + 1][point.y] = true;
    }
  }

  //below neighbor
  if(inBounds(Point(point.x, point.y+1)) && !visitedVec[point.x + 1][point.y] ){
    if(ImageTraversal::calculateDelta(img.getPixel(point.x + 1, point.y), img.getPixel(startPoint.x, startPoint.y)) < maxTolerance){
      neighborStack.push(Point(point.x + 1, point.y));
      validNeighborCount++;
    }
    else{
      visitedVec[point.x + 1][point.y] = true;
    }
  }
  //left neighbor
  if(inBounds(Point(point.x-1, point.y)) && !visitedVec[point.x + 1][point.y] ){
    if(ImageTraversal::calculateDelta(img.getPixel(point.x + 1, point.y), img.getPixel(startPoint.x, startPoint.y)) < maxTolerance){
      neighborStack.push(Point(point.x + 1, point.y));
      validNeighborCount++;
    }
    else{
      visitedVec[point.x + 1][point.y] = true;
    }
  }
  //upper neighbor
  if(inBounds(Point(point.x-1, point.y)) && !visitedVec[point.x + 1][point.y] ){
    if(ImageTraversal::calculateDelta(img.getPixel(point.x + 1, point.y), img.getPixel(startPoint.x, startPoint.y)) < maxTolerance){
      neighborStack.push(Point(point.x + 1, point.y));
      validNeighborCount++;
    }
    else{
      visitedVec[point.x + 1][point.y] = true;
    }
  }

  // bool toAdd = true;
  // for(unsigned long i = 0; i < visitedVec.size(); i++){
  //   //check if point has already been visited, has right tolerance, and is in bounds
  //   if(point == visitedVec[i] || (ImageTraversal::calculateDelta(img.getPixel(point.x, point.y), img.getPixel(startPoint.x, startPoint.y)) >= maxTolerance) ){
  //     validNeighborCount++;
  //     toAdd = false;
  //   }
  // }
  // if(toAdd){
  //   neighborStack.push(point);
  // }
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return visitedVec.front();
}
bool DFS::inBounds(Point p){
  if((point.x < 0) || (point.x >= img.width()) || (point.y < 0) || (point.y >= img.height())){
    return false;
  }
  return true;
}
//return number of neighbors at top of stack
int DFS::numNeighbors(){
  //mark tolerance visited ()
  int count = 0;
  //right
  if(!visitedVec[neighborStack.top().x + 1][neighborStack.top().y]){
    count++;
  }
  //below
  if(!visitedVec[neighborStack.top().x][neighborStack.top().y + 1]){
    count++;
  }
  //left
  if(!visitedVec[neighborStack.top().x - 1][neighborStack.top().y]){
    count++;
  }
  //above
  if(!visitedVec[neighborStack.top().x][neighborStack.top().y - 1]){
    count++;
  }
  return count;
}
/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return true;
}
