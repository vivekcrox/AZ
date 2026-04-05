/*
Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.
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
        for(int i = 0; i < n; i++) cin >> arr[i];

        // Step 1: count total distinct elements
        unordered_set<int> st(arr.begin(), arr.end());
        int totalDistinct = st.size();

        unordered_map<int,int> mp;
        int i = 0;
        int ans = n;  // max possible

        for(int j = 0; j < n; j++) {
            mp[arr[j]]++;

            // Step 2: shrink window when valid
            while(mp.size() == totalDistinct) {
                ans = min(ans, j - i + 1);

                mp[arr[i]]--;
                if(mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }
                i++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}