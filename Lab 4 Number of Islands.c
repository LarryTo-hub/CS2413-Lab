void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    // Boundary and water checks
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0')
        return;

    grid[i][j] = '0';  // Mark the land as visited

    // Explore neighbors (up, down, left, right)
    dfs(grid, gridSize, gridColSize, i - 1, j); // up
    dfs(grid, gridSize, gridColSize, i + 1, j); // down
    dfs(grid, gridSize, gridColSize, i, j - 1); // left
    dfs(grid, gridSize, gridColSize, i, j + 1); // right
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (!grid || gridSize == 0 || gridColSize == NULL) return 0;

    int count = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[i]; ++j) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize, i, j);  // Sink the entire island
            }
        }
    }
    return count;
}
