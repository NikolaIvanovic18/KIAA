#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using polje = pair<int, int>;

int bfs(polje pocetno, polje trazeno){
    vector<polje> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    vector<vector<int>> dist(8, vector<int>(8));
    vector<vector<bool>> visited(8, vector<bool>(8));
    queue<polje> q;

    q.push(pocetno);
    dist[pocetno.first][pocetno.second] = 0;
    visited[pocetno.first][pocetno.second] = true;

    while(!q.empty()){
        polje trenutno = q.front(); q.pop();
        if(trenutno == trazeno){
            return dist[trenutno.first][trenutno.second];
        }

        for(int i = 0; i < 8; i++){
            polje p = {trenutno.first + d[i].first, trenutno.second + d[i].second};
            if(p.first >= 0 && p.first < 8 && p.second >= 0 && p.second < 8 && !visited[p.first][p.second]){
                q.push(p);
                visited[p.first][p.second] = true;
                dist[p.first][p.second] = dist[trenutno.first][trenutno.second] + 1;
            } 
        }
    }

    return -1;
}

int main(){
    int n; cin >> n;

    while(n--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        polje pocetno = {x1 - 1, y1 - 1}, trazeno = {x2 - 1, y2 - 1};
        cout << bfs(pocetno, trazeno) << '\n';
    }

    return 0;
}