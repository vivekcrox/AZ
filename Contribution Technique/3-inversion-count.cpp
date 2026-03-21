#include<iostream>
#include<vector>
using namespace std;

#define int long long

// i < j and arr[i] > arr[j]
// count such pairs in each subarr
signed main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // idea: count each inversion comes in how many subarr
    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
                sum += (i+1) * (n-j);
            }
        }
    }
    
    cout << sum << endl;

    return 0;
}