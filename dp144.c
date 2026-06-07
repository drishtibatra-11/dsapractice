#include <stdio.h>
#include <string.h>

#define N 50

int grid[N][N];
int dp[N][N][N];
int n;

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int r1, int c1, int r2) {

    int c2 = r1 + c1 - r2;

    if (r1 >= n || c1 >= n ||
        r2 >= n || c2 >= n)
        return -1000000;

    if (grid[r1][c1] == -1 ||
        grid[r2][c2] == -1)
        return -1000000;

    if (r1 == n - 1 &&
        c1 == n - 1)
        return grid[r1][c1];

    if (dp[r1][c1][r2] != -1)
        return dp[r1][c1][r2];

    int cherries = 0;

    if (r1 == r2 && c1 == c2)
        cherries += grid[r1][c1];
    else
        cherries += grid[r1][c1] +
                    grid[r2][c2];

    int best = max(
        max(
            solve(r1 + 1, c1, r2 + 1),
            solve(r1 + 1, c1, r2)
        ),
        max(
            solve(r1, c1 + 1, r2 + 1),
            solve(r1, c1 + 1, r2)
        )
    );

    cherries += best;

    return dp[r1][c1][r2] = cherries;
}

int cherryPickup() {

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, 0);

    return ans < 0 ? 0 : ans;
}

int main() {

    n = 3;

    int temp[3][3] = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1,  1}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = temp[i][j];

    printf("Maximum Cherries = %d\n",
           cherryPickup());

    return 0;
}