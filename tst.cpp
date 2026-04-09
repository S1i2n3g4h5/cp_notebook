#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b) for(int i = a; i < b; i++)
#define ll long long
#define ld long double

const bool multipleTestCases = false;

int recur(vector<int>& a, int n, vector<int>::iterator i){
    if (i == a.begin())return -1;
    if ((*i) == n) return(i-a.begin());
    return recur(a,n,i-1);
}


bool solve(){
    
    vector<int> arr = {6,8,9,4,6};

    int o = recur(arr, 6, arr.end());
    cout << o;

    return 1;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    multipleTestCases and cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
