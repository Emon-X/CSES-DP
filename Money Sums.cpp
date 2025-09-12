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
#define N 100005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        s[i] = x;
        sum += x;
    }
    vector<ll> dp(sum + 1, 0);
    dp[0] = 1;

    for(int i=0;i<n;i++){
        for(int j=sum;j>=s[i];j--){
            if(dp[j-s[i]]) dp[j]=1;
        }
    }

    vector<ll> r;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
            r.pb(i);
    }
    cout << r.size() << endl;
    for (auto u : r)
        cout << u << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}