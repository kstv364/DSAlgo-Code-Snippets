class Graph {
    int V; // No. of vertices'

    // Pointer to an array containing adjacency listsList
    list<int>* adj;

    // A function used by topologicalSort
    bool topologicalSortUtil(int v, int visited[], stack<int>& Stack);

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    vector<int> topologicalSort();

    bool hasCycle() {
        int* visited = new int[V];
        for (int i = 0; i < V; i++)
            visited[i] = 0;

        // Call the recursive helper function to store Topological
        // Sort starting from all vertices one by one
        bool possible = true;
        for (int i = 0; i < V; i++)
            if (visited[i] == 0)
                possible = possible and DFSUtil(i, visited);
        return !possible;
    }

    bool DFSUtil(int v, int visited[]) {
        visited[v] = 1;
        // Recur for all the vertices adjacent to this vertex
        bool possible = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (visited[*i] != 1)
                possible = possible and DFSUtil(*i, visited);
            else
                return false;

        visited[v] = 2;
        return possible;

    }
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
bool Graph::topologicalSortUtil(int v, int visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = 1;
    bool possible = true;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (visited[*i] == 0)
            possible = possible and topologicalSortUtil(*i, visited, Stack);
        else if (visited[*i] == 1)
            return false;

    // Push current vertex to stack which stores result
    visited[v] = 2;
    Stack.push(v);
    return possible;
}


vector<int> Graph::topologicalSort()
{
    stack<int> Stack;


    int* visited = new int[V];
    bool possible = true;
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++)
        if (visited[i] == 0)
            possible = possible and
                       topologicalSortUtil(i, visited, Stack);

    vector<int> ans;
    if (possible) {
        while (Stack.empty() == false) {
            ans.push_back(Stack.top());
            Stack.pop();
        }
    }
    return ans;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for (auto x : prerequisites) {
            g.addEdge(x[1], x[0]);
        }
        return g.topologicalSort();
    }

};


