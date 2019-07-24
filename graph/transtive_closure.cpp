/* Transitive Closure for Graph (Graph is implemented using Adjacent Matrix)
    1. transitiveClosure_v3. Cubic timecomplexity using Floys warshall algorithm
        https://www.geeksforgeeks.org/transitive-closure-of-a-graph/
    2. transitiveClosure_v2. Square time complexity using DFS traversal
        https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/
*/


#include <iostream>
using namespace std;
#define V 4

/* Floyd warshall algorithm. V3 time complexity */
void transitiveClosure_v3(int graph[][V]) {
    int reach[V][V], i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (reach[i][j] == 0) {
                for (k = 0; k < V; k++) {
                    if (((i != k) && (reach[i][k] == 1)) &&
                        ((k != j) && (reach[k][j] == 1))) {
                        reach[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void DFSUtil(int graph[][V], int s, int v, int reached[][V]) {
    reached[s][v] = 1;
    for (int j=0; j < V; j++) {
        if (reached[s][j] != 1 && graph[v][j] == 1) {
            DFSUtil(graph, s, j, reached);
        }
    }
}

/* Using DFS Traversal. Perform DFS for each vertex and mark reached[v][0...V] as true in the DFD path. */
void transitiveClosure_v2(int graph[][V]) {
    int reached[V][V];

    for (int i=0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) reached[i][j] = 1;
            else reached[i][j] = 0;
        }
    }

    for (int v = 0; v < V; v++) {
        DFSUtil(graph, v, v, reached);
        cout << endl;
    }
    
    for (int i=0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << reached[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    /*
    int graph[V][V] = {
                        {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
                      */
    int graph[V][V] = {
                        {1, 1, 1, 1},
                        {0, 1, 1, 0},
                        {1, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
    //transitiveClosure(graph);
    transitiveClosure_v2(graph);
    return 0;
}
