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
    ll q;
    cin>>q;
    vll nums(n);
    rep(i,0,n) cin>>nums[i];
    ll prev = -1;
    bool detectTwo = false;
    ll totalSum = accumulate(all(nums),0LL);
    for(int i = 0; i<q; i++){
        ll t;
        cin>>t;
        if(t==2){
            ll temp;
            cin>>temp;
            prev = temp;
            totalSum = n*temp;
            cout<<n*temp<<endl;
        }else{
            ll index;
            cin>>index;
            ll toBeReplacedBy;
            cin>>toBeReplacedBy;
            ll valueAtIndex = nums[index];
            if(valueAtIndex!=prev){
                
            }

        }
    }
    
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
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}

