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
const ll INF = 1e9;
void domain_expension()
{
    ll n,x;
    cin >> n >> x;
    vector<ll>c(n);
    for(int i=0;i<n;i++) cin >> c[i];

    vector<ll>dp(x+1,INF);
    dp[0]=0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-c[j]>=0){
                dp[i]=min(dp[i],dp[i-c[j]]+1);
            }
        }
    }
    cout << (dp[x]==INF ? -1:dp[x]) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}