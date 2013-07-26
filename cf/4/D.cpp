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

int n, cw, ch;
vector< pair<int, int> > arr;
int dp[5005];
int bt[5005];
int main(){
    cin >> n >> cw >> ch;
    forn(i, n) dp[i] = 0;
    forn(i, n) bt[i] = i;
    forn(i, n){
        int w, h;
        cin >> w >> h;
        arr.pb(mp(w, h));
    }

    sort(all(arr));

    forn(i, n){ 
        if(arr[i].first > cw && arr[i].second > ch){
            int maximum = 0;
            int max_ind = i;
            forn(j, i){
                
                if( arr[i].first > arr[j].first && arr[i].second > arr[j].second ){
                    if(maximum < dp[j]){
                        maximum = dp[j];
                        max_ind = j;
                    }
                }
            }
            bt[i] = max_ind;
            dp[i] = maximum + 1;
        } else {
            dp[i] = 0;
        }
    }
    cout << dp[n-1] << endl;
    stack<int> res;
    int root_ind = n-1;
    while( root_ind != bt[root_ind] ) {
        root_ind = bt[root_ind];
        res.push(root_ind);
    }
    while(!res.empty()) {
        cout << res.top() + 1 <<endl;
        res.pop();
    }
    return 0;
}
