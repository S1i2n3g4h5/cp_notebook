#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>


void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}


#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double



const bool multipleTestCases = 1;


void solve(){       

    string s;cin>>s;

    
    int cnt0 = 0, cnt1 = 0;
    for(char c : s){
        if (c == '0') cnt0++;
        else cnt1++;
    }

    f(i,0,s.size()){
        if (s[i] == '0') {
            if (cnt1 > 0){
                cnt1--;
            } 
            else{
                print(s.size() - i);
                return;
            }
        } 
        else{ 
            
            if (cnt0>0){
                cnt0--;
            } 
            else{
                print(s.size() - i);
                return;
            }
        }
    }
    print(0);     

    /*

    Given a sorted array of integers (not necessarily distinct) A and an integer B, find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B.

Since the number of such pairs can be very large, return number of such pairs modulo (109 + 7).



Problem Constraints

1 <= |A| <= 100000

1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format

The first argument given is the integer array A.

The second argument given is integer B.
write cpp code    int Solution::solve(vector<int> &A, int B) {
    ll count = 0;
    int n = A.size();
    unordered_map<int, int> freq;
    for (int x : A) {
        freq[x]++;
    }

    for (int x : A) {
        int target = B - x;
        if (freq.count(target)) {
            if (target == x) {
                count = (count + (ll)freq[target] * (freq[target] - 1)) % 1000000007;
            } else {
                count = (count + (ll)freq[target]) % 1000000007;
            }
        }
    }
    return count / 2;
}




}*/


int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
