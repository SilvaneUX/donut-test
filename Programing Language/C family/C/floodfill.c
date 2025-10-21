void dfs(int i, int j, int m, int n, int** grid, int** visited, int srColor, int color) {
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (grid[i][j] != srColor || visited[i][j]) return;
    visited[i][j] = 1;
    grid[i][j] = color;
    dfs(i + 1, j, m, n, grid, visited, srColor, color);
    dfs(i - 1, j, m, n, grid, visited, srColor, color);
    dfs(i, j + 1, m, n, grid, visited, srColor, color);
    dfs(i, j - 1, m, n, grid, visited, srColor, color);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int m = imageSize;
    int n = imageColSize[0];
    int srColor = image[sr][sc];
    if (srColor == color) {
        *returnSize = m;
        *returnColumnSizes = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) (*returnColumnSizes)[i] = n;
        return image;
    }
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        visited[i] = (int*)calloc(n, sizeof(int));
    dfs(sr, sc, m, n, image, visited, srColor, color);
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = n;
    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited);
    return image;
}
