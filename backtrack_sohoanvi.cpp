#include <iostream>
using namespace std;

const int MAX = 10;
int x[MAX];         // mang luu hoan vi hien tai
bool used[MAX + 1]; // danh dau phan tu da dung

// backtrack liet ke hoan vi theo thu tu tu dien
void A2(int i, int n) {
    if (i == n) {
        for (int j = 0; j < n; ++j)
            cout << x[j] << " ";
        cout << endl;
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if (!used[j]) {
            x[i] = j;
            used[j] = true;
            A2(i + 1, n);
            used[j] = false; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Nhap so nguyen duong n (1 <= n <= 10): ";
    cin >> n;

    //reset mang used
    for (int i = 1; i <= n; ++i)
        used[i] = false;

    cout << "\nCac hoan vi cua tap S = {1, 2, ..., " << n << "} theo thu tu tu dien:\n";
    A2(0, n);

    return 0;
}

