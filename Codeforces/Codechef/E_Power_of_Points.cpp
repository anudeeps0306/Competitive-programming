int n, m;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cin >> m;
        vector<pair<int, int>> q(m);
        for (int i = 0; i < m; i++) {
            cin >> q[i].first >> q[i].second;
        }
        
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            map<int, int> hashMap;
            int x = q[i].first, y = q[i].second;
            int f = 0;
            
            for (int j = 0; j < n; j++) {
                if (hashMap.count(x - arr[j]) && arr[j] * (x - arr[j]) == y) {
                    f += hashMap[x - arr[j]];
                }
                hashMap[arr[j]]++;
            }
            
            ans[i] = f;
        }
        
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;