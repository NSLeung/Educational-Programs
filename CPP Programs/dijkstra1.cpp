
#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
// #include <priority_queue>
#include <vector>
#include <limits>

template <class V, class E>
  std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  std::list<std::string> path;
  // std::queue<Vertex> vertexQueue;
  std::unordered_set<std::string> set;
  std::unordered_map<std::string, int> distMap;
  //
  // for(auto it : adjList[start]){
  //   vertexQueue.push(((Edge&)*it).source());
  // }
  // visited.insert(start);


  const int INF = -1;
  //make pair struct to hold distancec
  struct Dist_struct{
    Dist_struct(){
      vertex = INF;
      dist = INF;
    }
    //struct ctor
    Dist_struct(std::string v1, int d){
      vertex = v1;
      dist = d;
    }
    std::string vertex;
    int dist;
  };
  auto cmp = [](Dist_struct *d1, Dist_struct *d2) { return d1->dist < d2->dist;};
  //initialize dist struct
  Dist_struct ** d= new Dist_struct*[size()];

  //initialize first distances array elt
  d[0] = new Dist_struct(start, 0);
  int index = 1;
    //iterate through graph and initialize vertex costs to infinity
  for (auto it : vertexMap){
    if(it.first != start){
      //initialize distances to infinity
      d[index] = new Dist_struct(it.first, INF);
    }
    else{
      index++;
    }
  }
  std::priority_queue<Dist_struct*, std::vector<Dist_struct*>,decltype(cmp)>  Q(cmp);
  //add to priority queue
  for(unsigned i = 0; i < size(); i++){
    Q.push(d[i]);
  }
  int num = size();
  while(num > 0){
    Dist_struct *d = Q.top();
    Q.pop();
    set.insert(d->vertex);

    //iterate through
    for(auto it : adjList[d->vertex]){
      //neighbors of u not in set
      if(set.find(((Edge&)*it).dest().key()) != set.end()){
        if(distMap[d->vertex] < distMap[((Edge&)*it).dest().key()]){
          distMap[((Edge&)*it).dest().key()] = distMap[d->vertex] + 1;
          path.push_back(d->vertex);
        }
      }
    }
    num--;
  }
  return path;
}
