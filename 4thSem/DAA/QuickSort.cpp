#include <iostream>

using namespace std;

int partition(int arr[], int p, int r) {
    int i = r+1;
    for(int j = r; j >= p+1; j--) {
        if(arr[j] <= arr[p]) {
            i--;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i-1], arr[p]);
    return i-1;
}

void QuickSort(int arr[], int p, int r) {
    if(p < r) {
        int q = partition(arr, p, r);
        QuickSort(arr, p, q-1);
        QuickSort(arr, q+1, r);
    }
}

void Display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}
int main() {
    int A[] = {1,3,2,5,4,6,7,8};
    Display(A, 8);
    QuickSort(A, 0, 7);
    Display(A, 8);
    return 0;
}