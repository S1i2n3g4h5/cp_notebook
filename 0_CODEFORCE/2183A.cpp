#include <iostream>
#include <vector>

using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }


    if (a[0] == 1 || a[n-1]== 1){
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}