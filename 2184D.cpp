#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // Since n = 2^d, find d
        int d = __builtin_ctzll(n);  // count trailing zeros = log2(n) for powers of 2
        
        // Key insight: count how many numbers need > k moves
        // For numbers 1 to n where n = 2^d
        // Answer follows a pattern based on k and d
        
        long long count = 0;
        
        // If k is very large, no number will need > k moves
        if (k >= d + d) {  // max moves for any number ≤ n is around 2*d
            cout << 0 << endl;
            continue;
        }
        
        // Count numbers that need > k moves
        // We count by iterating through possible move counts
        // Numbers needing exactly m moves form a pattern
        
        // For each number of moves m > k
        for (int m = k + 1; m <= 2 * d + 1; m++) {
            // Count how many numbers from 1 to n need exactly m moves
            // This requires combinatorial counting based on binary representation
            
            // A number with b bits and p ones needs (b-1) + p moves
            // So for m moves: we need b + p = m + 1
            
            for (int bits = 1; bits <= d + 1; bits++) {
                int ones = m - bits + 1;
                
                if (ones < 1 || ones > bits) continue;
                
                // Count b-bit numbers with p one-bits
                // First bit is always 1, so we choose (ones-1) from remaining (bits-1) positions
                
                if (bits == d + 1) {
                    // Special case: n itself
                    if (ones == 1) {  // n = 2^d has only 1 one-bit
                        int movesN = d + 1;  // n needs d+1 moves
                        if (movesN > k) count++;
                    }
                } else {
                    // Calculate C(bits-1, ones-1)
                    long long comb = 1;
                    int nC = bits - 1;
                    int kC = ones - 1;
                    
                    // Calculate combination
                    for (int i = 0; i < kC; i++) {
                        comb = comb * (nC - i) / (i + 1);
                        if (comb > n - count) break;  // Prevent overflow
                    }
                    
                    count += comb;
                }
                
                if (count >= n) {
                    count = n;
                    break;
                }
            }
            
            if (count >= n) break;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
