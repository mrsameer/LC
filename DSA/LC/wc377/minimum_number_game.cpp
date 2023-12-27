#include <bits/stdc++.h>
using namespace std;

#define int long long // Use 'int' or 'long long' as per the problem requirements

// Shortcut for commonly used data types
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

const int INF = LLONG_MAX;
const int MOD = 1e9 + 7;

// Shortcut for loops
#define for0(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)

// Debugging macros
#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(arr, n) for (int i = 0; i < n; ++i) cout << arr[i] << " "; cout << endl;

vi numberGame(vi& nums) {
    priority_queue<int> pq;
    for (int num : nums) {
        pq.push(-num);  // Negate the values to create a max-heap
    }


    vi result;
    while (pq.size() >= 2) {
        int a = -pq.top(); // Negate again to get the original values
        pq.pop();
        int b = -pq.top();
        pq.pop();

        result.pb(b);
        result.pb(a);
    }

    return result;
}

void solve() {
    int n;
    cin >> n; // Input the number of elements in the array

    vi arr(n);
    for0(i, n) {
        cin >> arr[i];
    }

    vi result = numberGame(arr);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // Number of test cases, change as needed
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
