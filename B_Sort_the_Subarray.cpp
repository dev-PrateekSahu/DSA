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
    vll initArr(n), finalArr(n);
    rep(i,0,n) cin>>initArr[i];
    rep(i,0,n) cin>>finalArr[i];
    if(is_sorted(all(finalArr))){
        cout<<1<<" "<<n<<endl;
        return;
    }
    ll start = 0, end = n-1;
    bool findStart = false, findEnd = false;
    // while(start<end){
    //     if(initArr[start]!=finalArr[start] && !findStart){
    //         findStart = true;
    //         start += 1;
    //     }
    //     if(initArr[end]!=finalArr[end] && !findEnd){
    //         findEnd = true;
    //         end += 1;
    //     }
    //     if(findStart&&findEnd) break;
    //     if(!findStart) start++;
    //     if(!findEnd) end--;
    // }

    rep(i,0,n){
        if(finalArr[i]!=initArr[i]){
            start = i+1;
            break;
        }
    }
    per(i,n-1,0){
        if(finalArr[i]!=initArr[i]){
            end = i+1;
            break;
        }
    }
    bool leftSorted = is_sorted(finalArr.begin()+start-1, finalArr.end());
    if(leftSorted){
        cout<<start<<" "<<n<<endl;
        return;
    }
    cout<<start<<" "<<end<<endl;
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

