#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> rang;

void UF_init(int n){
    parent.resize(n);
    rang.resize(n);

    for(int i = 0; i < n; i++){
        parent[i] = i;
        rang[i] = 1;
    }
}

int UF_find(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

void UF_union(int x, int y){
    int fx = UF_find(x);
    int fy = UF_find(y);

    if(fx == fy){
        return;
    }

    if(rang[fx] > rang[fy]){
        parent[fy] = fx;
        rang[fx] += rang[fy];
    } else if(rang[fx] < rang[fy]){
        parent[fx] = fy;
        rang[fy] += rang[fx];
    } else{
        parent[fx] = fy;
        rang[fy] *= 2;
    }
}

int main(){

    int n, q; cin >> n >> q;
    n++;

    UF_init(n);
    while(q--){
        char upit; cin >> upit;
        if(upit == 'M'){
            int a, b; cin >> a >> b;
            UF_union(a, b);
        } else if(upit == 'Q'){
            int a; cin >> a;
            cout << rang[UF_find(a)] << '\n';
        }
    }

    return 0;
}