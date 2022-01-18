// A C++ program for Dijkstra's single source shortest path algorithm.

// The program is for adjacency matrix representation of the graph

#include <iostream>

using namespace std;

#include <limits.h>

#include <cstring>

// V is the number of vertices in the graph and is initialized to 0

int V = 0;

// A utility function to find the vertex with minimum distance value, from

// the set of vertices not yet included in shortest path tree

int minDistance(int dist[], bool sptSet[])

{
    //TODO

    return min_index;
}

// A utility function to print the constructed distance array

void printSolution(int dist[])

{
    for (int i = 0; i < V; i++)

        cout << i << " " << dist[i] << endl;
}

// Function that implements Dijkstra's single source shortest path algorithm

// for a graph represented using adjacency matrix representation

void dijkstra(int** graph, int src)

{
    /*Set the "graphmatrix" 2D array to the adjacency matrix of the graph to use Dijkstra's algorithm

    , and the subsequent operations are to use the "graphmatrix" 2D array as the adjacency matrix of the graph to use Dijkstra's algorithm*/

    int graphmatrix[V][V];

    for (int i = 0; i < V; i++)

        for (int j = 0; j < V; j++)

            graphmatrix[i][j] = *((int*)graph + i * V + j);

    /* "graphmatrix" 2D array is the adjacency matrix of the graph to be processed, while src is the source vertex when using Dijkstra's algorithm. */

    int dist[V];  // The output array.  dist[i] will hold the shortest

    // distance from src to i

    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in shortest

    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false

    for (int i = 0; i < V; i++)

        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0

    dist[src] = 0;

    // Find shortest path for all vertices

    //TODO

    // print the constructed distance array

    printSolution(dist);
}

// driver program to test above function

int main()

{
    string cmd;

    int E;

    cin >> cmd;

    //You should create the graph first

    if (cmd == "creategraph") {
        cin >> V;

        cin >> E;
    }

    //Create the adjacent matrix of the given graph and set it to zero

    int graph[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 1000000;  //1000000 is used to represent infinity, which is much larger than the value of all the given edges in the testcase.

    while (cin >> cmd) {
        if (cmd == "addEdge") {
            int u;

            int v;

            int w;

            cin >> u;

            cin >> v;

            cin >> w;

            graph[u][v] = w, graph[v][u] = w;

        } else if (cmd == "dijkstra") {
            int s;  //source node

            cin >> s;

            dijkstra((int**)graph, s);

        } else if (cmd == "exit") {
            return 0;
        }
    }

    return 0;
}

// This code is contributed by shivanisinghss2110
