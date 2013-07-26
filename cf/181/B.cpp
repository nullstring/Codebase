//Harsh Mehta
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:300000000")


#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

/*
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
*/
// Usefull macros
typedef vector<int> vi; 
typedef vector< vi > vvi; 
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

#define MAX 50
bool g[MAX][MAX];
bool visited[MAX];
vector<int> cur;
vector< vector< int > > res[MAX];

void dfs(int node, int size){
    //cout << node << endl;
    visited[node] = true;
    cur.pb(node);
    for(int i=1; i<=size;i++) {
        if(g[node][i] && !visited[i]) {
            dfs(i, size); 
        }
    }
}

int main(){

    memset(g, 0, sizeof g);
    memset(visited, 0, sizeof visited);

    int n, m;
    scanf("%d %d", &n, &m);

    forn(i, m){
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = true;
    }

    for(int i = 1; i <= n; i++){
        if (!visited[i]){
            cur.clear();
            dfs(i, n);
            res[sz(cur)].pb(cur);
        }
    }
    //cout << "n " << n << endl;
    if( res[2].size() > res[1].size() ) {
//            cout << "2>1" <<endl;
        cout << "-1" << endl;
        return 0;
    }
    
    for(int i = n; i > 0; i--){
        if(i > 3 && sz(res[i])>0) {
            //cout << ">3 " << i << " " << sz(res[i]) <<endl;
            cout << -1 << endl;
            return 0;
        }
        else if( i == 3 ){
            forn(j, res[3].size()){
                forn(k, 3)
                    cout << res[3][j][k] << " ";
                cout << endl;
            }
        }
    }

    

    int k = 0;
    for(k = 0; k < res[2].size(); k++){
        cout << res[2][k][0] << " ";
        cout << res[2][k][1] << " ";
        cout << res[1][k][0] << " ";
        cout << endl;
    }

    for(int i=k; i < res[1].size(); i++){ 
        cout << res[1][i][0] << " ";
        if ( !((i+1-k)%3) ) cout << endl;
    } 
    
    return 0;
}
