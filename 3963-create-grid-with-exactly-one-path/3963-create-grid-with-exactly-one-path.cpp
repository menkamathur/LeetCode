class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m , string(n, '#'));

        if(m == 1 || n == 1){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    grid[i][j] = '.';
                }
            }
            return grid;
        }
        for(int j = 0; j < n; j++){
            grid[0][j] = '.';
        }
        for(int i = 0; i < m ; i++){
            grid[i][n-1] = '.';
        }
        return grid;
    }
};