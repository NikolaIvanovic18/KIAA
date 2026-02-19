#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

using funkcija = pair<int, int>;

int velicina(int n){
    return pow(2, ceil(log2(n)));
}

funkcija kompozicija(funkcija f, funkcija g){
    return {f.first * g.first, f.second + f.first * g.second};
}

vector<funkcija> buildTree(vector<funkcija>& niz, int n){
    vector<funkcija> tree(2*n);
    copy(begin(niz), end(niz), n + begin(tree));
    for(int i = n + niz.size(); i < 2*n; i++){
        tree[i] = {1, 0};
    }

    for(int i = n-1; i > 0; i--){
        tree[i] = kompozicija(tree[2*i + 1], tree[2*i]);
    }

    return tree;
}

void postavi(int i, int c, int d, vector<funkcija>& tree, int n){
    tree[i += n] = {c, d};
    for(i /= 2; i > 0; i /= 2){
        tree[i] = kompozicija(tree[2*i + 1], tree[2*i]);
    }
}

int upit(int l, int d, int x, vector<funkcija>& tree, int n){
    funkcija f = {1, 0};
    for(l += n, d += n; l <= d; l /= 2, d /= 2){
        if(l % 2 == 1){
            f = kompozicija(tree[l], f);
            l++;
        }
        if(d % 2 == 0){
            f = kompozicija(tree[d], f);
            d--;
        }
    }

    return f.first * x + f.second;
}

int main(){
    int n, q; cin >> n >> q;

    vector<funkcija> niz(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        niz[i] = {a, b};
    }

    int treeSize = velicina(n);
    vector<funkcija> tree = buildTree(niz, treeSize);

    while(q--){
        int i1, i2, i3, i4; cin >> i1 >> i2 >> i3 >> i4;
        if(i1 == 0){
            postavi(i2, i3, i4, tree, treeSize);
        }
        if(i1 == 1){
            cout << upit(i2, i3, i4, tree, treeSize) << '\n';
        }
    }

    return 0;
}