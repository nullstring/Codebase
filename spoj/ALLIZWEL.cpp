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

char inp[105][105];
bool visited[105][105];
string s = "ALLIZZWELL";
int r, c;
bool dfs(int a, int b, int n) {
    if(n == 9) return true;
    visited[a][b] = true;
    //cout << a << " " << b << " " << n << endl;

    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int aa = a+i;
            int bb = b+j;
            if(aa>=0 && bb>=0 && aa<r && bb<c && !visited[aa][bb]) {
                if(inp[aa][bb] == s[n+1] && dfs(aa, bb, n+1)) return true; 
            }
        }
    }
    visited[a][b] = false;
    return false;
}
//bool bfs(int r, int c, int x, int y) {
    //bool visited[105][105];
    //memset(visited, 0, sizeof visited);

    //queue< pair<pair<int, int>, int> > q;
    //q.push(mp(mp(x, y), 0));
    //visited[x][y] = true;
    //while(!q.empty()) {
        //pair<ii, int> top = q.front();
        //q.pop();

        //int a = top.first.first;
        //int b = top.first.second;
        //int n = top.second;
        //if(n == 9) return true;
        //if(n > 9) continue;
        //visited[a][b] = true;
        ////cout << a << " " << b << " " << n << endl;
        //for(int i=-1; i<=1; i++) {
            //for(int j=-1; j<=1; j++) {
                //int aa = a+i;
                //int bb = b+j;
                //if(aa<0 || bb<0 || aa>=r || bb>=c || visited[aa][bb]) continue;
                //if(inp[aa][bb] == s[n+1]) {
                    //q.push(mp(mp(aa, bb), n+1));
                //}
            //}
        //}
    //}
    //return false;
//}
int main(){
    //freopen("ALLIZWEL.txt","r",stdin);
    int t;
    scanf("%d",&t);

    while(t--) {
        //int r, c;
        memset(visited, 0, sizeof visited);
        scanf("%d %d", &r, &c);
        forn(i, r) scanf("%s", inp[i]);
        
        bool br = false;
        forn(i, r) {
            forn(j, c) {
                if(inp[i][j] == 'A') {
                    if(dfs(i,j,0)) {
                        printf("YES\n");
                        br = true;
                        break;
                    }
                    //memset(visited, 0, sizeof visited);
                }
            }
            if(br) break;
        }
        if(!br) printf("NO\n");
    }
    
    return 0;
}
