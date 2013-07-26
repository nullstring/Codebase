//Harsh Mehta

//library includes 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>//setprecision()
#include <string>//s.length(),s.find("string"),s.find_last_of('char'),s.replace(from_pos,number_of_chars_to_replace,"string to replace"),s.c_str();
#include <cstring>//strcpy(s1,s2),strcmp(s1,s2),strcmpi(s1,s2),strstr(s1,s2)  returns address location of s2,strlen()
#include <cmath>//sin,cosec,sinh,acos,sqrt,pow,sort,atoi,atof,atol,ceil,exp,itoa,sprintf,modf
#include <cctype>//isdigit(),isalnum(),isspace(),ispunct()

using namespace std;
// Usefull macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<string> vs;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

#define present(c,x) ((c).find(x) != (c).end())  // for set/map etc 
#define cpresent(c,x) (find(all(c),x) != (c).end())  // for vector 

#define MOD 1000000007

long long getBinCoef(int n, int x){
    if( x > n ) return -1;
    if( x == n) return 1;
    long long r = 1;
    for(int i=1; i<=x ; i++){
        r = (r*n)%MOD;
        n--;
        r /= i;
    }
    return r;
}

int fact[1000000];
void calc_fact(int n){
    ll r = 1;
    fact[0] = 1;
    for(int i=1; i<n; i++){
        fact[i] = (fact[i-1] * i)%MOD;
    }
}
long long getBinCoef_Memoised(int n, int x){
    return 
}

bool is_good(int n, int a, int b){
    while( n ){
        int rem = n%10;
        n = n/10;
        if ( rem != a && rem != b) return false;
    }
    return true;
}

int a, b, n;
int main(){

    //int t;
    //scanf("%d",&t);
    cin >> a >> b >> n;
    int num = n*a;
    int diff = b - a;
    ll r = 0;
    for(int i=0; i<=n ; i++){
        if( is_good(num, a, b) ) r = ( r + (getBinCoef(n,i)%MOD) ) % MOD; 
        num += diff;
    }

    cout << r << endl; 
    
    return 0;
}
