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
typedef double T;
#define V 105
#define INF 200
T e[V][V];
T d[V];
T operation(T a, T b) {
    return a/100*b;
}
T dijkstra(int nv, int source, int dest, T noEdgeValue) {
    // clear dijkstra array.
    forn(i, nv) d[i] = noEdgeValue;
    d[source] = 100 ;
    
    set<ii> q;
    q.insert(ii(d[source], 0));

    while(!q.empty()) {

        //forn(i, nv) cout << d[i] << " ";
        //cout << endl;

        // change this rbegin to begin for <. 
        ii top = *(q.rbegin());
        q.erase(top);

        int s = top.second;
        T val = top.first;
        forn(t, nv) {
            // remove no edge and self edge cases.
            if(s == t || e[s][t] == noEdgeValue) continue;
            double op = operation(d[s], e[s][t]);
            // for every other edges, relax that edge.
            if(d[t] < op) {
                //cout << t << endl;
                q.erase(ii(d[t], t));
                d[t] = op;
                q.insert(ii(d[t], t));
            }
        }
    }
    return (d[dest] == noEdgeValue)? (-1) : d[dest];
}

int main(){
    
    while(1) {
        int nv, ne;
        //scanf("%d %e",&nv, &ne);
        cin >> nv;
        if(nv == 0) return 0;
        cin >> ne;
        
        forn(i, nv) forn(j, nv) e[i][j] = 0;
        forn(i, ne) {
            int a, b;
            T p;
            scanf("%d %d %lf",&a, &b, &p);
            e[a-1][b-1] = e[b-1][a-1] = p;
        }

        // Dijkstra
        printf("%.6f percent\n",dijkstra(nv, 0, nv-1, 0));
    }
    return 0;
}
