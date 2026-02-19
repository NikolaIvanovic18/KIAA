#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Cvor{
    bool krajReci = false;
    int prolaziReci = 0;
    unordered_map<char, Cvor*> grana;
};

void dodajRec(Cvor* koren, string& s){
    for(auto c : s){
        if(koren->grana.find(c) == koren->grana.end()){
            koren->grana[c] = new Cvor();
        }
        koren = koren->grana[c];
        koren->prolaziReci++;
    }

    koren->krajReci = true;
}

string ispitajRec(Cvor* koren, string& s){
    string result = "";
    for(char c : s){
        result += c;
        koren = koren->grana[c];
        
        if(koren->prolaziReci == 1){
            break;
        }
    }

    return result;
}

int main(){
    int n; cin >> n;

    Cvor* koren = new Cvor();

    vector<string> recnik(n);
    for(int i = 0; i < n; i++){
        cin >> recnik[i];
        dodajRec(koren, recnik[i]);
    }

    for(int i = 0; i < n; i++){
        cout << ispitajRec(koren, recnik[i]) << '\n';
    }

    return 0;
}