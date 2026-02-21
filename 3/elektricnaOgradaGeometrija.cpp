#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using tacka = pair<int, int>;

int orijentacijaTrougla(tacka A, tacka B, tacka C){
    return (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
}

vector<tacka> KonveksniOmotac(vector<tacka>& p){
    swap(p[0], *min_element(p.begin(), p.end()));
    sort(begin(p) + 1, end(p), [&](tacka a, tacka b){
        return orijentacijaTrougla(p[0], a, b) > 0;
    });

    vector<tacka> omotac;
    omotac.push_back(p[0]);
    for(int i = 1; i < p.size(); i++){
        while(omotac.size() > 1 && orijentacijaTrougla(omotac[omotac.size() - 2], omotac.back(), p[i]) < 0){
            omotac.pop_back();
        } 
        omotac.push_back(p[i]);
    }
    
    return omotac;
}

int distance2(tacka t, tacka source){
    return (source.first - t.first)*(source.first - t.first) + (source.second - t.second)*(source.second - t.second);
}

int main(){
    int n; cin >> n;
    
    vector<tacka> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    int x, y; cin >> x >> y;
    tacka source = {x, y};

    vector<tacka> omotac = KonveksniOmotac(p);

    tacka best = {0, 0};
    for(tacka t : omotac){
        if(distance2(t, source) < distance2(best, source)){
            best = t;
        }
    }

    cout << best.first << ' ' << best.second << '\n';

    return 0;
}