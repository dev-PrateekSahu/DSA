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
    int base = (n+2)/2;
    vll ans(n+1);
    ans[0] = base;
    vector<pll>avail;
    for(int i = 0; i<n; i++){
        avail.pb({nums[i],i+1});
    }
    sort(all(avail));
    reverse(all(avail));
    // if(n%2==1){
        int toDo = n;
        int index1 = base+1, index2 = base-1;
        int temp = 0;
        while(temp<n){
            // if(index2==0) index2 = n+1;
            if(temp%2==0){
                ans[avail[temp].se] = index1;
                index1++;
            }
            else {
                ans[avail[temp].se] = index2;
                index2--;
            }
            temp++;
        }
    // }else{

    // }
    // for(auto it:avail)cout<<it.fi<<" "<<it.se<<" ";
    ll cost = 0;
    int initx = ans[0];
    for(int i = 1; i<=n; i++){
        int diff = abs(initx - ans[i]);
        cost+= (diff * nums[i-1]);
    }
    cout<<2*cost<<endl;
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
    

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

