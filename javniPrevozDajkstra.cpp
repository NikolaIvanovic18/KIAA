#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;
using grana = pair<int, int>; //.first je cvor .second je tezina grane
using par = pair<int, int>; //.first je razdaljina .second je cvor

int dajkstra(int u, int k, vector<vector<grana>>& graf){
    vector<int> d(graf.size(), numeric_limits<int>::max());
    d[u] = 0;

    set<par> s;
    s.insert({0, u});

    while(!s.empty()){
        int v = s.begin()->second;
        s.erase(s.begin());

        for(grana w : graf[v]){
            int sused = w.first, duzina = w.second;
            int novaDuzina = max(duzina, d[v]);
            if(novaDuzina < d[sused]){
                s.erase({d[sused], sused});
                d[sused] = novaDuzina;
                s.insert({d[sused], sused});
            }
        }
    }

    return d[k];
}

int main(){ 
    int n, m; cin >> n >> m;
    vector<vector<grana>> graf(n);
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        graf[a-1].push_back({b-1, c});
        graf[b-1].push_back({a-1, c});
    }

    cout << dajkstra(0, n-1, graf) << '\n';

    return 0;
}