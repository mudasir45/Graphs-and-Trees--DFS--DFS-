//https://leetcode.com/problems/island-perimeter/description/

#include<iostream>
using namespace std;
  int islandPerimeter(vector<vector<int>>& grid) {
        int n, m, ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                ans += 4;
                
                    
                
                if(i+1 < n && grid[i+1][j] ==1)
                   { ans--;}
                if(i-1 >=0 && grid[i-1][j]==1)
                    {ans--;}
                if(j+1 < m && grid[i][j+1])
                   { ans--;}
                if(j-1 >=0 && grid[i][j-1])
                    {ans--;}
                }
            }
        }
        return ans;
    }

int main()
{
	
	
	return 0;
}