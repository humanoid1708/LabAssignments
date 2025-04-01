#include <iostream>
using namespace std;

int sack(int weights[], int profits[], int items, int capacity) {
    int core[items + 1][capacity + 1];

    for (int i = 0; i <= items; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                core[i][j] = 0;
            else if (weights[i - 1] <= j)
                core[i][j] = max(profits[i - 1] + core[i - 1][j - weights[i - 1]], core[i - 1][j]);
            else
                core[i][j] = core[i - 1][j];
        }
    }
    return core[items][capacity];
}

int main() {
    int n = 4;  
    int profits[] = {1, 2, 5, 6};
    int weights[] = {2, 3, 4, 5};
    int cap = 8;

    cout << "Maximum profit: " << sack(weights, profits, n, cap) << endl;
    return 0;
}