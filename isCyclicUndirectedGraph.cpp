bool DFSUtil(int visited[], vector<int> adj[], int src, int frm) {
    visited[src] = 1;
    bool ans = false;
    for (auto i = adj[src].begin(); i != adj[src].end(); i++ ) {
        if (visited[*i] == 0) {
            if (DFSUtil(visited, adj, *i, src))
                return true;
        }
        else if (*i != frm and visited[*i] != 0) {
            return true;
        }

    }
    visited[src] = 2;
    return ans;
}
bool isCyclic(vector<int> adj[], int V)
{
    // Your code here
    int visited[V];
    memset(visited, 0, sizeof(visited));
    bool ans = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            if (DFSUtil(visited, adj, i, -1))
                return true;
    }
    return ans;

}