//finding pivot element in rotated sorted array

#include<iostream>
using namespace std;

int findPivot(int arr[], int n) {
    
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;

    while(start < end) {

        if(arr[mid] >= arr[start]) {
            start = mid + 1;
        }

        else {  //condition is arr[mid] < arr[start]
            end = mid;
        }

        mid = start + (end - start)/2;
    }
    return start;   //end could also be return
}


int main() {

    int arr[5] = {3, 7, 9, 1, 2};

    int pivotIndex = findPivot(arr, 5);
    cout << "The index of pivot element is : " << pivotIndex << endl;

    return 0;
}