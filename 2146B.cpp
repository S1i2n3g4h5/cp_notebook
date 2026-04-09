/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void print(Args&&... args){(std::cout << ... << args) << "\n";}

#define f(i, a, b)          for(int i = a; i < b; i++)
#define ll long long
#define ld long double


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



// ______________________________________________________
const bool multipleTestCases = 1;


void solve(){
  /*    
    This problem based on checking if the ways to check exists or not
    so only output yes/no;

    instead of checking each set with each to find the redundacny sets(sets when removed doenst make any contribution to the overall [1..m] required set)

    so instead of checking possible sets conditions we checking the 
    count of redundancy sets possible, like if we've got atleast 2 sets 
    which can be removed then there must exist ways to select sets such that it covers[1..m];

    but also before all this checking if all sets combined contribute to [1..m] or not
        if not then NO answer;

    
    ->> since we first check if combining the sets gets us answer or not
        so thats why the redudancy count approach works.
        1. 
  */
    
    int n,m;cin>>n>>m;
    vector<bool>is_all_there(m+1,false);
    vector<vector<int>>sets(n);
    f(i,0,n){
        int x;cin>>x;
        vector<int>arr(x);
        f(j,0,x){
            cin>>arr[j];
            if(!is_all_there[arr[j]]){
                is_all_there[arr[j]] = 1;
            }
        }
        sets[i] = arr;
    }
  
    
    // Checking if all nums there to build
    f(i,1,m+1){
        if(!is_all_there[i]){
            print("NO");
            return;
        }
    }

    
    // count sets containing which numbers
    map<int,int> all_nums_sets;
    f(i,0,n){
        for(auto num : sets[i]){
            all_nums_sets[num]++;
        }
    }

    
    int redundancy_count = 0;

    f(i,0,n){
        bool removable=true;
        f(j,0,sets[i].size()){
            int num = sets[i][j];
            if(all_nums_sets[num] <= 1){
                removable=false;
                break;
            }
        }

        if(removable){
            redundancy_count++;
        }
    }


    if(redundancy_count >= 2){
        print("YES");

    }
    else{
        print("NO");
    }
    
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;multipleTestCases and cin >> t;    
    while(t--){  
      solve();
    }  
    return 0;
}     
