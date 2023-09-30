#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> matrix(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                points.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < points.size(); i++) {
        int x = points[i].first;
        int y = points[i].second;

        for (int j = 0; j < m; j++) {
            matrix[x][j] = 0;
        }

        for (int j = 0; j < n; j++) {
            matrix[j][y] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}