//finding index of peak element in a mountain array using binary search

#include<iostream>
using namespace std;

int peakInMountin(int arr[], int n) {

    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;

    while(start < end) {

        if(arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        }

        else {
            end = mid;
        }

        mid = start + (end - start)/2;
    }

    return start;
    //return arr[start] to find value of peak element
}


int main() {

    int arr[8] = {1, 2, 3, 4, 5, 3, 2, 1};

    int peak_element = peakInMountin(arr, 8);
    cout << "The peak element in mountain array is at index : " << peak_element << endl;

    return 0;
}