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
    ll n;
    cin>>n;
    vll nums(n);
    rep(i,0,n) cin>>nums[i];
    vll prefix(n),suffix(n);
    ll sum = 0;
    rep(i,0,n){
        sum+=nums[i];
        prefix[i] = (sum);
    }
    sum = 0;
    per(i,n-1,0){
        sum+=nums[i];
        suffix[i] = (sum);
    }

    // cout<<"PREFIX : ";
    // for(auto it:prefix) cout<<it<<" ";
    // cout<<endl<<"SUFFIX : ";
    // for(auto it:suffix) cout<<it<<" ";
    // cout<<endl;

    ll cnt = 0;
    ll start = 0, end = n-1;
    while(start<end){
        if(prefix[start]==suffix[end]){
            cnt = start + n - end + 1;
            start++;
            end--;
        }else if (prefix[start]>suffix[end]){
            end--;
        }else start++;
    }
    cout<<cnt<<endl;
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

