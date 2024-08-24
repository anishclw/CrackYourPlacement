class Solution {
  public:
  bool CycleDFS(int src,int parent, vector<int> adj[],vector<int> Vis){
    
    Vis[src] = 1;
    
    for(auto it:adj[src]){
        if(!Vis[it]) {return CycleDFS(it,src,adj,Vis);}
        else if(it!=parent) return 1;
    }
    return 0;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> Vis (V,0);
        bool isCycle = 0;
        for(int i=0;i<V;i++){
            if(!Vis[i]){
             isCycle = CycleDFS(i,-1,adj,Vis);
            }
            if(isCycle) return 1;
        }
        return 0;
    }
};