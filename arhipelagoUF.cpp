#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> roditelj;
vector<int> rang;
int count;

void UF_init(int n){
    roditelj.resize(n);
    rang.resize(n);

    for(int i = 1; i < n; i++){
        roditelj[i] = i;
        rang[i] = 1;
    }
}

int UF_find(int x){
    while(x != roditelj[x]){
        roditelj[x] = roditelj[roditelj[x]];
        x = roditelj[x];
    }

    return x;
}

void UF_union(int x, int y){
    int fx = UF_find(x);
    int fy = UF_find(y);

    if(fx == fy){
        return;
    }

    count--;

    if(rang[fx] > rang[fy]){
        roditelj[fy] = fx;
        rang[fx] += rang[fy]; 
    } else if(rang[fx] < rang[fy]){
        roditelj[fx] = fy;
        rang[fy] += rang[fx];
    } else{
        roditelj[fx] = fy;
        rang[fy] *= 2;
    }
}

int main(){
    int n, m; cin >> n >> m;
    n++;
    count = n - 1;

    UF_init(n);

    while(m--){
        char c; cin >> c;
        if(c == 'U'){
            int a, b; cin >> a >> b;
            UF_union(a, b);
        } else if(c == 'P'){
            int a, b; cin >> a >> b;
            if(UF_find(a) == UF_find(b)){
                cout << "DA\n";
            } else{
                cout << "NE\n";
            }
        } else if(c == 'V'){
            int a; cin >> a;
            cout << rang[UF_find(a)] << '\n';
        } else if(c == 'K'){
            cout << count << '\n';
        }
    }


    return 0;
}