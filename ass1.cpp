#include<bits/stdc++.h>

using namespace std;


class Graph {
    int V;
    vector<int> *adj;

public:
    Graph(int V) {//construcor
        this->V = V;
        adj = new vector<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) { 
                DFSUtil(*i, visited);
            }
        }
    }

    void DFS(int v) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        DFSUtil(v, visited);
    }

   
    void BFS(int v) {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            v = q.front();
            cout << v << " ";
            q.pop();

            for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
};

int main() {
    ifstream inputFile("graph.txt");
    //if (!inputFile.is_open()) {
        //cout << "Error opening file" << endl; 
        //return 0;
    //}

    int V, E;
    inputFile >> V >> E;

    Graph g(V);

    for (int i = 0; i < E; i++) {
        int v, w;
        inputFile >> v >> w;
        g.addEdge(v, w);
    }

    inputFile.close();

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);
    cout << endl;

    return 0;
}

