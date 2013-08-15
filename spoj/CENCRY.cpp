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

int dp[26];
char vow[] = {'a', 'e', 'i', 'o', 'u'};
char cons[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
int get_pos(char c, bool v) {
//cout << "inside: " << c << " " << v << endl;
    int i = 0;
    if(v){
        for(i = 0; i<5; i++) {
            if(c == vow[i]) return i;
        }
    } else {
        for(i = 0; i<21; i++) {
            if(c == cons[i]) return i;
        }
    }
}   
int main(){
//freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--) {
        memset(dp, 0, sizeof dp);
        string s;
        cin >> s;
        forn(i, s.length()) {
            int c = s[i] - 'a';
            bool v = false;
            forn(j, 5) if(s[i] == vow[j]) v = true; 
            int pos = get_pos(s[i], v);
            //cout << "pos: " << pos << endl;
            char put;
            if(v) {
                put = cons[((5*dp[c] + pos)%21)];
            } else {
                put = vow[((21*dp[c] + pos)%5)];
            }
            dp[c]++;
            cout << put;
        }
        cout << endl;
    }
    return 0;
}
