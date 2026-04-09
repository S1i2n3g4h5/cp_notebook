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
const bool multipleTestCases = 0;

void solve(){       

    int n,q;cin>>n>>q;
    vector<int>arr(n+2,0),pos(n+2,0);
    f(i,1,n+1){
        int x;cin>>x;
        arr[x]=i;
        pos[i]=x;
    }
    
    
    int total_inequalities = 0;
    f(i,1,n){
        if(arr[i] > arr[i + 1]){
            total_inequalities++;
        }
    }


    while(q--){
        int a,b;cin>>a>>b;
        // a--;b--;
        
        if(a==b){
            print(total_inequalities+1);
            continue;
        }

        //___________________________________________
        // below code giving tle so to fix, using running `inequality` variable
        
        // swap(arr[pos[a]], arr[pos[b]]);
        // swap(pos[a], pos[b]);

        
        // int inequality=1;
        // f(i,2,arr.size()){
            //     if(arr[i-1]>arr[i])inequality++;
            // }
        //___________________________________________    
            


        int x = pos[a];
        int y = pos[b];

        
        // subtracting 
        if(x > 1  and (arr[x-1] > arr[x])){
            total_inequalities--;
        }
        if(x < n  and  (arr[x] > arr[x + 1])){
            total_inequalities--;
        }
        if(y>1 and y-1!=x and (arr[y-1] > arr[y])){
            total_inequalities--;
        }
        if(y<n and y+1!=x and (arr[y] > arr[y + 1])){
            total_inequalities--;
        }



        swap(pos[a], pos[b]);
        arr[x]=b;
        arr[y]=a;


        if(x > 1 and (arr[x-1] > arr[x])){
            total_inequalities++;
        }
        if(x < n  and  (arr[x] > arr[x + 1])){
            total_inequalities++;
        }
        if(y>1 and y-1!=x and (arr[y-1] > arr[y])){
            total_inequalities++;
        }
        if(y<n and y+1!=x and (arr[y] > arr[y + 1])){
            total_inequalities++;
        }

        print(total_inequalities+1);
        
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
