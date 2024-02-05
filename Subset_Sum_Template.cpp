#include <bits/stdc++.h>
#define ll long long int
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;

bool subsetSumToK(ll n, ll k, vector<ll> &arr) {
    
    vector<vector<ll>>dp_tab(n,vector<ll>(k+1,0));

    for(int i=0;i<k+1;i++){
        if(i==arr[0]){
            dp_tab[0][i]=1;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<k+1;j++){
            if(dp_tab[i-1][j]==1){
                dp_tab[i][j]=1;
                if(j+arr[i]<=k) dp_tab[i][j+arr[i]]=1;
            }
            if(j==arr[i]) dp_tab[i][j]=1;
        }
    }

    return dp_tab[n-1][k];
}

signed main(){
    ll n; cin>>n;
    vector<ll>arr(n);
    rep(i,0,n) cin>>arr[i];
    ll k; cin>>k;

    cout<<subsetSumToK(n,k,arr);
    return 0;
}
