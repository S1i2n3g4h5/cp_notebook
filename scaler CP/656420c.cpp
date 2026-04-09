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

const bool multipleTestCases = true;

bool solve(){


    int n;cin>>n;
    vector<ll> arr(n);
    vector<ll> divby3_arr,notdiv3_arr;
    f(i,0,n){
        cin>>arr[i];

        if (arr[i]%3 ==0) divby3_arr.push_back(arr[i]);
        else
            notdiv3_arr.push_back(arr[i]);
    }

    
//     count+= ((div3 - pairs)/3) + ((notdiv3 - pairs)/3);

//     print(count);

    ll count = divby3_arr.size();

    ll m1,m2;


    m1=m2=0;
    for(auto& val:notdiv3_arr){
        if (val%3 ==1) m1++;
        else if (val%3 ==2) m2++;
    }
    ll mn =min(m1,m2);

    // print(mn, m1, m2);

    m1-= mn;
    m2 -=mn;
    // print("first m diff - ", m1,",", m2,",",  " final - ", m1/3, ", ", m2/3);
    count += mn + (m1/3)+(m2/3);

    print(count);
  
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