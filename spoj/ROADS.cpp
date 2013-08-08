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

// dijkstra implementation with set<pair<int, int>>
typedef int T;
typedef pair<int, ii> iii;
#define V 105
#define MONEY 10005
#define INF 100000000
vector<int> toll[V][V];
T dp[V][MONEY];
vector<int> len[V][V];

int main(){

    int t;
    cin >> t;
    while(t--) {
        int m, n, r;
        cin >> m >> n >> r;

        forn(i, r) {
            int source, dest, length, toll_tmp;
            cin >> source >> dest;
            cin >> length >> toll_tmp;
            len[source-1][dest-1].pb(length);
            toll[source-1][dest-1].pb(toll_tmp);
        }
       
        forn(i, n) 
            forn(j, m + 1) dp[i][j] = INF;

        forn(i, m + 1) dp[0][i] = 0;

        //cout << endl;
        forn(t, m + 1) {
            for(int p = 0; p < n; p++) {
                for(int q = 0; q < n; q++) {
                    forn(i, toll[p][q].size()) {
                        if(t+toll[p][q][i] <= m) {
                            dp[q][t+toll[p][q][i]] = min(dp[q][t+toll[p][q][i]], dp[p][t] + len[p][q][i]);    
                        }
                    }
                }
            }
        }
 
        int minimum = INF;
        int index = -1;
        //forn(i, m + 1) { 
            //forn(j, m + 1) cout << dp[i][j] << " ";
            //cout << endl;
        //}
        
        forn(i, m + 1) { 
            if(minimum > dp[n-1][i]) {
                minimum = dp[n-1][i];
                index = i;
            }
        }
        if(minimum == INF) minimum = -1;
        cout << minimum << endl;
    }
    return 0;
}
