#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << "\n";
}
#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


const bool multipleTestCases = false;

bool solve(){

  int n,k;cin>>n>>k;
  vector<int>arr(n);
  map<ll, int>freq;
  f(i,0,n)cin>>arr[i],freq[arr[i]]++;

  sort(arr.begin(), arr.end());


  // int bucket = k / n;
  // if (k%n == 0) bucket--;
  // int second = (k%n == 0 ?  + n-1 : (k%n)-1);
  // // cout  << " - > "<<second << endl;
  // print(arr[bucket], " ", arr[second]);


  for(int i=0;i<n;i++){

    // counting the freq of number coming up
    int count = freq[arr[i]];

    if (k < (n * count)){
      print(arr[(k -i-1  )  / count]); 
    }
    else{

    }

  }

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