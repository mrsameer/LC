#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())

#define for0(i, n) for (int i = 0; i < n; ++i)
#define for1(i, n) for (int i = 1; i < n - 1; ++i)

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // include the 1 and m in hFences as we need to find all possible heights
        hFences.pb(1);
        hFences.pb(m);

        // include the 1 and n in vFences as we need to find all possible widths
        vFences.pb(1);
        vFences.pb(n);

        unordered_set<int> all_widths;
        // store all possible widths in the set all_widths
        for0(i, hFences.size()) {
            for0(j, hFences.size()) {
                if (i != j) {
                    all_widths.insert(abs(hFences[i] - hFences[j]));
                }
            }
        }

        long ans = -1;
        // now iterate over each possible height and see if that is present in all_widths and update ans
        for0(i, vFences.size()) {
            for0(j, vFences.size()) {
                if (i != j) {
                    int height = abs(vFences[i] - vFences[j]);
                    if (all_widths.find(height) != all_widths.end()) {
                        ans = max(ans, static_cast<long>(height));
                    }
                }
            }
        }

        return (ans == -1) ? -1 : static_cast<int>((ans * ans) % 1000000007);
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> hFences = {2, 4};
    vector<int> vFences = {2, 4};
    int result = sol.maximizeSquareArea(4, 4, hFences, vFences);
    cout << "Result: " << result << endl;

    return 0;
}
