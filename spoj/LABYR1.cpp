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

int maxx = 0;
bool arr[1005][1005];
bool visited[1005][1005];
struct node {
    int i;
    int j;
    int steps;
};
int c, r;
void bfs(int i, int j) {
    memset(visited, 0, sizeof visited);
    queue<node> q;
    struct node cur = {i, j, 0};
    q.push(cur);
    while(!q.empty()) {
        struct node top = q.front();
        q.pop();
        visited[top.i][top.j] = true;
        //cout << "hello" << endl;
        int how_many = 0;
        for(int x = -1; x <= 1; x++) {
            for(int y = -1; y <= 1; y++) {
                int next_r = top.i + x;
                int next_c = top.j + y;    
                if( x == 0 && y == 0) continue; 
                if( (x == 0 || y == 0) && next_r >= 0 && next_c >=0 && next_r < r && next_c < c && !visited[next_r][next_c] && arr[next_r][next_c]) {
                    how_many++;
                    struct node cur1 = { next_r, next_c, top.steps + 1 }; 
                    q.push(cur1);
                }
            }
        }
        if(how_many == 0) maxx = max(maxx, top.steps);
    }
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        maxx = 0;
        memset(arr, 0, sizeof arr);
        cin >> c >> r;

        forn(i, r) {
            string s;
            cin >> s;
            forn(j, c) {
                if(s[j] == '.') arr[i][j] = true;
            }
        }       
        //forn(i, r) {
            //forn(j, c) {
                //cout << arr[i][j] << " ";
            //}
            //cout << endl;
        //}

        bool one_complete = false;
        forn(i, r) { 
            forn(j, c) {
                if(arr[i][j]) {
                    int n = 0;
                    if(i-1 >=0 && arr[i-1][j]) n++; 
                    if(j-1 >=0 && arr[i][j-1]) n++; 
                    if(i+1 < r && arr[i+1][j]) n++; 
                    if(j+1 < c && arr[i][j+1]) n++; 
                    //cout << "n " << i << " " << j << " " << n << endl;
                    if(n == 1) {
                        bfs(i, j); 
                        one_complete = true;
                        break;
                    }
                } 
            }
            if(one_complete) break;
        }
        cout << "Maximum rope length is " << maxx << "." << endl;
    }
    
    return 0;
}
