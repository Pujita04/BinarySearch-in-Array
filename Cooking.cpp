#include <bits/stdc++.h> 

bool isPossible(vector<int> &rank, int n, int m, int mid) {

    int dishes = 0;

    for(int i=0; i<n; i++) {
        int timeSum = 0;
        
        for(int j = 1; (timeSum <= mid); j++) {
            timeSum = timeSum+ (rank[i]*j);
            dishes++;

            if(timeSum > mid) {
                dishes--;
            }
            if(dishes >= m) {
                return true;
            }
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(), rank.end());
    int s = 0;
    int n = rank.size();
    int maxi = rank[n-1];
    int e = maxi *(m*(m+1)/2);
   
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(isPossible(rank, n, m, mid)) {
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
