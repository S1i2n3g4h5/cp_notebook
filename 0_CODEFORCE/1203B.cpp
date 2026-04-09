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
    // int n;cin>>n;

    // map<int, int> a;
    // vector<int>lens;

    // f(i,0,4*n){
    //     int t;cin>>t;
    //     a[t]++;
    //     if (a[t]%2==0)
    //         lens.push_back(t);
    // }

    // if (a.size() == 1){
    //     print("YES");
    //     return 1;

    // }

    // // check if even-freqs
    // for(auto&p:a){
    //     if (p.second %2== 1){
    //         print("NO");
    //         return 1;
    //     }
    // }


    // n = lens.size();
    // sort(lens.begin(), lens.end());
    // f(i,1,n/2){
    //     if (lens[i]*lens[n-i-1] != lens[i-1]*lens[n-(i-1)-1]){
    //         print("NO");
    //         return 1;
    //     }
    // }
    // print("YES");


    /*
            MUCH BETTER READABLE SOLUTION
    */

    int n; 
    cin >> n;
    
    int total_sticks = 4 * n;
    vector<int> a(total_sticks);
    for (int i = 0; i < total_sticks; i++) {
        cin >> a[i];
    }

    // Sort all sticks to easily find pairs and min/max lengths
    sort(a.begin(), a.end());

    // Step 1: Check if every stick has a twin (sticks[i] must equal sticks[i+1])
    for (int i = 0; i < total_sticks; i += 2) {
        if (a[i] != a[i + 1]) {
            print("NO");
            return true;
        }
    }

    // Step 2: Use two pointers to pair the smallest side with the largest side
    // target_area is determined by the absolute smallest and largest sticks
    int left = 0;
    int right = total_sticks - 1;
    long long target_area = (long long)a[left] * a[right];

    while (left < right) {
        // Current rectangle area: smallest available pair * largest available pair
        long long current_area = (long long)a[left] * a[right];

        if (current_area != target_area) {
            print("NO");
            return true;
        }

        // Move pointers by 2 since we already verified the "twins" in Step 1
        left += 2;
        right -= 2;
    }

    print("YES");

  return 1;
}
 
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}   