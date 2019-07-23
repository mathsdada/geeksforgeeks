// https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int numVertices);
    void addEdge(int v, int e);
    int findMother();
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int e) {
    adj[v].push_back(e);
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
    
}

int Graph::findMother() {
    /*
        2-pass algorithm (kosaraju's algo)
        1. Perform DFS for each vertex. Mark the visited vertices as true while doing DFS. Do not perform DFS if vertex is already visited.
           Keep track of last visited vertex on which DFS was perfored.
        2. If there exist a mother vertex then last visited vertext will be a mother. Perform DFS again with that last visited vertex
    */
    int lastVisitedVertex;
    bool *visited = new bool[numVertices];
    for (int i=0; i<numVertices; ++i) visited[i] = false;

    /* 1st pass */
    for (int i=0; i<numVertices; ++i) {
        if (!visited[i]) {
            DFSUtil(i, visited);
            lastVisitedVertex = i;
        }
    }

    /* 2nd pass */
    for (int i=0; i<numVertices; ++i) visited[i] = false;
    DFSUtil(lastVisitedVertex, visited);
    for (int i=0; i<numVertices; ++i) {
        if (!visited[i]) return -1;
    }
    return lastVisitedVertex;
}

int main() {
	// your code goes here
	Graph g(7);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0);
    
    cout << g.findMother();
	return 0;
}
