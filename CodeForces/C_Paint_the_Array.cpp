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

    ll hcf1 = nums[0], hcf2 = nums[1];
    ll maxi = 0;
    rep(i,0,n){
        if(i%2==0){
            hcf1 = gcd(hcf1,nums[i]);
        }else{
            hcf2 = gcd(hcf2,nums[i]);
        }
    }
    // cout<<max(hcf1,hcf2)<<endl;
    // cout<<hcf1<<" "<<hcf2<<endl;
    bool poss1 = true, poss2 = true;
    rep(i,0,n){
        if(i%2==0){
            if(nums[i]%hcf2==0) poss2 = false;
        }else{
            if (nums[i]%hcf1==0) poss1 = false;
        }
    }
    if(poss1==true){
        cout<<hcf1<<endl;
    }else if(poss2==true){
        cout<<hcf2<<endl;
    }else cout<<0<<endl;
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

