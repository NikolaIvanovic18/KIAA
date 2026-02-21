#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z(string s){
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
    string riff1, riff2, pesma; cin >> riff1 >> riff2 >> pesma;
    string p1 = riff1 + '$' + pesma;
    string p2 = riff2 + '$' + pesma;
    
    vector<int> z1 = z(p1);
    vector<int> z2 = z(p2);

    int count1 = 0, count2 = 0;
    for(int i = riff1.size() + 1; i < p1.size(); i++){
        if(z1[i] == riff1.size()){
            count1++;
        }
    }

    for(int i = riff2.size() + 1; i < p2.size(); i++){
        if(z2[i] == riff2.size()){
            count2++;
        }
    }

    if(count1 > count2){
        cout << 1 << '\n';
    } else if(count1 < count2){
        cout << 2 << '\n';
    } else{
        cout << 0 << '\n';
    }

    return 0;
}