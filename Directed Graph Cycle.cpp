class Solution {
  public:
    //using DFS.
    
    bool checkCycleDFS(int node , unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,vector<int> adj[])
   { 
       visited[node ]=true;
       dfsVisited[node]=true;
       
       for(auto nbr:adj[node])
       {
           if(!visited[nbr])
           {
               bool cycledetect=checkCycleDFS(nbr,visited,dfsVisited,adj);
               if(cycledetect)
               {
                   return true;
               }
           }
            else if(dfsVisited[nbr])
            {
                   //visited true;
                   return true;
            }
        }
           dfsVisited[node]=false;
           return false;
       }
    bool isCyclic(int V, vector<int> adj[]) {
        //create visited map
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        
        for(int i = 0 ; i <V ;i++)
        {
            if(!visited[i])
            {
                bool cycleFound = checkCycleDFS(i , visited , dfsVisited, adj);
                if(cycleFound)return true;
            }
        }
        return false;
    
       
    }
};