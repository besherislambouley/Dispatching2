#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
ll n , m , ans ;
vll v[100009] ;
ll c[100009] , l[100009] , sz[100009] ;
mset<ll>s[100009];
ll sum[100009] ;
void dfs ( int node , int p ) {
	pi mx = { -1 , -1 } ;
	for ( auto u : v[node] ) {
		if ( u == p ) C ;
		dfs ( u , node ) ;
		mx = max ( mx , { (int)s[u].size() , u } ) ;
	}
	if ( mx.se != -1 ) {
		swap ( s[mx.se] , s[node] ) ;
		for ( auto u : v[node] ) {
			sum [node] += sum[u] ;
			if ( u == p || u == mx.se ) C ;
			for ( auto it : s[u] ) {
				s[node].ins ( it ) ;
			}
		}
	}
	s [node] .ins ( c[node] ) ;
	sum [ node ] += c[node] ;
	while ( sum [ node ] > m ) {
		sum [ node] -= * ( -- s[node].end() ) ;
		s [node] . era ( ( -- s[node].end() ) ) ;
	}
	ans = max ( ans , (ll)s[node].size() * l[node] ) ;
}
int main () {
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int b ;
		cin >> b >> c[i] >> l[i] ;
		b -- ;
		if ( b == -1 ) C ;
		int a = i ;
		v [a] .pb ( b ) ;
		v [b] .pb ( a ) ;
	}
	dfs  ( 0 , 0 ) ;
	cout << ans << endl ;
}
