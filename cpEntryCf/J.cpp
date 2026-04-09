#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    map<int, int> left_counts;
    map<int, int> right_counts;
    vector<int> colors(n);

    for (int i = 0; i < l; ++i) {
        cin >> colors[i];
        left_counts[colors[i]]++;
    }

    for (int i = l; i < n; ++i) {
        cin >> colors[i];
        right_counts[colors[i]]++;
    }
    
    // Read all inputs first if needed, but the current input reading is fine.

    int cost = 0;

    // 1. Adjust counts by forming matching pairs of same color, opposite side.
    for (auto const& [color, count_l] : map<int, int>(left_counts)) {
        if (right_counts.count(color)) {
            int common = min(count_l, right_counts[color]);
            left_counts[color] -= common;
            right_counts[color] -= common;
        }
    }
    // Note: The second loop from the previous code is redundant if the first loop covers all colors present in the left_counts map.
    // The maps now contain only the counts of *unmatched* socks.

    // 2. Count the remaining socks on each side
    int remaining_l = 0;
    for (auto const& [color, count] : left_counts) {
        remaining_l += count;
    }
    int remaining_r = 0;
    for (auto const& [color, count] : right_counts) {
        remaining_r += count;
    }

    // 3. Use same-side "turn" operations to balance the sides efficiently.
    // Prioritize using same-color double socks (count / 2) to match the other side.
    if (remaining_l > remaining_r) {
        int diff_to_balance = (remaining_l - remaining_r) / 2;
        for (auto const& [color, count] : map<int, int>(left_counts)) {
            int turnable = count / 2; // Number of same-color pairs we can convert
            int use_turns = min(turnable, diff_to_balance);
            cost += use_turns;
            diff_to_balance -= use_turns;
            // No need to update the maps here if we just use the final simplified cost calculation below
            if (diff_to_balance == 0) break;
        }
    } else if (remaining_r > remaining_l) {
        int diff_to_balance = (remaining_r - remaining_l) / 2;
        for (auto const& [color, count] : map<int, int>(right_counts)) {
            int turnable = count / 2;
            int use_turns = min(turnable, diff_to_balance);
            cost += use_turns;
            diff_to_balance -= use_turns;
            if (diff_to_balance == 0) break;
        }
    }

    // 4. The sides are now effectively balanced in number by the used turns.
    // The remaining cost is the number of socks that must be recolored.
    // The most simplified final calculation works after step 1:
    // Total cost = (abs(remaining_l - remaining_r) / 2) + min(remaining_l, remaining_r)
    // The logic in step 3 already accounted for the first part. We just need the second part.

    cost += min(remaining_l, remaining_r);

    cout << cost << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
