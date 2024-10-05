class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> memory(m, vector<int>(m, -1));
        vector<vector<int>> current(m, vector<int>(m, -1));
        int maxi;
        memory[0][m-1] = grid[0][0] + grid[0][m-1];
        
        for (int i=1; i<n; i++) {
            for (int j1=0; j1<m; j1++) {
                for (int j2=0; j2<m; j2++) {
                    maxi = -1;
                    for (int d1=-1; d1<=1; d1++) {
                        for (int d2=-1; d2<=1; d2++) {
                            if (j1+d1>=0 && j1+d1<m && j2+d2>=0 && j2+d2<m) {
                                maxi = maxi > memory[j1+d1][j2+d2] ? maxi : memory[j1+d1][j2+d2];
                            }
                        }
                    }
                    
                    if (maxi == -1) current[j1][j2] = -1;
                    else if (j1 == j2) current[j1][j2] = maxi + grid[i][j1];
                    else current[j1][j2] = maxi + grid[i][j1] + grid[i][j2];
                }
            }
            memory = current;
        }
        
        int result = 0;
        for (int j1=0; j1<m; j1++) {
            for (int j2=0; j2<m; j2++) {
                result = result > current[j1][j2] ? result : current[j1][j2];
            }
        }
        
        return result;
    }
};
