#include <stdio.h>

#define MAX 100   

int m, n;
int grid[MAX][MAX];


int check(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
        return 0;

    grid[x][y] = 0; 
    int count = 1;

    count += check(x+1, y);     
    count += check(x-1, y);     
    count += check(x, y+1);     
    count += check(x, y-1);     
    count += check(x+1, y+1);   
    count += check(x+1, y-1);   
    count += check(x-1, y+1);   
    count += check(x-1, y-1);   

    return count;
}

int maxArea() {
    int maxArea = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int area = check(i, j);
                if (area > maxArea)
                    maxArea = area;
            }
        }
    }
    return maxArea;
}

int main() {
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the matrix (0s and 1s):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = maxArea();
    printf("Maximum area of connected 1s = %d\n", result);

    return 0;
}
