//painter's partition problem

#include<iostream>
using namespace std;

bool isPossible(int boards[], int n, int k, int mid) {

    int painterCount = 1;
    int timeSum = 0;

    for(int i=0; i<n; i++) {
        if(timeSum + boards[i] <= mid) {
            timeSum += boards[i];
        }

        else {
            painterCount++;
            if(painterCount > k || boards[i] > mid) {
                return false;
            }

            timeSum = boards[i];
        }
    }
    return true;
}

int minimumTime(int boards[], int n, int k) {

    int s = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += boards[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e) {

        if (isPossible(boards, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        }

        else {
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int main() {

    int boards[4] = {10, 20, 30, 40};
    int k = 2;

    int answer = minimumTime(boards, 4, k);

    cout << "The answer is : " << answer << endl;

}