#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Cvor{
    bool krajReci = false;
    unordered_map<char, Cvor*> grana;
};

void dodajRec(Cvor* koren, string& s){
    for(char c : s){
        if(koren->grana.find(c) == koren->grana.end()){
            koren->grana[c] = new Cvor();
        }
        koren = koren->grana[c];
    }

    koren->krajReci = true;
}

int ispitajPrefiks(Cvor* koren, string& prefiks){
    for(char c : prefiks){
        if(koren->grana.find(c) == koren->grana.end()){
            return 0;
        }
        koren = koren->grana[c];
    }

    return 1;
}

int main(){
    int n, m; cin >> n >> m;

    Cvor* koren = new Cvor();

    while(n--){
        string s; cin >> s;
        dodajRec(koren, s);
    }

    while(m--){
        string s; int d; cin >> s >> d;
        string prefiks = s.substr(0, d);
        cout << ispitajPrefiks(koren, prefiks) << '\n';
    }

    return 0;
}