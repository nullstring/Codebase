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

int dp[1005][1005];
bool dp_b[1005][1005];
int main(){

    while(1) {
        int t;
        scanf("%d",&t);

        if(t == 0) break;
        memset(dp, 0, sizeof dp);
        memset(dp_b, 0, sizeof dp_b);
        forn(i, t) {
            cin >> dp[i][i];
        }

        forn(i, t) {
            forn(j, t) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        for(int len = 1; len < t; len++) {
            for(int i=0; i+len<t; i++) {
                int j = i+len;
                if(dp[i][j-1] + dp[j][j]> dp[i-1][j] + dp[i][i]) {
                    dp[i][j] = dp[i][j-1] + dp[j][j];
                    dp_b[i][j] = true;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][i];
                }
            }
        }

        forn(i, t) {
            forn(j, t) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
