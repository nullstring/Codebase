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

int dp[20005];
int main(){
//freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, h1, h2;
        cin >> n >> h1 >> h2;
        dp[0] = -1;
        //cout << n << endl;
        for(int i=1;i< (n+1); i++) {
        //cout << "i " << i << endl;
            if(i == h1) {
                dp[i] = i;
            } else {
                cin >> dp[i];
            }
        }
        //forn(i, n+2) cout << dp[i] << endl;

        int dp1[n+5];
        memset(dp1, -1, sizeof dp1);

        int old = h2, next = dp[h2];
        dp1[h2] = h2;
        while(dp1[next] == -1) {
            dp1[next] = old;
            old = dp[old];
            next = dp[next];
        }
        for(int i = 1;i< n+1; i++) {
            if(dp1[i] == -1) dp1[i] = dp[i];
        }
        
        for(int i = 1;i< n+1; i++) {
            if(i != h2) cout << dp1[i] << " ";
        }
        cout << endl;

        
        //forn(i, n+1) cout << dp1[i] << endl;
    }

    
    return 0;
}
