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

vector<int> findFactor(int n){
    vector<int>factor;
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i==0){
            factor.pb(i);
            factor.pb(n/i);
        }
    }
    return factor;
}

void solve(){
    ll n;
    cin>>n;
    vll nums(n);
    rep(i,0,n) cin>>nums[i];

    vector<int>factors;
    factors = findFactor(n);
    ll ans = abs(*min_element(all(nums)) - *max_element(all(nums)));
    int cnt = 0;
    // ll ans = 0;
    for(int i = 0; i<sz(factors); i++){
        int factor = factors[i];
        ll sum = 0;
        vll helper;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            cnt++;
            if(cnt==factor){
                helper.pb(sum);
                sum = 0;
                cnt = 0;
            }
        }
        if(sum) helper.pb(sum);
        ll mini = *min_element(all(helper));
        ll maxi = *max_element(all(helper));
        ans = max(ans, abs(mini-maxi));
    }
    cout<<ans<<endl;
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

