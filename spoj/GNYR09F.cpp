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

int dp[105][105][2];

int count_n(int n, int k, int prev) {
    if(n == 0 && k == 0) return 1;
    if(k == 0) return 0;
    if(n <= 0) return 0;
    if(n == k+1) return 1;
    if(dp[n][k][prev] != -1) return dp[n][k][prev];
    int sum = 0;

    if(prev) {
        sum += count_n(n-1, k-1, 1);
        sum += count_n(n-1, k, 0);
    } else {
        sum += count_n(n-1, k, 1);
        sum += count_n(n-1, k, 0);
    }

    //forn(i, n) {
    //    forn(j, k+1) {
    //        sum += count(i, j)*count(n-i-1, k-j);
    //    }
    //}
    //cout << n << " " << k << " " << dp[n][k] << endl;
    dp[n][k][prev] = sum;
    return sum;
}

int main(){

    //freopen("b.txt","r",stdin);
    int t;
    scanf("%d",&t);

    while(t--) {
        memset(dp, -1, sizeof dp);
        int num, n, k;
        cin >> num >> n >> k;
        cout << count_n(n-1, k, 1) + count_n(n-1, k, 0) << endl;
        //forn(i, n+1) {
        //    forn(j, k+1) {
        //        cout << dp[i][j] << " ";
        //    }
        //    cout << endl;
        //}

    }
    
    return 0;
}
