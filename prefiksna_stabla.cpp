#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Cvor{
    bool krajReci = false;
    map<char, Cvor*> grana;
};

void dodaj(Cvor* koren, string& s){
    for(char c : s){
        if(koren->grana.find(c) == end(koren->grana)){
            koren->grana[c] = new Cvor();
        }
        koren = koren->grana[c];
    }
    koren->krajReci = true;
}

bool nadji(Cvor* koren, string& s){
    for(char c : s){
        if(koren->grana.find(c) == end(koren->grana)){
            return false;
        }
        koren = koren->grana[c];
    }

    return koren->krajReci;
}

void oslobodi(Cvor* koren){
    for(auto podstablo : koren->grana){
        oslobodi(podstablo.second);
    }
    delete koren;
}

Cvor* noviKoren(Cvor* koren, string& prefiks){
    for(auto c : prefiks){
        koren = koren->grana[c];
    }
    return koren;
}

void ispis(Cvor* koren, string& rec){
    if(koren->krajReci == true){
        cout << rec << '\n';
    }

    for(auto podstablo : koren->grana){
        rec.push_back(podstablo.first);
        ispis(podstablo.second, rec);
        rec.pop_back();
    }
}


int main(){
    Cvor* stablo = new Cvor();

    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        dodaj(stablo, s);
    }
    
    string prefiks; cin >> prefiks;
    Cvor* newStablo = noviKoren(stablo, prefiks);
    string rec = prefiks;
    ispis(newStablo, rec);

    oslobodi(stablo);

    return 0;
}