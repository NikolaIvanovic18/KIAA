#include <iostream>
#include <vector>

using namespace std;

// 0 znaci nije obidjen, 1 znaci svetiljka, 2 znaci bez svetiljke
int bipartitan(int v, int trenutnaBoja, vector<int>& boja, vector<vector<int>>& graf){
    boja[v] = trenutnaBoja;
    int count = 0;
    if(trenutnaBoja == 1){
        count++;
    }

    for(auto w : graf[v]){
        if(boja[w] == trenutnaBoja){
            return -1;
        }

        if(boja[w] == 0){
            int pomocni = bipartitan(w, 3 - trenutnaBoja, boja, graf);
            if(pomocni == -1){
                return pomocni;
            } else{
                count += pomocni;
            }
        }
    }

    return count;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graf(n);

    while(m--){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    vector<int> boja(n, 0);
    int k = bipartitan(0, 1, boja, graf);
    cout << min(k, n - k) << '\n';

    return 0;
}