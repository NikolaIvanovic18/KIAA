#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void artAlg(int v, int r, vector<int>& nums, int& t, vector<int>& lowlink, vector<vector<int>>& graf, vector<bool>& art){
    lowlink[v] = nums[v] = ++t;
    int children = 0;

    for(auto w : graf[v]){
        if(nums[w] != 0 && w != r){
            lowlink[v] = min(lowlink[v], nums[w]);
        } else if(nums[w] == 0){
            children++;
            artAlg(w, v, nums, t, lowlink, graf, art);

            lowlink[v] = min(lowlink[v], lowlink[w]);

            if(r != -1 && lowlink[w] >= nums[v]){
                art[v] = true;
            }
        }
    }

    if(r == -1 && children > 1){
        art[v] = true;
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graf(n);
    vector<int> d(n, 0);

    for(int i = 0; i < n; i++){
        cin >> d[i]; 
    }

    while(m--){
        int a, b; cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    vector<int> nums(n), lowlink(n); int t = 0;
    vector<bool> art(n, false);
    for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            artAlg(i, -1, nums, t, lowlink, graf, art);
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        if(art[i] == true){
            count += d[i];
        }
    }

    if(count >= 0){
        cout << "POZITIVNA " << count << '\n'; 
    } else{
        cout << "NEGATIVNA " << -count << '\n';
    }

    return 0;
}