#include<bits/stdc++.h>
using namespace std;

//brute force ye hai ki sort the whole array and then joo bhi last elemnt hoga array mai vahi hoga answer T.C=O(nlogn)
int sortArr(vector<int>& a) {
    sort(a.begin(),arr.end());
    return arr[a.size()-1];
}
///more optimal T.C O(n) hai
int findLargestElement(int arr[], int n) {
    int largest = arr[0]; // Assume the first element is the largest initially    
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest)  largest = arr[i];
    }
    return largest;
} 
int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<findLargestElement(arr2);
   
    return 0;
}
