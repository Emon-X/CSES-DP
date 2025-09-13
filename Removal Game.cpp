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

void domain_expension()
{
    ll n;
    cin >> n;
    vector<ll>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    ll sum = accumulate(all(s),0LL);
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));

    for(int i=0;i<n;i++) dp[i][i]=s[i];
    
    for(int len=2;len<=n;len++) {
        for(int l=0;l+len-1<n;l++) {
            ll r = l + len - 1;
            dp[l][r] = max(s[l] - dp[l+1][r], s[r] - dp[l][r-1]);
        }
    }
    cout << (sum+dp[0][n-1])/2 << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}