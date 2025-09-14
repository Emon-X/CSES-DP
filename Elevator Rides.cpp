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
    ll n,x;
    cin >> n >> x;
    vector<ll>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    vector<pair<ll,ll>>dp((1LL<<n),{n+1,0});// rides,last rides weight
    dp[0]={1,0};

    for(int mask=0;mask<(1LL<<n);mask++)
    {
        for(int i=0;i<n;i++){
            if(mask&(1LL<<i)){
                auto prev = dp[mask ^ (1LL<<i)];
                ll curr_weight = prev.second;
                ll rides = prev.first;
                if(curr_weight+s[i]<=x){

                    auto option = make_pair(rides,curr_weight+s[i]);
                    if(option<dp[mask]) dp[mask] = option;
                }
                else{
                    auto option = make_pair(rides+1,s[i]);
                    if(option<dp[mask]) dp[mask] = option;
                }
            }
        }
    }
    cout << dp[(1LL<<n)-1].first << endl;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}