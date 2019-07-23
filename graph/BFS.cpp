// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adj;
public:
    Graph(int numVertices);
    void addEdge(int v, int e);
    void BFS(int v);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int e) {
    adj[v].push_back(e);
}

void Graph::BFS(int v) {
    bool *visited = new bool[numVertices];
    for (int i=0; i<numVertices; ++i) visited[i] = false;
    
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);
    
    while (!queue.empty()) {
        int v = queue.front();
        cout << " " << v; 
        queue.pop_front();
        
        for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
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
    
    g.BFS(5);
	return 0;
}
