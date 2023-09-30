#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        vector<pair<char, int>> vp;
        for (auto itr : m)
        {
            vp.push_back({itr.first, itr.second});
        }
        sort(vp.begin(),vp.end());
        int k = 0, g = 1;
        char u;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vp[0].first == s[i])
            {
                ans++;
            }
            else
            {
                break;
            }
        }

        if (ans == vp[0].second)
        {
            cout << s << endl;
        }
        else
        {
            int g = vp[0].second - ans + 1;
            int d = 0;
            string s2 = "";
            s2 = s2 + vp[0].first;
            for (int i = 0; i < n; i++){
                if (s[i] == vp[0].first){
                    d++;
                }
                if (d == vp[0].second)
                {
                    d++;
                    continue;
                }
                s2 = s2 + s[i];
            }
            cout << s2 << endl;
        }
    }
}