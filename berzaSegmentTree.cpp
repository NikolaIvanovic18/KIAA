#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

int velicina(int n){
    return pow(2, ceil(log2(n)));
}

pair<int ,int> merge(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first){
        return a;
    } else if(b.first > a.first){
        return b;
    }
    return {a.first, a.second + b.second};
}

vector<pair<int , int>> buildTree(int n, vector<int>& niz){
    vector<pair<int, int>> tree(2*n);
    for(int i = n; i < 2*n; i++){
        tree[i] = {niz[i - n], 1};
    }
    
    for(int i = n - 1; i > 0; i--){
        tree[i] = merge(tree[2*i], tree[2*i + 1]);
    }

    return tree;
}

void postavi(int i, int v, vector<pair<int, int>>& tree, int n){
    tree[i += n] = {v, 1};
    for(i /= 2; i > 0; i /= 2){
        tree[i] = merge(tree[2*i], tree[2*i + 1]);
    }
}

pair<int ,int> upit(int l, int d, vector<pair<int, int>>& tree, int n){
    pair<int, int> res = {numeric_limits<int>::min(), 0};
    for(l += n, d += n; l <= d; l /= 2, d /= 2){
        if(l % 2 == 1){
            res = merge(res, tree[l]);
            l++;
        }
        if(d % 2 == 0){
            res = merge(res, tree[d]);
            d--;
        }
    }

    return res;
}

int main(){
    int n, q; cin >> n >> q;
    vector<int> niz(n);

    for(int i = 0; i < n; i++){
        cin >> niz[i];
    }

    int treeSize = velicina(n);
    vector<pair<int, int>> tree = buildTree(treeSize, niz);

    while(q--){
        char x; int i1, i2; cin >> x >> i1 >> i2;
        if(x == 'm'){
            pair<int, int> rez = upit(i1, i2, tree, treeSize);
            cout << rez.first << ' ' << rez.second << '\n';
        } else if(x == 'u'){
            postavi(i1, i2, tree, treeSize);
        }
    }

    return 0;
}