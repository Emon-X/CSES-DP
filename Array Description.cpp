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
    ll n,m;
    cin >> n >> m;
    vector<ll>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    vector<vector<ll>>dp(n+1,vector<ll>(m+1));
    if(s[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]=1;
    }
    else dp[0][s[0]]=1;

    for(int i=0;i<n-1;i++)
    {
       for(int x=1;x<=m;x++){

        for(auto y:{x-1,x,x+1})
        {
            if(1<=y && y<=m){
                if(s[i+1]!=0 && s[i+1]!=y) continue;

                dp[i+1][y]+=dp[i][x];
                if(dp[i+1][y]>=mod) dp[i+1][y]-=mod;
            }
        }
        }
    }
    ll ans = 0;

    for(int i = 1;i<=m;i++){
        ans+=dp[n-1][i];
        if(ans>=mod) ans-=mod;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}