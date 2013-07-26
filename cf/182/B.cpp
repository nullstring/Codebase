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


/*
 * arrIndex bSearch( arr, size, val )
 * If not found gives index of just greater value.
 * Note: If > highest then returns -1
 *
 */
typedef ll ARR_TYPE;
int bSearch(vector<ARR_TYPE> &arr, int arr_size, ARR_TYPE x ){
    int lo = 0;
    int hi = arr_size - 1;
    int mid = (lo + hi)/2;
    if( x > arr[hi] ) return -1;

    while( lo < hi){
        if(x == arr[mid]) return mid;
        else if(x < arr[mid]) {
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
        mid = (lo + hi)/2;
    }
    return mid;
}

int n, m;

int main(){

    ll bound = 0;
    cin >> n >> m;
    vector<ll> arr;
    forn(i, n){
        ll c, t;
        cin >> c >> t;
        bound += c*t;
        arr.pb(bound);
    }

    forn(i, m){
        ll moment;
        cin >> moment;
        cout << bSearch(arr, arr.size(), moment) + 1 << endl;
    }
    
    return 0;
}
