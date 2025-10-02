#include <iostream>
using namespace std;

void print(int matrix[][100], int m, int n) {
    cout << "\nMatrix is:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    int matrix[100][100]; 

    cout << "Enter values:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    print(matrix, m, n);
}
