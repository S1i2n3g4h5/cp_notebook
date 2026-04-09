// /*
//   Competing against Myself  
//   [zoASHro]
// */
// #pragma GCC optimize("O2")  
// #include <bits/stdc++.h>
// using namespace std;

// template <typename... Args>
// void print(Args&&... args){
//    ((cout << args << " "), ...); cout << "\n";
// }
// #define all(x)(x).begin(),(x).end()
// #define rall(x)(x).rbegin(),(x).rend()
// #define pb push_back
// #define f(i, a, b)          for(int i = a; i < b; i++)
// #define debug(x) cout<<#x<<" = "<<x<<"\n"
// typedef long long ll;
// typedef pair<ll,ll> pll;
// typedef vector<ll> vll;



// // ______________________________________________________
// long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
//   long long result = 1; 
//   while(power > 0){
//     if(power & 1){result =(result*base) % MOD;}
//     base =(base*base) % MOD;
//     power = power>>1ll;
//   } 
//   return result;
// }


// const bool multipleTestCases = 1; 

// void solve(){
//   /*
//     gcd(a,b) must be divisor of n
//     a+b=n  then b=n-a;

//     so for gcd(a,n-a) is same as gcd(a,n);

//     so to get the min LCM, we try to increase the gap between a,b
//     like if they are multiples of each other then try to maximize it by removing the least prime numbe rpresent

//   */

//     ll n;cin>>n;


//     if(n%2==0){
//         print(n/2, n/2);
//         return;
//     }

//     int smp = -1;
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             smp=i;
//             break;
//         }
//     }


//     if(smp == -1){
//         // prime found
//         print(1,n-1);
//     }
//     else{
//         print(n/smp, n- n/smp);
//     }
    
// }


/*
# Problem Understanding

The problem requires finding the size of the largest subset of bulbs that maximizes the value of L for a given query C. The value of L is calculated as the sum of contributions of each bulb in the subset, where the contribution of each bulb is given by $a_i \cdot C - b_i$.

Key constraints and edge cases:

* $1 \le n \le 2 \cdot 10^5$
* $1 \le a_i \le 10^9$
* $1 \le b_i \le 10^9$
* $1 \le q \le 2 \cdot 10^5$
* $1 \le C \cdot 10^9$

Input:

* $n$: the number of bulbs
* $arr$: a list of pairs $(a_i, b_i)$ representing the bulbs
* $q$: the number of queries
* $C$: a list of query values

Output:

* The size of the largest subset of bulbs that maximizes the value of L for each query C

Subtle requirements or implicit constraints:

* The problem requires finding the largest subset, not just any subset that maximizes the value of L.
* The value of L is calculated as the sum of contributions of each bulb in the subset.

# Key Insights

Crucial observations that lead to the solution:

* The contribution of each bulb can be calculated as $a_i \cdot C - b_i$.
* The problem can be solved by sorting the bulbs based on their contributions for a given C.
* The largest subset that maximizes the value of L can be found by selecting all bulbs with positive contributions.
* The size of the largest subset is equal to the number of bulbs with positive contributions.

Patterns or properties being used:

* The problem uses the property that the sum of contributions of each bulb in the subset is maximized when all bulbs with positive contributions are selected.

Key algorithmic insights:

* The problem can be solved using a simple sorting approach.
* The time complexity of the solution is O(n log n) due to the sorting step.

Important realizations:

* The problem requires finding the largest subset, not just any subset that maximizes the value of L.
* The value of L is calculated as the sum of contributions of each bulb in the subset.

Critical examples or test cases:

* The example in the problem statement illustrates the calculation of the value of L for a given query C.

# Solution Strategy

Steps to solve this problem:

1. Read the input values $n$, $arr$, $q$, and $C$.
2. For each query C, calculate the contributions of each bulb as $a_i \cdot C - b_i$.
3. Sort the bulbs based on their contributions in descending order.
4. Find the point where the contributions become negative.
5. The size of the largest subset is equal to the number of bulbs with positive contributions.

Critical details:

* The bulbs should be sorted based on their contributions for a given C.
* The size of the largest subset is equal to the number of bulbs with positive contributions.

Optimizations or special cases to handle:

* The solution has a time complexity of O(n log n) due to the sorting step.
* The solution requires finding the largest subset, not just any subset that maximizes the value of L.

Here's the python solution:
```python
import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    arr = []
    for _ in range(n):
        a, b = map(int, input().split())
        arr.append((a, b))

    q = int(input())

    diff = []
    for i in range(n):
        diff.append((arr[i][0], arr[i][1], i))

    diff.sort(key=lambda x: x[0] - x[1])

    prefix_sum = [0] * (n + 1)
    for i in range(n):
        prefix_sum[i + 1] = prefix_sum[i] + diff[i][0] - diff[i][1]

    for _ in range(q):
        C = int(input())
        l = 0, h = n - 1
        while l < h:
            mid = (l + h + 1) // 2
            if diff[mid][0] * C - diff[mid][1] > 0:
                l = mid
            else:
                h = mid - 1

        if diff[l][0] * C - diff[l][1] > 0:
            print(l + 1)
        else:
            print(l)

if __name__ == "__main__":
    solve()
```

*/




// int main(){
//   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
//   int t = 1;
//   if(multipleTestCases) cin >> t;
//   while(t--){
//       solve();
//   }
//   return 0;
// }