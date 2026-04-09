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

    ll m,n;cin>>m>>n;
    
    struct Worker{
        ll t,z,y;
    };
    vector<Worker> workers(n);
    f(i,0,n){
        ll t,z,y;cin>>t>>z>>y;
        workers[i].t = t;
        workers[i].z = z;
        workers[i].y = y;
    }


    auto calcWorkerCapacity = [&](ll T, Worker worker){
    
        ll fullCycleTime = worker.t*worker.z + worker.y;

        ll fullCycle = T / fullCycleTime;
        ll leftovercycletime = T%fullCycleTime;
        
        ll leftoverCycle = min(worker.z, leftovercycletime / worker.t);
    
        return (fullCycle * worker.z) + leftoverCycle;
    };


    ll l=0,h=1e9;
    while(l<=h){
        ll mid = l + (h-l)/2;


        ll total_ballons =0;
        f(i,0,n){
            total_ballons += calcWorkerCapacity(mid, workers[i]);
        }


        if(total_ballons < m){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    print(l);



    ll totalBallons = m;           // *****   `m` not `l`  cuz `l` is the time but we need totBallons
    for(Worker& worker : workers){
        ll capacity = calcWorkerCapacity(l, worker);
        capacity = min(totalBallons, capacity);

        cout << capacity << " ";
        totalBallons -= capacity;
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
