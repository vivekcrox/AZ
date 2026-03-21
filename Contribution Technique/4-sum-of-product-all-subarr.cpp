#include<iostream>
#include<vector>
using namespace std;

#define int long long

signed main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // idea: for ith element, prev ans m ith ko include + ith element
    int total = 0;
    int curans = 0;
    for(int i=0; i<n; i++) {
        curans = curans * arr[i] + arr[i];   // for sum of all subarr: curans = curans + i * arr[i] + arr[i]
        total += curans;
    }
    
    cout << total << endl;

    return 0;
}