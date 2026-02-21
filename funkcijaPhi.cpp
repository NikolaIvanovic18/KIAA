#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int phi(int n){
    int proizvod = n;
    for(int d = 2; d*d <= n; d++){
        if(n % d == 0){
            proizvod = (proizvod / d) * (d - 1);
            while(n % d == 0){
                n /= d;
            }
        }
    }

    if(n > 1){
        proizvod = (proizvod / n) * (n - 1);
    }

    return proizvod;
}