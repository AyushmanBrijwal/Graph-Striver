#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //declare min heap
        vector<int>vis(V,0); //created vis arr and mark as 0 everyone
        pq.push({0,0}); //store wt and node, (no need for parent we don't need mst as o/p)
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1) continue; //if its already vis just go ahead
            vis[node] = 1; //mark it vis if not only when we add to mst
            sum += wt; //else it will be part of mst
            //get all adj nodes
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode]){
                    pq.push({edW, adjNode}); //only add in pq don't mark as vis
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
