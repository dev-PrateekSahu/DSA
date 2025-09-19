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
    ll k;
    cin>>k;
    vll nums(n);
    rep(i,0,n) cin>>nums[i];
    map<ll,ll>freq;
    vll hashArr(n+1,0);
    vll req(n+1,INT_MAX);
    for(auto it:nums) {
        freq[it]++;
        hashArr[it]++;
    }
    for(auto it:freq){
        if(it.se % k != 0){
            cout<<0<<endl;return;
        }
    }

    for(auto it:freq){
        req[it.fi] = it.se/k;
    }

    ll cnt = 0;
    int j = 1;
    for(int i = 0; i<n; i++){
        vll tempHash (n+1,0);
        tempHash[nums[i]]++;
        cnt++;
        // int j = i+1;
        int initj = j;
        while(j<n){
            if(tempHash[nums[j]]+1 <= req[nums[j]]){
                tempHash[nums[j]]++;
                cout<<nums[j]<<" "<<tempHash[nums[j]]<<" "<<cnt<<endl;
                j++;
            }else {
                tempHash[nums[initj]]--;
                break;
            }
        }
        if(j==n) break;
        cnt += j-i+1;
        // i = j-1;
    }
    cout<<cnt<<endl;
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

