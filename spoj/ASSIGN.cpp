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

unsigned numbits(unsigned i)
{
    const unsigned MASK1  = 0x55555555;
    const unsigned MASK2  = 0x33333333;
    const unsigned MASK4  = 0x0f0f0f0f;
    const unsigned MASK8  = 0x00ff00ff;
    const unsigned MASK16 = 0x0000ffff;

    i = (i&MASK1 ) + (i>>1 &MASK1 );
    i = (i&MASK2 ) + (i>>2 &MASK2 );
    i = (i&MASK4 ) + (i>>4 &MASK4 );
    i = (i&MASK8 ) + (i>>8 &MASK8 );
    i = (i&MASK16) + (i>>16&MASK16);

    return i;
}

int mat[21][21];
long long memo[1<<20];

int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        cin>>n;

        //int mat[n][n];
        //int memo[1<<n];
        memset(memo,0,sizeof memo);
        memset(mat,0,sizeof mat); 

        REP(i,n){
            REP(j,n){
                cin >> mat[i][j];
            }
        }

        memo[(1<<n) -1] = 1;
        for(int i=((1<<n)-1); i>=0; i--){
            int pop_count = numbits(i);
            //cout << pop_count<<endl;
            REP(j,n){
                if( mat[pop_count][j] == 0 || (i & 1<<j)) continue;
                memo[i] += memo[i|1<<j];
            }
        }
        cout << memo[0] << endl;
    }

    
    return 0;
}
