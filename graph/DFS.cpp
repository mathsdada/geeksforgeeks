// https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

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
    void DFS(int v);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int e) {
    adj[v].push_back(e);
}

void Graph::DFSUtil(int v, bool visited[]) {
    cout << " " << v;
    visited[v] = true;
    
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
    
}

void Graph::DFS(int v) {
    bool *visited = new bool[numVertices];
    for (int i=0; i<numVertices; ++i) visited[i] = false;
    
    DFSUtil(v, visited);
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
    
    g.DFS(0);
	return 0;
}
