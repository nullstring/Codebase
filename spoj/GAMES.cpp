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

ll gcd(ll a, ll b) {
    while(a&&b) {
        if(a>b) a %= b;
        else b %= a;
    }
    return a+b;
}

int main(){
//    freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);

    while(t--) {
        string s;
        //double f;
        cin >> s;
        int i=0;
        for(i=0;i< s.length();i++) if(s[i] == '.') break;
        if(i == s.length()) {
            cout << 1 << endl;
            continue;
        }
        i++;
        //cout << "{i " << i << endl;
//        cout << "i " << i << endl;
        int len = s.length()-i;
        /*
        bool done = false;
        for(int j = i;j<s.length(); j++) {
            ll x = pow(10, (len-j+i));
            ll p = 0;
            for(int k=j; k<s.length(); k++) {
                p += s[k]-'0';
                p *= 10;
            }
            p /= 10;
  //          cout << x << " " << p << endl;
            if(p == 0) {
                ll res = pow(10, (j-i));
                ll g = gcd(res, (ll)res*(atof(s.c_str())));
                res = res/g;
                cout << res << endl;
               
                //cout << pow(10, (j-i)) << endl;
                done = true;
                break;
            } else if(x%p == 0) {
                ll res = pow(10, (j-i))*x/(p);
                ll g = gcd(res, (ll)res*(atof(s.c_str())));
                res = res/g;
                cout << res << endl;
                done = true;
                break;
            }
        }
        */
        ll x = 0;
        for(int j=i; j<s.length(); j++) x = x*10 + (s[j]-'0');
        //cout << "x " << x << endl;
        ll res = pow(10, len);
        ll g = gcd(res, x);
        res = res/g;
        cout << res << endl;

        
   }
    
    return 0;
}
