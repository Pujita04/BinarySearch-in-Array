//binary search program
//array is sorted in non- decreasing order

#include<iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key) {

    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //moving to right side of array
        else if(arr[mid] < key){
            start = mid + 1;
        }

        //condition is arr[mid] > key then move to the left side of array
        else{
            end = mid-1; 
        }

        //updating the mid point of array after every iteration 
        mid = start + (end - start)/2;
    }

    return -1;
}

int main() {
    
    int even[6] = {2, 3, 5, 19, 27, 30};

    int odd[5] = {2, 7, 11, 23, 27};

    int evenIndex = BinarySearch(even, 6, 27);
    cout << "The index of 27 is : " << evenIndex << endl;

    int oddIndex = BinarySearch(odd, 5, 7);
    cout << "The index of 7 is : " << oddIndex << endl;

    return 0;
}