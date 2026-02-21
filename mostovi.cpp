#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using most = pair<int, int>;

void mostoviAlg(int v, int r, vector<int>& num, int& t, vector<int>& lowlink, vector<vector<int>>& graf, vector<most>& mostovi){
    lowlink[v] = num[v] = ++t;

    for(int w : graf[v]){
        if(num[w] != 0 && w != r){
            lowlink[v] = min(lowlink[v], num[w]);
        } else if(num[w] == 0){
            mostoviAlg(w, v, num, t, lowlink, graf, mostovi);

            lowlink[v] = min(lowlink[v], lowlink[w]);
            
            if(lowlink[w] > num[v]){
                mostovi.push_back({v, w});
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    
    vector<vector<int>> graf(n);
    while(m--){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    
    vector<most> mostovi;
    vector<int> num(n), lowlink(n);
    int t = 0;
    mostoviAlg(0, -1, num, t, lowlink, graf, mostovi);

    for(auto x : mostovi){
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}