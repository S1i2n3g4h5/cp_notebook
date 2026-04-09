/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;

template <typename... Args>
void print(Args&&... args){
    (std::cout << ... << args) << "\n";
}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll) {
  long long result = 1;
  while(power > 0){
    if(power & 1){result = (result*base) % MOD;}
    base = (base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 

int sum_digits(int x){
    if(x <= 0)
        return 0;
    return x%10 + sum_digits(x/10);
}

void solve(){
  /*
    for -1 -1 condition its simple to cehck the max sum of d digits VS the curr sum of s   and another edge case is when s=0 & d>1

    greedy strategy to build the formation number is easy, to choose max digits as much as possible;

    for smallest numer there are few edge cases like always reversing the largest number may not work when the initial digits gets 0 (which is not allowed);

  */
 
  
    int d,s;cin>>d>>s;

    int digits_in_s = log10(s)+1;
    int sum_of_s = sum_digits(s);
    int mx_sum=0;
    f(i,0,d) mx_sum += 9;


    // -1 -1
    if((s==0 and d>1) or (s > mx_sum)){
        print("-1 -1");
        return;
    }

    vector<int>digits = {0,1,2,3,4,5,6,7,8,9};

    // Largest number
    string largest_num = "";
    int rem_s=s;
    f(i,0,d){
        int digit = min(9, rem_s);
        largest_num+= ((char)('0' + digit));
        rem_s -= digit;
    }

    
    // Smallest number
    string smallest_num(d, '0');
    rem_s = s-1;  // saving 1 for last first digit;
    for(int i=d-1;i>0;i--){
        int digit = min(9,rem_s);
        smallest_num[i] = (char)('0' + digit);
        rem_s -= digit;
    }

    smallest_num[0] = (char)('0' + (rem_s + 1));


    print(smallest_num, " ", largest_num);

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    if (multipleTestCases) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}