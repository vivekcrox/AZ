/*
Given an array of N integers and an integer D. Consider all subarrays with length 
D, the penalty of the subarray is the number of distinct elements present in the subarray. Find a subarray of length 
D with minimum penalty. Print the minimum penalty.
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;

        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        //
        int i=0, j=0;
        int ans = 1e9;

        map<int,int> mp;

        while(j < n) {
            mp[arr[j]]++;

            if(j-i+1 > d) {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }

            if(j-i+1 == d) {
                ans = min(ans, (long long)mp.size());
            }
            
            j++;
        }
        cout << ans << endl;
    }

    return 0;
}