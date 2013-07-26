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

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

#define sz(a) ((int)((a).size())) 
#define pb push_back 

#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

#define present(c,x) ((c).find(x) != (c).end())  // for set/map etc 
#define cpresent(c,x) (find(all(c),x) != (c).end())  // for vector 


int main(){
    int t;
    scanf("%d",&t);

    vi a,b;
    int c = 0;
    int negatives = 0;
    REP(i, t){
        int tmp;
        cin >> tmp;
        if (tmp < 0){
            if(a.size() > 0) {
                c = tmp;
                negatives++;
                b.pb(tmp);
            }
            else {
                a.pb(tmp);
            }
        } else if (tmp > 0){
            b.pb(tmp);
        } 
    }

    //cout << negatives << endl;
    cout << a.size();
    REP(i, a.size()) cout << " " << a[i];
    cout << endl;

    if ( negatives%2) cout << b.size() - 1; else cout << b.size();
    REP(i, b.size()) {
        cout << " "; 
        //if ( negatives%2 && b[i] == c) {} else cout << b[i];
        if ( (!(negatives%2)) || b[i] != c ) cout << b[i]; else {};
    }
    cout << endl;

    if ( negatives%2) cout << "2 "; else cout << "1 ";
    cout << "0 " ;
    if( negatives%2 ) cout << c ; else {}
    cout << endl;
    
    return 0;
}
