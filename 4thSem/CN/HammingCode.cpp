#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void HammingCode(string input) {
    int m = input.length();
    int r = 0;
    
    while (pow(2, r) < m + r + 1) {
        r++;
    }
    cout << "No. of bits in input: " << m << endl;
    cout << "No. of redundant bits to be added: " << r << endl;
    
    int tl = m + r;
    vector<char> code(tl, '0');
    int j = 0;
    
    for (int i = 0; i < tl; i++) {
        if ((i + 1) == pow(2, j)) j++;
        else code[i] = input[--m];
    }
    
    for (int i = 0; i < r; i++) {
        int PI = pow(2, i) - 1;
        int parity = 0;
        
        for (int k = PI; k < tl; k += 2 * (PI + 1)) {
            for (int l = k; l < k + (PI + 1) && l < tl; l++) {
                if (code[l] == '1') {
                    parity ^= 1;
                }
            }
        }
        code[PI] = (parity == 1) ? '1' : '0';
    }
    
    cout << "Final Hamming Code: ";
    for (char c : code) {
        cout << c;
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter binary input: ";
    cin >> input;
    
    HammingCode(input);
    return 0;
}
