#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> zAlgo(string& s){
    int n = s.size();
    vector<int> z(n);

    int l = 0, d = -1;
    for(int i = 1; i < n; i++){
        if(i <= d){
            z[i] = min(z[i - l], d - i + 1);
        }

        while(z[i] + i < n && s[z[i]] == s[z[i] + i]){
            z[i]++;
        }

        if(i + z[i] - 1 > d){
            l = i;
            d = i + z[i] - 1;
        }
    }

    return z;
}

int main(){
    string grad, sifra; cin >> grad >> sifra;

    for(int k = 0; k < 26; k++){
        string noviGrad = grad;
        for(int j = 0; j < grad.size(); j++){
            noviGrad[j] = 'a' + ((grad[j] - 'a' + k) % 26);
        }

        string p = noviGrad + '$' + sifra;
        vector<int> z = zAlgo(p);

        for(int i = grad.size() + 1; i < p.size(); i++){
            if(z[i] == grad.size()){
                cout << k << '\n';
                break;
            }
        }
    }

    return 0;
}