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

struct node {
    int a;
    int b;
    int c;

};
int dp[105];
bool cmp (const node& lhs, const node& rhs) {
    if(lhs.a != rhs.a) return lhs.a>rhs.a;
    else if(lhs.b != rhs.b) return lhs.b>rhs.b;
    else return lhs.c>rhs.c;
}
struct node in[100];
int main(){
//freopen("b.txt","r",stdin);
    while(1) {
        int t;
        scanf("%d",&t);
        memset(in, 0, sizeof in);
        memset(dp, 0, sizeof dp);
        if(!t) break;
        forn(i, t) {
            int x[3];
            cin >> x[0] >> x[1] >> x[2];
            forn(j, 3) {
                in[i*3+j].a = x[j];
                in[i*3+j].b = x[(j+1)%3];
                in[i*3+j].c = x[(j+2)%3];
                if(in[i*3+j].a > in[i*3+j].b) swap(in[i*3+j].a, in[i*3+j].b);
            }
        }
        int n = 3*t;
        sort(in, in+n, cmp);
        //forn(i, n)
            //cout << in[i].a << " " << in[i].b << " " << in[i].c << endl;
        //cout << endl;
        forn(i, n) {
            dp[i] = in[i].c;
            int maxx = 0;
            forn(j, i) {
                if(in[i].a < in[j].a && in[i].b < in[j].b)
                maxx = max(maxx, dp[j]); 
            }
            dp[i] += maxx;
        }
        
        //forn(i, n) cout << dp[i] << endl;;
        //cout << endl;
        int maxx = 0;
        forn(i, n) maxx = max(maxx, dp[i]);
        cout << maxx << endl;
    }

    
    return 0;
}
