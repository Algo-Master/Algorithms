#include <bits/stdc++.h>
#define ll long long int
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;

ll knapsack(vector<ll> weight, vector<ll> value, ll n, ll mW) 
{
	vector<vector<ll>>dp_tab(n,vector<ll>(mW+1,0));

    for(int i=0;i<mW+1;i++){
        if(i==weight[0]){
            dp_tab[0][i]=value[0];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<mW+1;j++){
            if(dp_tab[i-1][j]>0){
                dp_tab[i][j]=max(dp_tab[i][j], dp_tab[i-1][j]);
                if(j+weight[i]<=mW) dp_tab[i][j+weight[i]]=max(dp_tab[i][j+weight[i]], dp_tab[i-1][j] + value[i]);
            }
            if(j==weight[i]) dp_tab[i][j]=max(dp_tab[i][j],value[i]);
        }
    }
	ll mx = 0;
	for(int i=0; i<=mW; i++){
		mx = max(mx, dp_tab[n-1][i]);
	}
	return mx;
}

signed main() {
    ll n; cin>>n;
    vector<ll> weight(n);
    rep(i,0,n) cin>>weight[i];
    vector<ll> value(n);
    rep(i,0,n) cin>>value[i];
    ll maxWeight; cin>>maxWeight;

    cout<<knapsack(weight, value, n, maxWeight);
}
