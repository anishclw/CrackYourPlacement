class Solution {
public:
void bfs(vector<vector<int>>& adj, int headID, vector<int>& informTime, int& maxTime) {
        queue<pair<int,int>> q;  // Queue to store pairs of employee ID and the time to inform them
        q.push({headID, 0});     // Start with the head of the company with time 0

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int v = temp.first;   // Current employee
            int time = temp.second; // Time taken to inform the current employee

            // Update the maximum time taken to inform any employee
            maxTime = max(time, maxTime);

            // Traverse through all the subordinates of the current employee
            for(int &emp: adj[v]) {
                // Push the subordinate into the queue with the updated time
                q.push({emp, time + informTime[v]});
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n); // Adjacency list to represent the company hierarchy

        // Build the adjacency list from the manager list
        for (int i = 0; i < manager.size(); i++) {
            int employee = i;
            int manager_e =  manager[i];

            if(manager_e != -1)
                adj[manager_e].push_back(employee);
        }
         int maxTime = 0;
         bfs(adj, headID, informTime, maxTime);
         return maxTime; 
    }
};