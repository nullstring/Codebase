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

vector<int> parseIntToVector( ll t ) {
    vector<int> arr;
    while( t ) {
        arr.pb(t%10);
        t /= 10;
    }
    reverse(all(arr));
    return arr;
}

int dp[5005];

int main(){

    while(1) {
        // get input.
        string arr;
        cin >> arr;
        if ( arr == "0" ) return 0;

        forn(i, arr.size()) {
            arr[i] -= '0';
        }

        // On every iteration check,
        // Add dp[i-1] + dp[i-2]
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 1; i < arr.size(); i++) {
            // from index 1 to n - 1.
            if( arr[i] > 0 ) dp[i] += dp[i - 1];

            // from index 2 to n - 1
            int two = arr[i - 1]*10 + arr[i];
            if( two >= 10 && two <= 26) dp[i] += dp[(i-2 < 0)? 0 : i-2];
        }
        cout << dp[arr.size() - 1] << endl;
    }
    return 0;
}
