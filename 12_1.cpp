#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V;
    
    vector<vector<int> > adj; 

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        
    }

    
    void DFS(int s) {
       
        vector<bool> visited(V, false);
        queue<int> q;

        
        visited[s] = true;
        q.push(s);

        cout << "\nDFS Traversal starting from vertex " << s << ": ";

        while (!q.empty()) {
           
            int curr = q.front();
            cout << curr << " ";
            q.pop();

            for (size_t i = 0; i < adj[curr].size(); i++) {
                int neighbor = adj[curr][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges, source;

    cout << "--- DFS Implementation ---" << endl;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    
    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (Source Destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        
        if (u < vertices && v < vertices) {
            g.addEdge(u, v);
        } else {
            cout << "Error: Vertex index out of range (0 to " << vertices - 1 << ")" << endl;
            i--; 
        }
    }

    cout << "\nEnter starting vertex for DFS: ";
    cin >> source;

    if (source >= 0 && source < vertices) {
        g.DFS(source);
    } else {
        cout << "Invalid starting vertex." << endl;
    }

    return 0;
}
