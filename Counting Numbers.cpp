#include<bits/stdc++.h>
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
string s;

ll dp[20][2][2][12];

ll digit_dp(ll i,ll tight,ll started,ll prev)
{
    if(i==s.size()) return 1;

    if(dp[i][tight][started][prev]!=-1) return dp[i][tight][started][prev];

    ll ans = 0;
    ll lmt = tight ? s[i]-'0':9;

    for(int j=0;j<=lmt;j++){
        ll nwtight = (j==lmt && tight);
        ll nwstarted = (j>0 || started);
        if(!started) {
            ans += digit_dp(i+1, nwtight, nwstarted, j);
        } else if(prev != j) {
            ans += digit_dp(i+1, nwtight, nwstarted, j);
        }
    }
    return dp[i][tight][started][prev]=ans;
}

ll Solve(ll x)
{
    if(x<0) return 0;
    s = to_string(x);
    memset(dp,-1,sizeof(dp));
    return digit_dp(0,1,0,-1);
}

void domain_expension()
{
    ll l,r;
    cin >> l >> r;

    cout << Solve(r)-Solve(l-1) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}