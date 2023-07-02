#include<iostream>
using namespace std;

bool isPossible(int time[],int n,int m,int mid) {
	int dayCount = 1;
	int timeSum = 0;

	for(int i=0; i<m; i++) {
		if(timeSum+ time[i] <= mid) {
			timeSum+=time[i];
		}
		else {
			dayCount++;
			if(dayCount>n || time[i] > mid){
				return false;
			}
			timeSum = time[i];
		}
	}
	return true;
}


long long ayushGivesNinjatest(int n, int m, int time[]) 
{	
	int s = 0;
	int sum = 0;
	for(int i= 0; i<m; i++) {
		sum = sum + time[i];
	}
	int e = sum;
	int mid = s + (e - s)/2;
	int ans = -1;

	while(s <= e) {
		if(isPossible(time,n,m,mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
		mid = s + (e - s)/2;
	}
	return ans;
}


int main() {

    int n = 4;
    int m = 7;
    int time[7] = {2, 2, 3, 3, 4, 4, 1};

    int answer = ayushGivesNinjatest(n, m, time);
    cout << "The answer is : " << answer << endl;

    return 0;
}