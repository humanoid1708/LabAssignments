#include <iostream>
using namespace std;

bool place(int k, int i, int x[]) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

void nQueen(int k, int n, int x[]) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i, x)) {
            x[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            } else {
                nQueen(k + 1, n, x);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    int arr[n] = {0};
    nQueen(1, n, arr);
    return 0;
}