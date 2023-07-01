//finding the first and last occurrence of element in an sorted array
//using binary search 

#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int key) {

    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {

        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;  
        }

        else if(arr[mid] > key) {    //move to left side of an array
            end = mid - 1;
        }

        else {  //condition is arr[mid] < key     right side move 
            start = mid + 1;
        }

        mid = start + (end - start)/2;

    }

    return ans;
}

int lastOcc(int arr[], int n, int key) {

    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end) {

        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;  
        }

        else if(arr[mid] > key) {    //move to left side of an array
            end = mid - 1;
        }

        else {  //condition is arr[mid] < key     right side move 
            start = mid + 1;
        }

        mid = start + (end - start)/2;

    }

    return ans;
}

int main() {

    int arr[6] = {1,2,3,3,3,5};
    int first_occ = firstOcc(arr, 6, 3);
    cout << "The first occurrence of element is at index : " << first_occ << endl;

    int last_occ = lastOcc(arr, 6, 3);
    cout << "The last occurrence of element is at index : " << last_occ << endl;

    //if we need to find the total number of occurrence of element :

    int total = (last_occ - first_occ) + 1;
    cout << "The total number of occurrence of element is: " << total << endl;

    return 0;
}

