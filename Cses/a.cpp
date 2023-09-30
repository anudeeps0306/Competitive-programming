#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> a;

string s = "ri1vf9med50";

bool f(vector<int> v, int target, int pos, int sum, vector<int> &ans)
{
    if (target == 0)
    {
        a = ans;
        return true;
    }
    if (pos == v.size())
    {
        return false;
    }
    if (sum >= v.size() / 2)
    {
        return false;
    }

    ans.push_back(v[pos]);
    if (target >= v[pos])
    {
        if (f(v, target - v[pos], pos + 1, sum + 1, ans))
        {
            return true;
        }
    }
    ans.pop_back();

    if (f(v, target, pos + 1, sum, ans))
    {
        return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    if (f(v, sum / 2, 0, 0, ans) == 0)
    {
        string p="";
        p+="-";
        p+=s;
        cout << p << endl;
        return 0;
    }

    set<int> s_set;

    for (auto it : a)
    {
        s_set.insert(it);
    }

    vector<int> ans2;

    for (int i = 0; i < n; i++)
    {
        if (s_set.find(v[i]) == s_set.end())
        {
            ans2.push_back(v[i]);
        }
        else
        {
            s_set.erase(v[i]);
        }
    }

    sort(a.begin(), a.end());
    sort(ans2.begin(), ans2.end());

    vector<int> final_ans;

    if (a[0] < ans2[0])
    {
        for (auto it : a)
        {
            final_ans.push_back(it);
        }
        for (auto it : ans2)
        {
            final_ans.push_back(it);
        }
    }
    else
    {
        for (auto it : ans2)
        {
            final_ans.push_back(it);
        }
        for (auto it : a)
        {
            final_ans.push_back(it);
        }
    }

    string interspersed;
    int j = 0;

    for (int i = 0; i < final_ans.size(); i++) {
        if (i == 0) {
            interspersed += to_string(final_ans[i]) + s[j%11]+",";
            j++;
        }
        else if (i == final_ans.size() - 1) {
            interspersed += s[j%11] + to_string(final_ans[i]);
            j++;
            interspersed += s.substr(j%11);
        }
        else {
            interspersed += s[j%11] + to_string(final_ans[i]);
            j++;
            interspersed += s[j%11];
            interspersed += ",";
            j++;
        }
    }

    cout << interspersed << endl;
}
