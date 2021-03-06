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
#define TIME 255
#define INF 100000000
T e[V][V];
T d[V][TIME];
T time_arr[V][V];
T operation(T a, T b) {
    return a + b;
}
void dijkstra(int nv, int source, int dest, T noEdgeValue, int MAX_TIME) {
    // clear dijkstra array.
    forn(i, nv) forn(j, MAX_TIME + 1) d[i][j] = noEdgeValue;
    d[source][MAX_TIME] = 0 ;
    
    set<iii> q;
    q.insert(iii(d[source][MAX_TIME], ii(source, MAX_TIME)));

    while(!q.empty()) {

        //forn(i, nv) {
            //forn(j, MAX_TIME + 1)
                //cout << d[i][j] << " ";
            //cout << endl;
        //}
        //cout << endl;

        // change this rbegin to begin for <. 
        iii top = *(q.begin());
        q.erase(top);

        int s = top.second.first;
        int s_time = top.second.second;
        //cout << "s_time " << s_time << endl;
        T val = top.first;
        //forn(i, nv) {
            //forn(j, nv) cout << e[i][j] << " ";
            //cout << endl;
        //}
        forn(t, nv) {
            // remove no edge and self edge cases.
            if(s == t || e[s][t] == noEdgeValue) continue;
            int op = operation(d[s][s_time], e[s][t]);
            //cout << "op " << op << endl;
            // for every other edges, relax that edge.
            int t_time = s_time-time_arr[s][t];
            if(t_time >= 0 && d[t][t_time] > op) {
                //cout << t << endl;
                q.erase(iii(d[t][t_time], ii(t, t_time)));
                d[t][t_time] = op;
                q.insert(iii(d[t][t_time], ii(t, t_time)));
                //q.insert(ii(d[t], t));
            }
        }
    }
    int minimum = INF, index = -1;
    forn(i, MAX_TIME + 1) {
        if(d[dest][i] <= minimum) {
            minimum = d[dest][i];
            index = i;
        }
    };
    if(index == -1 || minimum == INF) cout << -1 << endl;
    else cout << minimum << " " << MAX_TIME - index;
    cout << endl;
}


int main(){

    int t;
    scanf("%d",&t);
    while(t--) {
        int n, totalTime;
        cin >> n >> totalTime;
        //memset(time_arr, INF, sizeof time_arr);
        //memset(risk, INF, sizeof risk);

        forn(i, n)
            forn(j, n) time_arr[i][j] = INF; 
        forn(i, n)
            forn(j, n) e[i][j] = INF; 
 
        forn(i, n)
            forn(j, n) cin >> time_arr[i][j]; 
        forn(i, n)
            forn(j, n) cin >> e[i][j]; 
        
        dijkstra(n, 0, n-1, INF, totalTime);

        //forn(i, n) {
            //forn(j, totalTime + 1) cout << dp[i][j] << " ";
            //cout << endl;
        //}

        // Dijkstra

        ////forn(i, n) dp[i][0] = 0; 
        //for (int t = 1; t < totalTime + 1; t++) {
            //forn(i, n) bf[0][i] = INF;
            //bf[0][0] = 0;
            //for(int times = 1; times < n; times++) {
                //forn(i, n) bf[times][i] = bf[times-1][i];
                //// do this for each edge.
                //for(int p = 0; p < n-1; p++) {
                    //for(int succ = 0; succ < n-1; succ++) {
                        //if(p == succ) continue;
                        //if() 
                        ////dp[p][t] = min(dp[p][t], dp[prev][t-time_arr[prev][p]] + risk[prev][p]);
                    //}
                //}
            //}
        //}

        //forn(i, n) {
            //forn(j, totalTime + 1) cout << dp[i][j] << " ";
            //cout << endl;
        //}
    }
    return 0;
}
