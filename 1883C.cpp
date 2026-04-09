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

    int n,k;cin>>n>>k;
    vector<ll>arr(n);
    f(i,0,n)cin>>arr[i];
    


    if(k==4){
        /*
            for k=4 there are special cases cuz 4=2*2 so we need to either -
                - go for all {2 even, 1 even, 1 odd, 2 odd} with cnt>=2   {max(0, 2-div_by_2_cnt)}
                - making ai div by 4

            these are 2 strategy to get final results so just need to take
            whichever strategy costs minimum...
        */ 
        int div_by_2_cnt=0;
        ll mn_div_4=k;
        f(i,0,n){
            if(arr[i]%2==0)div_by_2_cnt++;
            mn_div_4 = min(mn_div_4, (4 - (arr[i]%4))%4);
        }
        
        if(n==1){
            print((4 - (arr[0]%4))%4);
            
            return;
        }

        print(min(mn_div_4 ,(ll)max(0, 2-div_by_2_cnt) ) );


    }
    else{
        /*
            since 2,3,5 are primes nums so theres nothing to worry much onto 
            factors of it to get the array results
        */
       int min_diff=k;
        int num=arr[0];
        f(i,0,n){
           int diff = (k - (arr[i]%k));  
           if(diff == k)diff=0;
            if(diff < min_diff){
                min_diff=diff;
                num = arr[i];
            }
        }

        print(min_diff);
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


