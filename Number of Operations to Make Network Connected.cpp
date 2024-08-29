class Solution {
public:
    void dfs(int node, vector<int> adj[],vector<int> &vis) {
        vis[node] = 1;
        for(int child:adj[node]) {
            if(!vis[child]) {
                dfs(child,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(n-1>m) return -1;
        int connected = 0;
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                connected++;
                dfs(i,adj,vis);
            }
        }
        return connected-1;
    }
};