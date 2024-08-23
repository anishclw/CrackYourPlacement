class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
   // stack<int> s;
    //     vector<bool> visited(V,false);
    //     for(int i=0;i<V;i++){
    //         if(!visited[i])
    //             dfs(i,adj,visited,s);
                
    //     }
        
    //     vector<int> ans;
    //     while(!s.empty()){
    //         ans.push_back(s.top());
    //         s.pop();
    //     }
    //     return ans;
 
    vector<int> ans;
    vector<int> inD(V,0);
    
    for(int i=0;i<V;i++){
        for(auto z:adj[i])
            inD[z]++;
        
    }
    
    
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inD[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        auto z=q.front();
        q.pop();
        
        ans.push_back(z);
        
        for(auto xx:adj[z]){
            inD[xx]--;
            if(inD[xx]==0)
                q.push(xx);
            
        }
        
    }
    
    return ans;
    
}

};