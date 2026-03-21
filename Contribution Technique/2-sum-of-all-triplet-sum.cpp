#include<iostream>
#include<vector>
using namespace std;

#define int long long

// sum arr[i] + arr[j] + arr[k] for all triplets, (i < j < k)
signed main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // idea: after choosing ith element, have (n-1) elements choose 2 to form triplet
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i] * (n-1)*(n-2)/2;
    }
    
    cout << sum << endl;

    return 0;
}