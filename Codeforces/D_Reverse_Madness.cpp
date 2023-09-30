#include <bits/stdc++.h>

#define fastIO                             \
    {                                      \
        ios_base ::sync_with_stdio(false); \
        cin.tie(NULL);                     \
        cout.tie(NULL);                    \
    }

using namespace std;

int mod = 10000007;


class SegmentTree {
private:
    vector<int> tree;

    void build(int start, int end, int node, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(start, mid, 2 * node + 1, arr);
        build(mid + 1, end, 2 * node + 2, arr);
        tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
    }

    int query(int start, int end, int node, int left, int right) {
        if (left <= start && right >= end)
            return tree[node];
        if (left > end || right < start)
            return INT_MAX;
        int mid = start + (end - start) / 2;
        int left_result = query(start, mid, 2 * node + 1, left, right);
        int right_result = query(mid + 1, end, 2 * node + 2, left, right);
        return left_result & right_result;
    }

public:
    SegmentTree(vector<int>& arr) {
        int n = arr.size();
        tree.resize(4 * n);
        build(0, n - 1, 0, arr);
    }

    int findMaxIndex(int start, int end, int k) {
        int left = start;
        int right = end;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int query_result = query(0, end, 0, start, mid);
            if (query_result >= k) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        if (ans >= 0)
            ans += 1;
        return ans;
    }
};
int lcm(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}

bool clean(string str)
{
    bool flag = false;
    int n;

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == 'A' && str[i + 1] == 'B')
        {
            flag = true;
        }
        else if (str[i] == 'B' && str[i + 1] == 'B')
        {
            flag = true;
        }
    }
    return flag;
}

int check(int i, vector<int> ans)
{
    for (auto it : ans)
    {
        if (it % i != 0)
        {
            return -1;
        }
    }

    if (i == 1)
        return 2;

    for (int index = 2; index < i; index++)
    {
        if (i % index != 0)
        {
            return index;
        }
    }

    return i + 1;
}

char get(int i)
{
    return 'a' + i - 1;
}

const int INF = 1e9 + 7;

int myans(int n)
{
    int pow = 1;
    while (pow <= n)
    {
        pow *= 2;
    }
    return pow;
}

int bpow(int base, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

int badd(int a, int b)
{
    return (a + b) % mod;
}
int bsub(int a, int b)
{
    return (((a - b) % mod) + mod) % mod;
}
int bmul(int a, int b)
{
    return ((a % mod) * (b % mod)) % mod;
}

int binv(int base)
{
    return bpow(base, mod - 2);
}

int bdiv(int a, int b)
{
    return bmul(a, binv(b));
}

// function to find factorial of a n number
int fact(int n)
{
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
int maxi = INT_MIN;

int main() {
    fastIO;
    int t;
    cin >> t;
    
    set<int> odd_num;
    set<int> even_num;

    for (int i = 1; i <= 100000; i++) {
        if (i % 2 == 1)
            odd_num.insert(i);
        else
            even_num.insert(i);
    }

    while (t--) {
        int length, target_sum;
        cin >> length >> target_sum;

        int total_sum = length / 2 + length;
        int cnt_odd = length / 2;
        int even_cnt = length / 2;

        if (total_sum % 2 != target_sum % 2 || total_sum > target_sum) {
            cout << -1 << endl;
        } else {
            total_sum = 0;
            vector<int> result;
            int flag = 0;

            for (int i = 0; i < length; i++) {
                int current_diff;
                if (i % 2 == 0)
                    cnt_odd -= 1;
                else
                    even_cnt -= 1;

                current_diff = cnt_odd + even_cnt * 2;
                int value = target_sum - current_diff;
                set<int>::iterator num_s;

                if (i % 2 == 0) {
                    num_s = odd_num.lower_bound(value);
                    if (num_s != odd_num.end() && *num_s > value)
                        num_s--;
                } else {
                    num_s = even_num.lower_bound(value);
                    if (num_s != even_num.end() && *num_s > value)
                        num_s--;
                }

                if (num_s == odd_num.end() || num_s == even_num.end()) {
                    flag = 1;
                    break;
                }

                result.push_back(*num_s);
                target_sum -= *num_s;
            }

            if (flag == 1 || target_sum != 0) {
                cout << -1 << endl;
            } else {
                for (int num : result) {
                    cout << num << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
