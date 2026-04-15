#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> board, blocked;

bool safe(int r, int c) {
    for (int i = 0; i < r; i++)
        if (board[i][c]) return false;

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solve(int r) {
    if (r == n) return true;

    for (int c = 0; c < n; c++) {
        if (blocked[r][c]) continue;

        if (board[r][c] == 1) {
            if (!safe(r, c)) return false;
            return solve(r + 1);
        }
    }

    for (int c = 0; c < n; c++) {
        if (blocked[r][c] || board[r][c]) continue;

        if (safe(r, c)) {
            board[r][c] = 1;
            if (solve(r + 1)) return true;
            board[r][c] = 0;
        }
    }

    return solve(r + 1);
}

int main() {
    cin >> n;

    board.assign(n, vector<int>(n, 0));
    blocked.assign(n, vector<int>(n, 0));

    int b;
    cin >> b;
    while (b--) {
        int r, c;
        cin >> r >> c;
        blocked[r][c] = 1;
    }

    int k;
    cin >> k;
    while (k--) {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }

    if (solve(0)) cout << "YES\n";
    else cout << "NO\n";
}