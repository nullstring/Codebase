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

typedef double T;
#define DIMENSION 4
vector<T> matrix_multiply(vector< vector< T > > mat, vector< T > inp_point) {
    vector<T> output_point;
    forn(i, sz(mat)) {
        double total = 0;
        forn(j, DIMENSION) {
            total += mat[i][j]*inp_point[j];
        }
        output_point.pb(total);
    }
}

vector<T> translate(vector< T > inp_point, T tx, T ty, T tz) {
    vector< vector< T > > mat;
    forn(i, DIMENSION) {
        vector<T> tmp;
        forn(j, DIMENSION) {
            if(i==j) tmp.pb(1);
            else tmp.pb(0); 
        }
        mat.pb(tmp);
    }
    mat[0][DIMENSION-1] = tx;
    mat[1][DIMENSION-1] = ty;
    mat[2][DIMENSION-1] = tz;
    return matrix_multiply(mat, inp_point);
}

vector<T> scale(vector< T > inp_point, T sx, T sy, T sz) {
    vector< vector< T > > mat;
    forn(i, DIMENSION) {
        vector<T> tmp;
        forn(j, DIMENSION) {
            if(i==j) tmp.pb(1);
            else tmp.pb(0); 
        }
        mat.pb(tmp);
    }
    mat[0][0] = sx;
    mat[1][1] = sy;
    mat[2][2] = sz;
    return matrix_multiply(mat, inp_point);
}

// theta in degrees
vector<T> rotate_x(vector< T > inp_point, double theta) {
    vector< vector< T > > mat;
    forn(i, DIMENSION) {
        vector<T> tmp;
        forn(j, DIMENSION) {
            if(i==j) tmp.pb(1);
            else tmp.pb(0); 
        }
        mat.pb(tmp);
    }
    double ang = pi*theta/180.0;
    mat[0][0] = cos(ang);
    mat[0][1] = -sin(ang);
    mat[1][0] = sin(ang);
    mat[1][1] = cos(ang);
    return matrix_multiply(mat, inp_point);
}

// theta in degrees
vector<T> rotate_y(vector< T > inp_point, double theta) {
    vector< vector< T > > mat;
    forn(i, DIMENSION) {
        vector<T> tmp;
        forn(j, DIMENSION) {
            if(i==j) tmp.pb(1);
            else tmp.pb(0); 
        }
        mat.pb(tmp);
    }
    double ang = pi*theta/180.0;
    mat[0][0] = cos(ang);
    mat[0][2] = sin(ang);
    mat[2][0] = -sin(ang);
    mat[2][2] = cos(ang);
    return matrix_multiply(mat, inp_point);
}

// theta in degrees
vector<T> rotate_z(vector< T > inp_point, double theta) {
    vector< vector< T > > mat;
    forn(i, DIMENSION) {
        vector<T> tmp;
        forn(j, DIMENSION) {
            if(i==j) tmp.pb(1);
            else tmp.pb(0); 
        }
        mat.pb(tmp);
    }
    double ang = pi*theta/180.0;
    mat[1][1] = cos(ang);
    mat[1][2] = -sin(ang);
    mat[2][1] = sin(ang);
    mat[2][2] = cos(ang);
    return matrix_multiply(mat, inp_point);
}

int main(){
//    freopen("a.txt","r",stdin);
    int t;
    scanf("%d",&t);

  


    return 0;
}
