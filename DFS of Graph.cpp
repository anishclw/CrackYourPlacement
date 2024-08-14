class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> adj[],vector<bool>&visited,vector<int>&ans)
    {
        visited[node]=1;
        ans.push_back(node);
        for(int j=0;j<adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
                dfs(adj[node][j],adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,0);
        vector<int> ans;
        dfs(0,adj,visited,ans);
        return ans;
    }
};