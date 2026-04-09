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



const bool multipleTestCases = 0;


void solve(){    
    int n;cin>>n;

    multiset<ll> left,right;

    f(i,0,n){
        char sign;
        ll l,r;
        cin>>sign>>l>>r;

        if(sign == '+'){
            left.insert(l);
            right.insert(r);

        }
        else{
            left.erase(left.find(l));
            right.erase(right.find(r));
        }

        if(left.empty()){
            print("NO");
            continue;
        }

        // ll mx_left = *max_element(left.begin(),left.end());
        // ll mn_right = *min_element(right.begin(), right.end());
        ll mx_left = *left.rbegin();
        ll mn_right = *right.begin();
        
        if(mn_right < mx_left)
            print("YES");
        else    print("NO");
    }
  return;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     


