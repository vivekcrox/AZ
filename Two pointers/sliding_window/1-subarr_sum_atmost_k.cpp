#include<bits/stdc++.h>
using namespace std;

// Given an array of N integers, find the number of subarrays with a sum less than or equal to K

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        //
        int cnt = 0;
        int tail = 0;
        int curSum = 0;
        for(int head = 0; head < n; head++) {
            curSum += arr[head];
            while(curSum > k) {
                curSum -= arr[tail];
                tail++;
            }

            cnt += head - tail + 1;  // # subarr ending at head
        }
        cout << cnt << endl;
    }

    return 0;
}