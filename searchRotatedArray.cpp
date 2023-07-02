//find the given key element in a rotated sorted array

#include<iostream>
using namespace std;

//find the pivot element to select the path: right or left
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

//to search the element in given path
int BinarySearch(int arr[], int start, int end, int key) {

    int s = start;
    int e = end;

    int mid = s + (e - s)/2;

    while(s <= e) {

        if(arr[mid] == key) {
            return mid;
        }

        //moving to right side of array
        else if(arr[mid] < key){
            s = mid + 1;
        }

        //condition is arr[mid] > key then move to the left side of array
        else{
            e = mid-1; 
        }

        //updating the mid point of array after every iteration 
        mid = s + (e - s)/2;
    }

    return -1;
}

//to find the position of element 
int findPosition(int arr[], int n, int key) {
    int pivot = findPivot(arr, n);

    if(key >= arr[pivot] && key <= arr[n-1]) {
        
        return(BinarySearch(arr, pivot, n-1, key));
    }

    else {
        return(BinarySearch(arr, 0, pivot-1, key));
    }
}


int main() {

    int arr[5] = {3, 7, 9, 1, 2};

    int keyIndex = findPosition(arr, 5, 9);
    cout << "The key element is present at the index : " << keyIndex << endl;


    return 0;
}