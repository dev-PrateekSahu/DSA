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
    string s;
    cin>>s;
    int n = s.length();
    string compare = s;
    int cnt0 = 0, cnt1 = 0;
    int init0 = -1, init1 = -1;
    for(int i = 0; i<n;i++){
        if(s[i]=='0'){
            if(init0==-1){
                init0 = i;
            }
            cnt0++;
        }else{
            init1 = i;
            cnt1++;
        }
    }
    
    if(cnt0==cnt1){
        cout<<0<<endl;return;
    }
    if(cnt0==0||cnt1==0){
        cout<<s.length()<<endl;return;
    }
    int mini = min(cnt0,cnt1);
    int tempCnt0 = 0, tempCnt1 = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='0' && tempCnt0!=mini){
            tempCnt0++;
            s[i] = '1';
        }else if (s[i]=='1' && tempCnt1!=mini){
            s[i] = '0';
            tempCnt1++;
        }
    }
    int cnt = 0;
    int ptr1 = 0, ptr2 = 0;
    while(ptr1<n && ptr2<n){
        if(s[ptr1]==compare[ptr2]){
            cnt++;
            ptr1++;
        }else{
            ptr1++;
            ptr2++;
        }
    }
    // cout<<" s : "<<s<<endl;
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

