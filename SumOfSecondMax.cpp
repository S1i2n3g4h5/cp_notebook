/*
  Competing against Myself  
  [zoASHro]
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pge(n), nge(n);
    vector<int> st;

    // Previous Greater Element
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        pge[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    st.clear();

    // Next Greater Element
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        nge[i] = st.empty() ? n : st.back();
        st.push_back(i);
    }

    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        long long val = a[i];
        int l1 = pge[i];
        int r1 = nge[i];

        if (l1 != -1) {
            int l2 = pge[l1];
            total_sum += val * (long long)(l1 - l2) * (long long)(r1 - i);
        }

        if (r1 != n) {
            int r2 = nge[r1];
            total_sum += val * (long long)(i - l1) * (long long)(r2 - r1);
        }
    }

    cout << total_sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}