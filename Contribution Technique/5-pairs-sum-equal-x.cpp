#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define int long long

// arr[i] + arr[j] = x ; cnt such pairs
signed main() {

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // idea: x-arr[j] kitni baar past m mil chuka h, utne pairs ban jayenge 
    map<int,int> mp;
    int sum = 0;
    for(int j=0; j<n; j++) {
        int vali = x - arr[j];

        sum += mp[vali];
        mp[arr[j]]++;
    }
    
    cout << sum << endl;

    return 0;
}