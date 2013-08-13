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

long long int dp_min[105][105];
long long int dp_max[105][105];

void reset(string s) {
    forn(i, s.length()) {
        if(i&1) continue;
        dp_min[i/2][i/2] = s[i] - '0';
        dp_max[i/2][i/2] = s[i] - '0';
    }
}

int main(){

    int t;
    scanf("%d",&t);

    while(t--) {
        memset(dp_max, 0, sizeof dp_max);
        string s;
        cin >> s;

        string op = "";
        int n = s.length()/2 + 1;
        int num[n];
        forn(i, s.length()) {
            if(i&1) op += s[i];
            else num[i/2] = s[i] - '0';
        }

        forn(i, s.length()) forn(j, s.length()) dp_min[i][j] = INF;
        reset(s);

        // dp_min
        for(int len = 1; len < n; len++) {
            for(int i = 0; i + len < n; i++) {
                int j = i + len;
                long long int minn = INF;
                for(int k = i; k < j; k++) {
                    if(op[k] == '*') minn = min(minn, dp_min[i][k] * dp_min[k+1][j]);
                    else minn = min(minn, dp_min[i][k] + dp_min[k+1][j]);
                }
                dp_min[i][j] = minn;
            } 
        } 

        // dp_max
        for(int len = 1; len < n; len++) {
            for(int i = 0; i + len < n; i++) {
                int j = i + len;
                long long int maxx = 0;
                for(int k = i; k < j; k++) {
                    if(op[k] == '*') maxx = max(maxx, dp_max[i][k] * dp_max[k+1][j]);
                    else maxx = max(maxx, dp_max[i][k] + dp_max[k+1][j]);
                }
                dp_max[i][j] = maxx;
            } 
        } 
        //forn(i, n) {
            //forn(j, n) {
                //cout << dp_min[i][j] << " ";
            //}
            //cout << endl;
        //}
        cout << dp_max[0][n-1] << " " << dp_min[0][n-1] << endl;
    }

    
    return 0;
}
