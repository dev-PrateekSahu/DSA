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
    vll nums1(n), nums2(n);
    rep(i,0,n) cin>>nums1[i];
    rep(i,0,n) cin>>nums2[i];

    ll cnt = 1;
    ll prev = nums1[0];
    ll maxi = 1;
    ll start1 = 1, start2 = 0;
    while(start1<n && start2<n){
        if(nums1[start1]==prev){
            cnt++;
            // cout<<"1 : "<<cnt<<endl;
            start1++;
        }else if (nums2[start2]==prev){
            start2++;
            cnt++;
            // cout<<"2 : "<<cnt<<endl;
        }else{
            maxi = max(maxi,cnt);
            cnt = 1;
            // cout<<"3 : "<<cnt<<endl;
            prev = nums1[start1];
            start1++;
        }
        maxi = max(maxi,cnt);
    }
    while(start2<n){
        if(prev == nums2[start2]){
            cnt++;
            // cout<<"INC1 : "<<cnt<<endl;
        }else{
            prev = nums2[start2];
            maxi = max(maxi,cnt);
            cnt = 1;
            // cout<<"INC2 : "<<cnt<<endl;
            
        }
        start2++;
        maxi = max(maxi,cnt);
    }
    while(start1<n){
        if(prev == nums1[start1]){
            cnt++;
            // cout<<"INC3 : "<<cnt<<endl;
        }else{
            prev = nums1[start1];
            maxi = max(maxi,cnt);
            cnt = 1;
            // cout<<"INC4 : "<<cnt<<endl;
            
        }
        start1++;
        maxi = max(maxi,cnt);
    }
    cout<<maxi<<endl;
    // cout<<"\n";
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

