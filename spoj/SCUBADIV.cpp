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
#define MAX 1660
int dp[MAX][MAX];
int ox[1005];
int ni[1005];
int w[1005];
int main(){
//    freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int O, N;
        cin >> O >> N;

        int n;
        cin >> n;

        int maxx = O*N+1; 
        forn(i, maxx) forn(j, maxx) dp[i][j] = INF;
        dp[0][0] = 0;
        memset(ox, 0, sizeof ox);
        memset(ni, 0, sizeof ni);
        memset(w, 0, sizeof w);
        forn(i, n) scanf("%d %d %d", &ox[i+1], &ni[i+1], &w[i+1]);
        for(int i=1; i<= n; i++) {
            for(int j=maxx; j>=ox[i]; j--) {
                for(int k=maxx; k>=ni[i]; k--) {
                    if(dp[j-ox[i]][k-ni[i]] != INF)
                    dp[j][k] = min(dp[j][k], dp[j-ox[i]][k-ni[i]] + w[i]);
                }
            }
        }

        int minn = INF;
        for(int i=O; i<maxx; i++) {
            for(int j=N; j<maxx; j++) {
                minn = min(minn, dp[i][j]);
            }
        }
        cout << minn << endl;
    }

    
    return 0;
}
