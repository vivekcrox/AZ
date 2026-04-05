#include<iostream>
using namespace std;

#define int long long

//1. Count subarray having distinct cnt <= k
/* 
9 2
0 1 0 1 0 0 1 1 0
ans = 5
*/

int freq[100100];
int distcnt = 0;

void insert(int x) {
    if(freq[x] == 0) {
        distcnt++;
    }
    freq[x]++;
}

void erase(int x) {
    freq[x]--;
    if(freq[x] == 0) {
        distcnt--;
    }
}


signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //

    int tail = 0, head = -1;

    int ans = 0;
    while(tail < n) {

        while((head+1 < n) && (freq[arr[head+1]] > 0 || distcnt < k)) {
            head++;
            // ds change
            insert(arr[head]);
        }

        // update ans
        ans += head-tail+1;  // cnt all subarr starting on tail to head

        // tail++
        if(tail <= head) {
            erase(arr[tail]);
            tail++;
        } else {
            tail++;;
            head = tail-1;
        }
    }

    cout << ans << endl;


    return 0;
}

// 2. find subarr == k distinct 
// Count subarray distinct cnt <= k - Count subarray having distinct cnt <= (k-1)

/* 
3. Find the shortest subarr having >= k distinct element.
--> think of finding longest subarr, <k distinct element
if head + 1 exists,
then ans = min(ans, (head-tail+1) + 1)

; as <k mein + 1 krne pe >=k distinct element dega.
*/