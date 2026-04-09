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


bool loop_radiator(int &r,int &x,int &y, auto &rx,auto& ry,auto& rr){
    f(i,0,r){
        int xx = x-rx[i];
        int yy = y-ry[i];
        if((xx*xx + yy*yy) <= rr[i])
            return true;
    }
    return false;
}


void solve(){
  
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;

    int recX1=min(x1,x2);
    int recX2=max(x2,x1);
    int recY1=min(y1,y2);
    int recY2=max(y2,y1);

    int r;cin>>r;
    vector<int>rx(r),ry(r),rr(r);
    f(i,0,r){
        cin>>rx[i] >>ry[i] >> rr[i];
        rr[i]*=rr[i];
    }


    int blankets=0;

    f(i,recX1,recX2+1){
        if(!loop_radiator(r,i,recY1,rx,ry,rr)) blankets++;
        if(!loop_radiator(r,i,recY2,rx,ry,rr)) blankets++;
    }

    f(i,recY1+1, recY2){
        if(!loop_radiator(r,recX1,i,rx,ry,rr)) blankets++;
        if(!loop_radiator(r,recX2,i,rx,ry,rr)) blankets++;
    }


    print(blankets);

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