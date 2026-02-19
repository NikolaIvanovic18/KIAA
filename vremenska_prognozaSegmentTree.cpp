#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int velicina(int n){
    return pow(2, ceil(log2(n)));
}

vector<double> buildTree(vector<double>& niz, int n){
    vector<double> tree(2*n);
    copy(begin(niz), end(niz), begin(tree) + n);

    for(int i = n - 1; i > 0; i--){
        tree[i] = tree[2*i] + tree[2*i + 1];
    }

    return tree;
}

void postavi(int i, double k, vector<double>& tree, int n){
    tree[i += n] = k;
    for(i /= 2; i > 0; i /= 2){
        tree[i] = tree[2*i] + tree[2*i + 1];
    }
}

double upit(int l, int d, vector<double>& tree, int n){
    double suma = 0;
    int delilac = d - l + 1;

    for(l += n, d += n; l <= d; l /= 2, d /= 2){
        if(l % 2 == 1){
            suma = suma + tree[l];
            l++;
        }
        if(d % 2 == 0){
            suma = suma + tree[d];
            d--;
        }
    }

    return suma / delilac;
}

int main(){
    int n; cin >> n;
    vector<double> niz(n);

    for(int i = 0; i < n; i++){
        cin >> niz[i];
    }

    int treeSize = velicina(n);
    vector<double> tree = buildTree(niz, treeSize);

    int m; cin >> m;
    while(m--){
        char c; cin >> c;
        if(c == 'u'){
            int i; double k; cin >> i >> k;
            postavi(i - 1, k, tree, treeSize);
        }
        if(c == 'p'){
            int a, b; cin >> a >> b;
            cout << upit(a - 1, b - 1, tree, treeSize) << '\n';
        }
    }

    return 0;
}