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


bool b[2005][2005];
int dp[2005];
int main(){
    //freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);

    forn(j, t) {
        memset(b, 0, sizeof b);
        memset(dp, -1, sizeof dp);
        int n, q;
        cin >> n >> q;

        bool some = false;
        forn(i, q) {
            int x, y;
            cin >> x >> y;
            b[x][y] = b[y][x] = 1;
        }
        /*
            if(b[x] == -1 && b[y] == -1) {
                b[x] = 0;
                b[y] = 1;
            } else if(b[x] == -1) {
                if(b[y]) b[x] = 0;
                else b[x] = 1;
            } else if(b[y] == -1) {
                if(b[x]) b[y] = 0;
                else b[y] = 1;
            } else {
                if(b[x] == b[y]) some = true;
            }
        }
        */
        queue<int> qu;
        for(int k=1; k <=n; k++) {
            if(dp[k] == -1) {
                qu.push(k);
                dp[k] = 0;
                while(!qu.empty()){
                    int node = qu.front();
                    qu.pop();

                    forn(i, n+1) {
                        if(b[node][i]) {
                            if(dp[i] != -1) {
                                if(dp[node] == dp[i]) some = true;
                            } else {
                                if(dp[node]) dp[i] = 0;
                                else dp[i] = 1;
                                qu.push(i);
                            }
                        }
                    }
                    if(some) break;
                }
            }
            if(some) break;
        }
        cout << "Scenario #"<<j+1<<":" << endl;
        if(some) cout << "Suspicious bugs found!" << endl;
        else cout << "No suspicious bugs found!" << endl;
    }
    
    return 0;
}
