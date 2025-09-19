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
    vll nums(n);
    rep(i,0,n) cin>>nums[i];
    ll start = 0, end = n-1;
    ll init = 1;
    bool poss = false;
    while(start<end){
        if(nums[start]==init) start++;
        else if (nums[end]==init) end--;
        else{
            poss = true;
            break;
        }
        init++;
    }
    if(!poss){
        cout<<-1<<endl;
        return;
    }
    start = 1;
    end = n;
    ll startIndex = 0, endIndex = n-1;
    while(startIndex<n){
        if(nums[startIndex]!=start){
            break;
        }else{
            start++;
            startIndex++;
        }
    }
    while(endIndex>=0){
        if(nums[endIndex]!=end){
            break;
        }else{
            end--;
            endIndex--;
        }
    }
    cout<<startIndex+1<<" "<<endIndex+1<<endl;
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

