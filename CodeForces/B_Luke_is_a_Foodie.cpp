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
    ll n,x;
    cin>>n>>x;
    vll nums(n);
    rep(i,0,n) cin>>nums[i];

    vll diff;
    rep(i,0,n-1){
        // ll temp = abs(nums[i]-nums[i+1]);
        // if(temp%x==0) diff.pb(temp/x);
        diff.pb(nums[i]-nums[i+1]);    
    }
    int cnt = 0;
    ll sum = 0;
    for(auto it:diff){cout<<it<<" ";sum+=it;}
    cout<<endl;
    cout<<sum<<endl;
    cout<<endl;




    // OLD LOGIC
    // ll diff = 2*x;
    // int index = 0;
    // int cnt = 0;
    // rep(i,index,n){
    //     // index = nums[i];
    //     // cout<<"I : "<<i<<endl;
    //     rep(j,i,n){
    //         if(abs(nums[i]-nums[j])>diff){
    //             cnt++;
    //             i = j-1;
    //             // cout<<"J : "<<j<<endl;
    //             break;
    //         }

    //     }
    // }
    // // cout<<endl;
    // cout<<cnt<<endl;
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

