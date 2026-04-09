#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> children_count(n + 1, 0);

    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_ops = 0;
    
    
    
    vector<int> q;
    q.push_back(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    

    
    int head = 0;

    while(head < q.size()){
        int u = q[head++];
        int children = 0;
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                children++;
                q.push_back(v);
            }
        }


        max_ops = max(max_ops, children + 1);
    }

    
    cout << max_ops << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}