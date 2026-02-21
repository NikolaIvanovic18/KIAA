#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void artAlg(int v, int r, vector<int>& num, int& t, vector<int>& lowlink, vector<vector<int>>& graf, vector<bool>& artTacke){
    lowlink[v] = num[v] = ++t;
    int children = 0;

    for(int w : graf[v]){
        if(num[w] != 0 && w != r){
            lowlink[v] = min(lowlink[v], num[w]);
        } else if(num[w] == 0){
            children++;
            artAlg(w, v, num, t, lowlink, graf, artTacke);

            lowlink[v] = min(lowlink[v], lowlink[w]);
            
            if(r != -1 && lowlink[w] >= num[v]){
                artTacke[v] = true;
            }
        }
    }

    if(r == -1 && children > 1){
        artTacke[v] = true;
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
    
    vector<bool> artTacke(n);
    vector<int> num(n), lowlink(n);
    int t = 0;
    
    for(int i = 0; i < n; i++){
        if(num[i] == 0){
            artAlg(i, -1, num, t, lowlink, graf, artTacke);
        }
    }

    for(int i = 0; i < n; i++){
        if(artTacke[i] == true){
            cout << i << '\n';
        }
    }

    return 0;
}