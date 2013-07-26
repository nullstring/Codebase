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

/* Old method with TLEs */
//set<string> out;
//int num;
//int max_length;
//char x[85], y[85];
//int lcs(int xi, int yi) {
    //if (x[xi] == '\0' || y[yi] == '\0') return 0;
    //else if (x[xi] == y[yi]) return lcs(xi+1, yi+1) + 1;
    //else return max(lcs(xi+1, yi), lcs(xi, yi+1));
//}

//int get_lcs(string output_str, int xi, int yi) {
    //if (x[xi] == '\0' || y[yi] == '\0') {
        //if(output_str.length() == max_length)
            ////output[num++] = output_str;
            //out.insert(output_str);
        //return 0;
    //}
    //else if (x[xi] == y[yi]){
        ////arr[xi][yi] = x[xi];
        //output_str += x[xi];
        //return get_lcs(output_str, xi+1, yi+1) + 1;
    //}
    //else return max(get_lcs(output_str, xi+1, yi), get_lcs(output_str, xi, yi+1));
//}

void inline traverseAndAdd(set<string> &s, set<string> &t, string c) {
    set<string>::iterator it;
    for(it = s.begin(); it != s.end(); it++) t.insert((*it) + c); 
}

void lcs(string x, string y) {
    int m = x.length(), n = y.length();
    int len[m+5][n+5];
    set<string> sets[m+5][n+5]; 
    memset(len, 0, sizeof len);

    forn(i, m + 1) sets[i][0].insert("");
    forn(j, n + 1) sets[0][j].insert("");

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) {
            if(x[i-1] == y[j-1]) {
                len[i][j] = len[i-1][j-1] + 1;
                string s = "";
                traverseAndAdd(sets[i-1][j-1], sets[i][j], s + x[i-1]); 
            } 
            else if(len[i-1][j] > len[i][j-1]) {
                len[i][j] = len[i-1][j];
                traverseAndAdd(sets[i-1][j], sets[i][j], "");
            } 
            else if(len[i-1][j] < len[i][j-1]) {
                len[i][j] = len[i][j-1];
                traverseAndAdd(sets[i][j-1], sets[i][j], "");
            } 
            else {
                len[i][j] = len[i][j-1];
                traverseAndAdd(sets[i][j-1], sets[i][j], "");
                traverseAndAdd(sets[i-1][j], sets[i][j], "");
            }
        }
    }
    set<string> out = sets[m][n];
    set<string>::iterator it;
    for(it = out.begin(); it != out.end() ; it++) {
        printf("%s\n", (*it).c_str());
    }
} 
/* Prev method with TLEs */
/*
int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        scanf("%s %s", x, y);
        //printf("%s %s\n", x, y);
        num = 0;
        max_length = lcs(0, 0); 
        //memset(arr, '0', sizeof arr);
        get_lcs("", 0, 0); 
        //set<string> s(output, output + num);
        //vector<string> v(all(s));
        set<string>::iterator it;
        for(it = out.begin(); it != out.end() ; it++) {
            printf("%s\n", (*it).c_str());
        }
        //int i=0,j=0;
        //while(x[i]) {
            //j = 0;
            //while(y[j]) {
                //cout << arr[i][j] << " ";
                //j++;
            //}
            //i++;
            //cout << endl;
        //}
        printf("\n");
    }
    return 0;
}
*/

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        string x, y;
        cin >> x >> y;
        lcs(x, y);
        printf("\n");
    }
    return 0;
}
