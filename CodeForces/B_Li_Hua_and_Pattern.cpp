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
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>>nums(n,vector<ll>(n,0));
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n; j++){
            cin>>nums[i][j];
        }
    }
    
    vector<vector<ll>> original = nums;
    reverse(all(nums));
    for(auto &it:nums) reverse(all(it));
    ll difference = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(original[i][j]!=nums[i][j]) difference++;
            // cout<<nums[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<endl;
    // cout<<difference<<endl;
    if(difference<=k)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

