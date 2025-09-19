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
#define sz(x) ((int)(x).size())
#define fi first                           
#define se second                          
#define mp make_pair                       
#define pb push_back                      
#define eb emplace_back                   
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(a); i>=(b); --i)



ll gcd(ll a, ll b) { 
    return b ? gcd(b, a % b) : a;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vll nums(n), querie(q);
    vll newArr;
    unordered_map<ll,ll>mpp1;
    unordered_map<ll,vector<ll>>mpp;
    unordered_map<ll,ll>mpp2;
    rep(i,0,n) {
        cin>>nums[i];
        // s.insert(nums[i]);
        mpp[nums[i]].pb(i);
        if((nums[i]&1)==0) mpp2[nums[i]] = nums[i];
    }
    rep(i,0,q) cin>>querie[i];
    vll queries;
    for(auto it:querie){
        if(mpp1.find(it)==mpp1.end()){
            mpp1[it]++;
            queries.pb(it);
        }
    }

    for(int i = 0; i<queries.size(); i++){
        ll query = queries[i];
        ll toDivide = 1LL<<query;
        ll toAdd = 1LL<<(query-1);
        for(auto &it:mpp2){
            if((it.se % toDivide) == 0){
                it.se += toAdd;
            }
        }
    }
    vll ans(n);
    for(auto it:mpp){
        int val = it.fi;
        for(auto i:it.se){
            if(mpp2.find(val)!=mpp2.end())
            ans[i] = mpp2[val];
            else ans[i] = val;
        }
    }
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;






    // int size = newArr.size();
    // rep(i,0,q){
    //     ll query = queries[i];
    //     ll power = 1<<query;
    //     ll toAdd = 1<<(query-1);
    //     rep(j,0,size){
    //         if(newArr[j]%power == 0){
    //             newArr[j]+=toAdd;
    //         }
    //     }
    // }
    // ll j = 0;
    // // for(auto it:newArr) cout<<it<<" ";
    // // cout<<endl;
    // for(ll i = 0; i<n; i++){
    //     if(nums[i]&1) cout<<nums[i]<<" ";
    //     else cout<<newArr[j++]<<" ";
    // }
    // cout<<endl;
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

