#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b) for(int i = a; i < b; i++)
#define ll long long

const bool multipleTestCases = 1;

void solve(){
    /*
        maximize the permutation
        wnt largst valto appear 1st
                
        iif p[i] != n - i, 1st pos to fix
        
        rev segment [i, j] 
            this puts (n - i at index i.

                Since this is the first mismatch, this operation yields the lexicographically largest result.
    
    */

    int n;cin>>n;
    vector<int> p(n),pos(n+1);
    f(i,0,n){
        cin>>p[i];
        pos[p[i]] = i;
    }

        
    f(i,0,n){
        int target = n - i;

        if (p[i] != target){
        
            int j = pos[target];
            reverse(p.begin() + i, p.begin() + j+1);
        
            break;
        }
    }

    for(auto& val:p){
        cout << val << " ";
    
    }

    cout << "\n";

    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; 
    multipleTestCases and cin>>t;
    while(t--){
        solve();
    }
    return 0;
}