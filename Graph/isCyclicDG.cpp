bool DFSUtil(int visited[], vector<int> adj[], int src) {
    visited[src] = 1;
    bool ans = false;
    for (auto i = adj[src].begin(); i != adj[src].end(); i++ ) {
        if (visited[*i] == 1)    return true;
        if (visited[*i] != 0) {
            ans = ans || DFSUtil(visited, adj, *i);
        }
    }
    visited[src] = 2;
    return ans;
}
bool isCyclic(int V, vector<int> adj[])
{
    int visited[V];
    memset(visited, 0, sizeof(visited));
    bool ans = false;
    for (int i = 0; i < V; i++) {
        ans = ans || DFSUtil(visited, adj, i);
    }
    return ans;

}