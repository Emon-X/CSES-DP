#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool cmp(const pair<ll, pair<ll, ll>> &a, const pair<ll, pair<ll, ll>> &b)
{
    return a.second.first < b.second.first;
}

void domain_expension()
{
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> v;
    for (int i = 0; i < n; i++)
    {
        ll l, r, p;
        cin >> l >> r >> p;
        v.pb({l, {r, p}});
    }
    sort(v.begin(), v.end(), cmp);

    vector<ll> dp(n + 1, 0), ends;
    for (int i = 0; i < n; i++)
        ends.pb(v[i].second.first);

    for (int i = 1; i <= n; i++)
    {
        ll l = v[i - 1].first;
        ll r = v[i - 1].second.first;
        ll p = v[i - 1].second.second;

        // not take i option
        dp[i] = dp[i - 1];

        // take i option 
        ll j = upper_bound(all(ends), l - 1) - ends.begin();
        dp[i] = max(dp[i], dp[j] + p);
    }
    cout << dp[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}
