

#include <bits/stdc++.h>
using namespace std;

void findLargestAndSecondLargest(int arr*, int n, int &largest, int &secondLargest) {
    largest = secondLargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
}

int main() {
    int arr[] = {5, 3, 9, 1, 6, 7, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest, secondLargest;
    findLargestAndSecondLargest(arr, n, largest, secondLargest);

    if (secondLargest == INT_MIN) {
        cout << "There is no second largest element in the array." << endl;
    } else {
        cout << "The largest element in the array is: " << largest << endl;
        cout << "The second largest element in the array is: " << secondLargest << endl;
    }

    return 0;
}
