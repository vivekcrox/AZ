#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define int long long

// smallest arr[i] + arr[j]; s.t. arr[i] + arr[j] >= x
signed main() {

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // idea: x-arr[j]; just >= value past m mili thi kya, usme se best lelo
    set<int> st;
    int best = 1e9;
    for(int j=0; j<n; j++) {
        int vali = x - arr[j];  // vali >= x - arr[j]; check krna h

        auto it = st.lower_bound(vali);
        
        if(it != st.end()) {
            best = min(best, *it + arr[j]);
        }
        
        st.insert(arr[j]);
    }
    
    cout << best << endl;

    return 0;
}