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


bool supercentral(int& pidx, vector<pair<int,int>> &pts){
    int left=0,right=0,top=0,bottom=0;

    f(i,0,pts.size()){
        if(i!=pidx){
            // left
            if(pts[i].first<pts[pidx].first and pts[i].second ==pts[pidx].second) left++;
            
            // right
            if(pts[i].first>pts[pidx].first and pts[i].second ==pts[pidx].second) right++;
            
            // top
            if(pts[i].first==pts[pidx].first and pts[i].second >pts[pidx].second) top++;
            
            // bottom
            if(pts[i].first==pts[pidx].first and pts[i].second <pts[pidx].second) bottom++;
            
        }
    }

    return left and right and top and bottom;
}


void solve(){       

    int n;cin>>n;
    vector<pair<int,int>>pts(n);
    f(i,0,n){
        int x,y;cin>>x>>y;
        pts[i].first=x;
        pts[i].second=y;
    }

    int cnt=0;
    f(i,0,n){
        if(supercentral(i, pts))
            cnt++;
    }

    print(cnt);

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
