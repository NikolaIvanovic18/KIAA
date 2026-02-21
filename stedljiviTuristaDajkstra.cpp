#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;
using grana = pair<int, int>;
using par = pair<int, int>;

// graf[i].first je cvor do kog stize, graf[i].second je tezina grane
int dajkstra(int u, int k, vector<vector<grana>>& graf){
    vector<int> d(graf.size(), numeric_limits<int>::max());

    d[u] = 0;

    set<par> s; //s.first je duzina do cvora, s.second je cvor
    s.insert({0, u});

    while(!s.empty()){
        int v = s.begin()->second;
        s.erase(s.begin());

        for(auto w : graf[v]){
            int sused = w.first, duzina = w.second;
            if(duzina + d[v] < d[sused]){
                s.erase({d[sused], sused});
                d[sused] = duzina + d[v];
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
        int x, y, d; cin >> x >> y >> d;
        graf[x].push_back({y, d});
        graf[y].push_back({x, d});
    }

    int A, B, C, D; cin >> A >> B >> C >> D;

    cout << min(dajkstra(A, C, graf) + dajkstra(C, B, graf), dajkstra(A, D, graf) + dajkstra(D, B, graf)) << '\n';

    return 0;
}