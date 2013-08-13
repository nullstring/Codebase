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

int dp[30][30];
int inp[30][30];
int main(){
//freopen("a.txt","r",stdin);
    int m, n;
    scanf("%d %d",&m, &n);

    int x, y;
    cin >> x >> y;
    x--;
    y--;
    
    forn(i, m) forn(j, n) cin >> inp[i][j];
    forn(i, m) forn(j, n) dp[i][j] = INF;
    

    dp[x][y] = 0;
    for(int i=x; i<m; i++) {
        for(int j=y; j<n; j++) {
            if(i-1 >= x) dp[i][j] = min(dp[i][j], dp[i-1][j]+inp[i][j]);
            if(j-1 >= y) dp[i][j] = min(dp[i][j], dp[i][j-1]+inp[i][j]); 
        }
    }
    
    //forn(i, m){
        //forn(j, n) cout << dp[i][j] << " ";
        //cout << endl;
    //}
    if(dp[m-1][n-1] <= inp[x][y])
    cout << 'Y' << " " << inp[x][y]-dp[m-1][n-1] << endl;
    else cout << 'N' << endl;
    return 0;
}
