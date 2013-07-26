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

int dp[105][505];
int sol[105][505];
int cost[105];
int fun[105];

int main(){

    while(1) {
        int b, p;
        scanf("%d %d",&b, &p);
        if(b == 0 && p == 0) return 0;
        
        memset(dp, 0, sizeof dp);
        memset(cost, 0, sizeof cost);
        memset(fun, 0, sizeof fun);
        memset(sol, 0, sizeof sol);
        forn(i, p) {
            cin >> cost[i+1] >> fun[i+1];
        }
        
        for(int i = 1; i <= p; i++) {
            for(int j = 0; j <= b; j++) {
                if(j >= cost[i]) {
                    dp[i][j] = max(dp[i-1][j], fun[i] + dp[i-1][j-cost[i]]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int i = 0;
        for(i=b; i>0; i--) {
            if(dp[p][i] != dp[p][i-1]) break;
        }
        //forn(i, p+1) {
            //forn(j, b+1) {
                //cout << dp[i][j] << " ";
            //}
            //cout << endl;
        //}
        cout << i << " " << dp[p][b] << endl;
    }
    return 0;
}
