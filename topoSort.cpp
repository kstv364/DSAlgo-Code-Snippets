void DFSUtil(int visited[], vector<int> adj[], int u, stack<int> &s) {
    visited[u] = 1;
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
        if (!visited[*i])
            DFSUtil(visited, adj, *i, s);
    }
    visited[u] = 2;
    s.push(u);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    int visited[V];
    stack<int> S;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(visited, adj, i, S);
    }
    vector<int> v;
    while (!S.empty()) {
        v.push_back(S.top()); S.pop();
    }
    return v;
}
