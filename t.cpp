
#include<iostream> 
#include<vector> 
#include<string>
#include<stack>
#include<list> 
#include<algorithm> 
#include<queue> [
    ]                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           o
]
using namespace std;   
#define xx first    
#define yy second    
#define ep emplace    
#define pb push_back    
#define mp make_pair    
#define all(x) x.begin(),x.end()    
using namespace std;    
int n, m;    
    
pair<int, int> dir[8] = { mp(-1,0),mp(-1,1),mp(0,1),mp(1,1),mp(1,0),mp(1,-1),mp(0,-1),mp(-1,-1) };    
signed main() {    
    int sx, sy, ex, ey, i, j;    
    cin >> n >> m >> sx >> sy >> ex >> ey;    
    vector<vector<int> > a(n + 2, vector<int>(m + 2, 1));    
    // 最外層填1當作邊界    
    for (i = 1; i <= n; i++) {    
        for (j = 1; j <= m; j++) {    
            char c;    
            cin >> c;    
            a[i][j] = (c - '0');    
        }    
    }    
    vector<vector<int> > vis(n + 2, vector<int>(m + 2, 0)); // 步數    
    vector<vector<int> > dir_map(n + 2, vector<int>(m + 2, 0)); // 方向    
    queue<pair<int, int>>q;    
    vis[sx][sy] = 1;    
    q.ep(mp(sx, sy));    
    while (!q.empty()) {    
        auto cur = q.front(); q.pop();    
        if (cur.xx == ex && cur.yy == ey)break;    
        for (i = 0; i < 8; i++) {    
            int next_x = cur.xx + dir[i].xx;    
            int next_y = cur.yy + dir[i].yy;    
            if (!a[next_x][next_y]) {    
                a[next_x][next_y] = 1;    
                dir_map[next_x][next_y] = i;    
                q.ep(mp(next_x, next_y));    
                vis[next_x][next_y] = vis[cur.xx][cur.yy] + 1;    
            }    
        }    
    }    
    cout << vis[ex][ey] << "\n";    
    vector<pair<int, int> > path;    
    path.pb(mp(ex, ey));    
    for (auto v = mp(ex, ey); v != mp(sx, sy);) {    
        int idx = dir_map[v.xx][v.yy];    
        v.xx -= dir[idx].xx;    
        v.yy -= dir[idx].yy;    
        path.pb(mp(v.xx, v.yy));    
    }    
    reverse(all(path));    
    for (auto v : path) printf("(%d,%d)\n", v.xx, v.yy);    
}