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

    // idea: each element contribute in a subarr -> (i+1)C1 * (n-i)C1 (starting line and ending line)
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i] * ((i+1) * (n-i));
    }
    
    cout << sum << endl;

    return 0;
}