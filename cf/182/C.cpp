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

int n, negs;
bool if_zero;

int main(){

    cin >> n;
    negs = 0;
    if_zero = false;
    vector<int> arr;
    forn(i, 2*n - 1){
        int tmp;
        cin >> tmp;
        if (tmp < 0) negs++;
        else if (tmp == 0) if_zero = true;
        arr.pb(tmp);
    }

    int total = 0;
    if(n%2){ // odd
        forn(i, 2*n - 1) total += abs(arr[i]);
        cout << total << endl;
        return 0;
    } else { // even 
        if(if_zero || !(negs%2)){ 
            forn(i, 2*n - 1) total += abs(arr[i]);
        } else {
            int minimum;
            forn(i, 2*n - 1) total += abs(arr[i]);
            forn(i, 2*n - 1) minimum = min(minimum, abs(arr[i]));
            total -= 2*minimum;
        }
        cout << total << endl;
        return 0;
    }
}
