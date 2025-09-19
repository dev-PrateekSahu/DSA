#include <bits/stdc++.h> // CODEFORCES
using namespace std;

// Common type aliases
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Macros for convenience
#define all(x) (x).begin(), (x).end()        
#define rall(x) (x).rbegin(), (x).rend()        
#define sz(x) ((ll)(x).size())
#define fi first                           
#define se second                          
#define mp make_pair                       
#define pb push_back                      
#define eb emplace_back                   
#define rep(i,a,b) for(ll i=(a); i<(b); ++i)
#define per(i,a,b) for(ll i=(a); i>=(b); --i)



ll gcd(ll a, ll b) { 
    return b ? gcd(b, a % b) : a;
}

void solve(){
    ll n;
    cin>>n;
    vll nums(n);
    vll prefixSum;
    ll sum = 0;
    rep(i,0,n){
        cin>>nums[i];
    }
    vector<pair<ll,ll>>sortedArr;
    rep(i,0,n) sortedArr.pb({nums[i],i});
    sort(all(sortedArr));
    rep(i,0,n){
        sum+=sortedArr[i].fi;
        prefixSum.pb(sum);    
    }


    // for(auto it:prefixSum) cout<<it<<" ";
    // cout<<endl;
    map<ll,ll>mpp;
    rep(i,0,n){
        mpp[sortedArr[i].fi] = prefixSum[i];
    }
    rep(i,0,n) prefixSum[i] = mpp[sortedArr[i].fi];
    // for(auto it:prefixSum) cout<<it<<" ";
    // cout<<endl;
    vector<ll>ans(n);
    ans[sortedArr[n-1].se] = n-1;
    int finalAns = n-1;
    for(int i = n-2; i>=0; i--){
        if(prefixSum[i]>sortedArr[i+1].fi){
            ans[sortedArr[i].se] = finalAns;
        }else{
            finalAns = i;
            ans[sortedArr[i].se] = i;
        }
        // cout<<prefixSum[i]<<" "<<sortedArr[i].fi<<" "<<finalAns<<endl;
    }
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    // For local testing: redirect input/output to files
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

