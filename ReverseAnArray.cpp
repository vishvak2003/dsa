#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    
    while (start < end) {
    
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move start forward and end backward
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    reverseArray(arr, n);
    
    cout << "Reversed array: ";
    printArray(arr, n);
    
    return 0;
}
