/*
Given an array  A of  N integers and an integer target, 
find three integers in A such that the sum is closest to the target (absolute value of (sum−target) is minimum). 
Print the minimum absolute value of (sum−target). You cannot select an index more than once. All three indexes should be distinct.
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    int t;
    cin >> t;
    while(t--) {
        int n, target;
        cin >> n >> target;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        int ans =  LLONG_MAX;

        sort(begin(arr), end(arr));

        for(int k=0; k<n; k++){
            int i = k+1;
            int j = n-1;
            
            while(i < j){
                int sum = arr[k] + arr[i] + arr[j];

                ans = min(ans, abs(sum - target));

                if(sum > target)
                    j--;
                else
                    i++;
            }

        }
        cout << ans << endl;
    }

    return 0;
}