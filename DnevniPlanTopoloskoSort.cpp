#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int topolosko(vector<vector<int>>& graf){
    int n = graf.size();
    vector<int> indeg(n);
    vector<int> d(n);

    for(int i = 0; i < n; i++){
        for(auto v : graf[i]){
            indeg[v]++;
        }
    }

    vector<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push_back(i);
            d[i] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(auto v : graf[q[i]]){
            indeg[v]--;
            d[v] = max(d[v], d[q[i]] + 1);
            if(indeg[v] == 0){
                q.push_back(v);
            }
        }
    }

    if(q.size() < n){
        return -1;
    } else{
        return *max_element(d.begin(), d.end());
    }
}

int main(){
    int n, m; cin >> n >> m;
    
    vector<vector<int>> graf(n);
    while(m--){
        int a, b; cin >> a >> b;
        graf[a - 1].push_back(b - 1);
    }

    cout << topolosko(graf) << '\n';

    return 0;
}