#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 20;
int board[MAX][MAX];
//buoc di cua con ma
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

bool knightTour(int x, int y, int step) {
    board[x][y] = step;
    if (step == n * n - 1)
        return true;

    for (int k = 0; k < 8; ++k) {
        int nextX = x + dx[k];
        int nextY = y + dy[k];
        if (isValid(nextX, nextY)) {
            if (knightTour(nextX, nextY, step + 1))
                return true;
        }
    }

    board[x][y] = -1; // backtrack
    return false;
}

void printBoard() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << setw(3) << board[i][j];
        cout << endl;
    }
}

int main() {
    cout << "Nhap kich thuoc ban co n x n (n <= 10 de xem ket qua de dang): ";
    cin >> n;

    // Khoi tao ban co
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            board[i][j] = -1;

    // Bat dau tu (0, 0)
    if (knightTour(0, 0, 0)) {
        cout << "\nTim duoc phuong an di tuan:\n";
        printBoard();
    } else {
        cout << "\nKhong tim duoc phuong an di tuan.\n";
    }

    return 0;
}

