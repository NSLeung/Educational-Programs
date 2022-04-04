
/* from geeksforgeeks */
#pragma once
#include<iostream>
#include <list>
using namespace std;
/* class name needs to match header file so it should technically be a Graph class */
class BFS {
    int V;
    list<int> *adj; /* adjacency list */
    public:
        BFS(int V); /* graph ctor */
        void addEdge(int v, int w);
        void BFS_traversal(int s); /* actual alg implementation */

};