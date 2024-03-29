https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>& grid,
    vector<pair<int,int>&vec, int row0, int col0 ){
      vis[row][col] = 1;
      vec.push_back({row - row0, col - col0}); // needed base coordinates for subtracting
      int n = grid.size();
      int m = grid[0].size();
      int delrow[] = {-1, 0, +1, 0};
      int delcol[] = {0, -1, 0, 1};
      
      //check for top bottom left right
      for(int i = 0; i< 4; i++){
          int nrow = row + delrow[i];
          int ncol = col + delcol[i];
          //check for valid coorninates and unvisited 1's
          if(nrow>=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
              dfs(nrow, ncol, vis, grid, vec, row0, col0);
          }
          
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                  vector<pair<int,int>>vec; //list of 1,s coordinates created
                  dfs(i, j, grid, vis, vec, i, j);
                  st.insert(vec);
               }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
