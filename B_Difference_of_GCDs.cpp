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


const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) { 
    return b ? gcd(b, a % b) : a;
}

void solve(){
    ll n;
    cin>>n;
    ll r,l;
    cin>>l>>r;
    // if(abs(r-l)>=r) {
    //     cout<<"YES"<<endl;
    //     cout<<r<<" "<<r+n-1<<endl;
    //     while(n--){

    //     }
    //     ll needed = n;
    //     // cout<<needed<<endl;
    //     return;
    // }
    // else cout<<"NO";
    // cout<<endl;
    ll cnt = 0;
    ll index = 1;
    vll ans;
    for(ll i = l; i<=r && cnt<n; i++){
        if(i%index == 0){
            index++;
            cnt++;
            ans.pb(i);
        }
    }  
    if(cnt==n){
        cout<<"YES"<<endl;
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }     
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

