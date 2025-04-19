#include <iostream>
using namespace std;

const int MAX = 100;
char x[MAX];

// liet ke chuoi nhi phan do dai n
void binary_backtrack(int i, int n) {
    if (i == n) {
        for (int j = 0; j < n; ++j) cout << x[j];
        cout << endl;
        return;
    }

    x[i] = '0';
    binary_backtrack(i + 1, n);

    x[i] = '1';
    binary_backtrack(i + 1, n);
}

// liet ke chuoi a va b do dai n
void ab_backtrack(int i, int n) {
    if (i == n) {
        for (int j = 0; j < n; ++j) cout << x[j];
        cout << endl;
        return;
    }

    x[i] = 'a';
    ab_backtrack(i + 1, n);

    x[i] = 'b';
    ab_backtrack(i + 1, n);
}

int main() {
    int n;
    cout << "Nhap do dai n > 0: ";
    cin >> n;

    cout << "\nCac chuoi nhi phan do dai " << n << ":\n";
    binary_backtrack(0, n);

    cout << "\nCac chuoi 'a' va 'b' do dai " << n << " (tu dien):\n";
    ab_backtrack(0, n);

    return 0;
}

