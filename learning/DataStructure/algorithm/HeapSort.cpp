#include <iostream>
using namespace std;

void builtHeap(int* arr, int n, int i) {
    int largest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    while (lchild < n) {
        if (arr[lchild] > arr[largest]) {
            largest = lchild;
        }
        if (rchild < n && arr[rchild] > arr[largest]) {
            largest = rchild;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
            lchild = 2 * i + 1;
            rchild = 2 * i + 2;
        } else {
            break;
        }
    }
}

void heapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        builtHeap(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        builtHeap(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}