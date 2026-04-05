#include<iostream>
using namespace std;

#define int long long

// Longest subarray having #0's <= k
/* 
9 2
0 1 0 1 0 0 1 1 0
ans = 5
*/
signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //

    int tail = 0, head = -1;

    int ans = 0;
    // ds
    int cnt0 = 0;
    while(tail < n) {

        while((head+1 < n) && (arr[head+1] == 1 || cnt0 < k)) {
            head++;
            // ds change
            if(arr[head] == 0) {
                cnt0++;
            }
        }

        // update ans
        ans = max(ans, head-tail+1);

        // tail++
        if(tail <= head) {
            if(arr[tail] == 0) {
                cnt0--;
            }
            tail++;
        } else {
            tail++;
            head = tail-1;
        }
    }

    cout << ans << endl;


    return 0;
}