#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N]; //create graph or adj list of it
        for(auto it: edges){ //traverse across all edges
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]); //these both cases are for undirected graph
        }
        
        int dis[N];
        for(int i=0; i<N; i++){
            dis[i] = 1e9;
        }
        dis[src] = 0; //dist of src is always 0
        
        queue<int>q;
        q.push(src); //push src node in queue
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(dis[node] + 1 < dis[it]){
                    dis[it] = dis[node] + 1;
                    q.push(it);
                }
            }
        }
        
        vector<int>ans(N, -1);
        for(int i =0; i<N; i++){
            if(dis[i] != 1e9){
                ans[i] = dis[i];
            }
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
