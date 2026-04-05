/*
You are given an array of N integers. Find the length of the longest subarray with distinct elements.
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        //
        map<int,int> mp;
        int i = 0, j = 0;

        int ans = 0;
        while(j < n) {
            mp[arr[j]]++;

            while(mp[arr[j]] > 1) {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }

            ans = max(ans, j-i+1);

            j++;
        }
        cout << ans << endl;
    }

    return 0;
}