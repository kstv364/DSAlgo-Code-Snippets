void BFS(vector<int> g[], int i, int visited[], vector<int> &res
{
    queue<int> q;
    q.push(i);
    res.push_back(i);
    visited[i] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto it = g[u].begin(); it != g[u].end(); it++)
        {
            if (visited[*it] == 0) {
                q.push(*it);
                visited[*it] = 1;
                res.push_back(*it);
            }

        }
    }
}

// somwhow fails if you try to mark after popping
// need to mark while pushing