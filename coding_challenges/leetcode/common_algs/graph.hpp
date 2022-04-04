#include "graph.h"
#include "edge.h"
#include "vertex.h"

#include <string>
#include <iostream>

/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::size() const {
  // TODO: Part 2
  return vertexMap.size();
}


/**
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
  std::string vertex_key;
  //iterate through vertex map to find param
  for(auto it : vertexMap){
    if(it->second == v){
      vertex_key = it->first;
      //break out of loop because vertex key is found
      break;
    }
  }
  //locate the degree (key) and grab the list's size
  return (adjList.find(vertex_key)->second).size();
}


/**
* Inserts a Vertex into the Graph by adding it to the Vertex map and adjacency list
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
  V & v = *(new V(key));

  //add to vertex map
  vertexMap.insert(std::pair<std::string, V&>(key, v));
  std::list<edgeListIter> l;
  adjList.insert(std::pair<std::string, std::list<edgeListIter>>(key, l));
  return v;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2
  //find vertex in vertexMap
  // auto toDel = vertexMap.find()
  vertexMap.erase(key);
  adjList.erase(key);
}


/**
* Inserts an Edge into the adjacency list
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2
  E & e = *(new E(v1, v2));

  //add to front of edge linked list
  edgeList.push_front(e);
  //grab iterator of list and insert into adjacency list
  auto it = edgeList.begin();
  //locate 2 existing vertices and attach edge iterator/list pointer to front of edgeList
  adjList[v1.key()].push_front(it);
  adjList[v2.key()].push_front(it);
  return e;
}


/**
* Removes an Edge from the Graph
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {
  // TODO: Part 2

  for(edgeListIter & it : (adjList.at(key1).size() < adjList.at(key2).size()) ? adjList.at(key1) : adjList.at(key2)){
    if(((Edge&)*it).source().key() == key1 && ((Edge&)*it).dest().key() == key2){
      removeEdge(it);
      break;
    }
  }
  // for(edgeListIter & it : adjList[key2]){
  //   if(((Edge&)*it).source().key() == key1 && ((Edge&)*it).dest().key() == key2){
  //     removeEdge(it);
  //     break;
  //   }
  // }
  // for(auto e : edgeList){
  //   if(((Edge &)*e).source().key() == key1 && ((Edge &)*e).source().key() == key2){
  //     edgeList.erase(e);
  //   }
  // }
}


/**
* Removes an Edge from the adjacency list at the location of the given iterator
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
  adjList[((Edge&)*it).source().key()].remove(it);
  adjList[((Edge&)*it).dest().key()].remove(it);
  edgeList.erase(it);

}


/**
* @param key The key of an arbitrary Vertex "v"
* @return The list edges (by reference) that are adjacent to "v"
*/
template <class V, class E>
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges;

  //Method 1: since we're using an adjacency list, just use the private member structure (at the given vertex key)
  //Method 2: iterate through edge list and check source and dest labels
  for(std::reference_wrapper<E> e : edgeList){
    if(e.get().source().key() == key || e.get().dest().key() == key){
      edges.push_back(e);
    }
  }
  return edges;
}


/**
* Return whether the two vertices are adjacent to one another
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
  //runtime is O(min(deg(v1), deg(v2))) so we want to be checking in adjacency list
  //accessing adjlist using bracket notation and then calling method causes compiler error (because const?) - so must use .at operator
  std::list<edgeListIter> fasterList = (adjList.at(key1).size() < adjList.at(key2).size()) ? adjList.at(key1) : adjList.at(key2);
  // std::list<edgeListIter> fasterList = ((adjList[key1]).size() < (adjList[key2]).size()) ? adjList[key1] : adjList[key2];

  for(edgeListIter it : fasterList){
    //if there is an edge with key1 as the source and key2 as the dest, then return true
    if(((Edge&)*it).source().key() == key1 && ((Edge&)*it).dest().key() == key2){

      return true;
    }
  }
  return false;

}
