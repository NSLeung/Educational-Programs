#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_set>
#include <unordered_map>
// #include <priority_queue>
#include <vector>
#include <limits>
/**
 * Returns an std::list of vertex keys that creates some shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */


//DIJKSTRA's ALGORITHM
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  std::list<std::string> path;
  //change map from string to int (weight) to string to string
  std::unordered_map<std::string , std::string> map;
  // const int INF = -1;

  for(auto it = vertexMap.begin(); it!=vertexMap.end(); it++){
    //initialize vertices to have filler values
    map[it->second.key()] = "INF";
  }
  std::queue<std::string> Q;
  map[start]="0";
  //push the starting vertex
  Q.push(start);

  //while queue is not empty
  while(!Q.empty()){
    //pop doesn't return so need to grab front first
    std::string curr = Q.front();
    Q.pop();

    //edge list
    std::list<std::reference_wrapper<E>> inc_edges = incidentEdges(curr);
    for(auto it = inc_edges.begin(); it != inc_edges.end(); it++ ){
      if(it->get().source().key() == curr && map[it->get().dest().key()] == "INF") {
        map[it->get().dest().key()] = curr;
        Q.push(it->get().dest().key());
      }
      else if (it->get().dest().key() == curr && map[it->get().source().key()] == "INF"){
        map[it->get().source().key()] = curr;
        Q.push(it->get().source().key());
      }
      if(map[end] != "INF"){
        break;
      }
    }
    if(map[end] != "INF"){
      break;
    }
  }//end of while loop

  if(map[end] != "INF" ){
    std::string curr = end;
    // int curr_val = 0;
    while(map.find(curr)!=map.end()){
      //add to resultant path
      path.push_front(curr);
      curr = map[curr];
    }
  }
  return path;
}
