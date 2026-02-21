#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tacka = pair<double, double>;

double eps = 1e-9;

bool rayIntersect(tacka& A, tacka& B, tacka Q){
    if(Q.second == A.second || Q.second == B.second){
        Q.second += eps;
    }

    if(Q.second < A.second || Q.second > B.second){
        return false;
    }

    if(Q.first > max(A.first, B.first)){
        return false;
    }

    if(Q.first < min(A.first, B.first)){
        return true;
    }

    double kAQ = (Q.second - A.second) / (Q.first - A.first);
    double kAB = (B.second - A.second) / (B.first - A.first);

    return kAQ >= kAB;
}

bool rayCasting(vector<tacka>& p, tacka Q){
    int n = p.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        int j = (i + 1) % n;

        tacka A = p[i];
        tacka B = p[j];

        if(A.second < B.second){
            if(rayIntersect(A, B, Q)){
                count++;
            }
        } else{
            if(rayIntersect(B, A, Q)){
                count++;
            }
        }
    }

    return count % 2;
}

int main(){
    int n, m; cin >> n >> m;

    vector<tacka> poligon(n);
    for(int i = 0; i < n; i++){
        cin >> poligon[i].first >> poligon[i].second;
    } 

    double count = 0;
    while(m--){
        double x, y, cena; cin >> x >> y >> cena;
        tacka Q = {x, y};
        if(rayCasting(poligon, Q)){
            count += cena;
        }
    }

    cout << count << '\n';

    return 0;
}