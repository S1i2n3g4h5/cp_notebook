
/*
  Competing against Myself  
  [zoASHro]
*/
#pragma GCC optimize("O2")  
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
template <typename... Args>
void print(Args&&... args){
   ((cout << args << " "), ...); cout << "\n";
}
#define all(x)(x).begin(),(x).end()
#define rall(x)(x).rbegin(),(x).rend()
#define pb push_back
#define f(i, a, b)          for(int i = a; i < b; i++)
#define debug(x) cout<<#x<<" = "<<x<<"\n"
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


// ______________________________________________________
long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
  long long result = 1; 
  while(power > 0){
    if(power & 1){result =(result*base) % MOD;}
    base =(base*base) % MOD;
    power = power>>1ll;
  } 
  return result;
}


const bool multipleTestCases = 0; 

void solve(){
  /*
    checking last charcter like - aaab
    then find total a's before last chacter

    here checing a cuz last character b.

    and for complex cases- abbaaaaabb
    finding last b then in our answer the last answer being the a
    and coutning total a's before that

    and if both same takings all a's or whatevr bigger length


    something like thsi apprach not passing for the test case 2

  */

    ll n;cin>>n;
    string s;cin>>s;
        
    ll cnta = count(all(s),'a');
    ll cntb = count(all(s),'b');

        
        //pos of akhri a
        int lasta=0,lastb=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
              lasta=i;
              break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b'){
              lastb=i;
              break;
            }
        }
        //calc a before lastb;
        string x1="",x2="";
        int ca=0;
        for(int i=0;i<=lastb;i++){
            if(s[i]=='a'){
                x1+='a';
                ca++;
            }
        } 
        x1+="ab";

        //calc b before lasta;
        int cb=0;
        for(int i=0;i<=lasta;i++){
            if(s[i]=='b'){
                x2+='b';
                cb++;
            }
        } 
        
        string x3=x2;
        x2+="aa";
        x3 += "ba";
        cnta++;
        cntb++;
        
        string cn1a(cnta, 'a');
        string cn1b(cntb, 'b');

        // print(x1,x2);
        // print(cn1a, cn1b);

        // print(min({cn1a, cn1b, x1,x2}));
        
        vector<string>ans = {cn1a, cn1b, x1,x2, x3};
        // for(auto x:ans)
        //     print (x);

        
        sort(all(ans),[&](auto a, auto b){
            if(a.size() == b.size())return a<b;
            return a.size() < b.size();
        });
        
        string finalans = ans[0];
        if(x2 == finalans and cnta > x2.size()){
            finalans = ans[1];
        }
        
        print(finalans);

}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int t = 1;
  if(multipleTestCases) cin >> t;
  while(t--){
      solve();
  }
  return 0;
}



// /*
//   Competing against Myself  
//   [zoASHro]
// */
// #pragma GCC optimize("O2")  
// #include <bits/stdc++.h>
// using namespace std;
// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>
// // using namespace __gnu_pbds;
// // typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// // //For making pdbs multiset with erase functionality working asexpected change `less<int>` to `less_equal<int>` and also during tree.erase using .find_by_order to remove exact value perfectly without any bugs
// template <typename... Args>
// void print(Args&&... args){
//    ((cout << args << " "), ...); cout << "\n";
// }
// #define all(x)(x).begin(),(x).end()
// #define rall(x)(x).rbegin(),(x).rend()
// #define pb push_back
// #define f(i, a, b)          for(int i = a; i < b; i++)
// #define debug(x) cout<<#x<<" = "<<x<<"\n"
// typedef long long ll;
// typedef pair<ll,ll> pll;
// typedef vector<ll> vll;


// // ______________________________________________________
// long long fast_power(long long base, long long power, long long  MOD=1e9+7ll){
//   long long result = 1; 
//   while(power > 0){
//     if(power & 1){result =(result*base) % MOD;}
//     base =(base*base) % MOD;
//     power = power>>1ll;
//   } 
//   return result;
// }


// const bool multipleTestCases = 0; 

// void solve(){
//   /*
//     checking last charcter like - aaab
//     then find total a's before last chacter

//     here checing a cuz last character b.

//     and for complex cases- abbaaaaabb
//     finding last b then in our answer the last answer being the a
//     and coutning total a's before that

//     and if both same takings all a's or whatevr bigger length


//     something like thsi apprach not passing for the test case 2

//   */

//     ll n;cin>>n;
//     string s;cin>>s;
        
//     ll cnta = count(all(s),'a');
//     ll cntb = count(all(s),'b');

        
//         //pos of akhri a
//         int lasta=0,lastb=0;
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='a'){
//               lasta=i;
//               break;
//             }
//         }
//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='b'){
//               lastb=i;
//               break;
//             }
//         }
//         //calc a before lastb;
//         string x1="",x2="";
//         int ca=0;
//         for(int i=0;i<=lastb;i++){
//             if(s[i]=='a'){
//                 x1+='a';
//                 ca++;
//             }
//         } 
//         ca++;
//         x1+='a';
//         if(cnta-ca>1){
//             x1+='b';
//         }

//         else if(cnta-ca==1){
//             x1+='aa';
//         }
//         else{
//             x1+='a';
//         }
        

//         //calc b before lasta;
//         int cb=0;
//         for(int i=0;i<=lasta;i++){
//             if(s[i]=='b'){
//                 x2+='b';
//                 cb++;
//             }
//         } 

//         cb++;
//         x2+='b';
//         if(cntb-cb>=1){
//             x1+='a';
//         }

        
//         else{
//             x1+='a';
//         }

//         if(x1.size()>x2.size()){
//             cout<<x2<<endl;
//         }
//         else if(x1.size()<x2.size()){
//             cout<<x1<<endl;
//         }
//         else{
//             cout<<x1<<endl;
//         }
        
        



//         // print(x1,x2);
//         // print(cn1a, cn1b);

//         // print(min({cn1a, cn1b, x1,x2}));
        
//         // vector<string>ans = {cn1a, cn1b, x1,x2};

        
//         // sort(all(ans),[&](auto a, auto b){
//         //     if(a.size() == b.size())return a<b;
//         //     return a.size() < b.size();
//         // });
        
//         // string finalans = ans[0];
//         // if(x2 == finalans and cnta > x2.size()){
//         //     finalans = ans[1];
//         // }
        
//         // print(finalans);

// }


// int main(){
//   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
//   int t = 1;
//   if(multipleTestCases) cin >> t;
//   while(t--){
//       solve();
//   }
//   return 0;
// }