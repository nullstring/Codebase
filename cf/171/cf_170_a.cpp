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

    int x,y;
    scanf("%d %d",&x,&y);
    int to_return = 0;

    if(x == 0 && y == 0) to_return = 0;
    else if(x == 1 && y == 0) to_return = 0;
    else if(y-x > 0 && y+x >= 0) {
        to_return = 2 + 4*(y-1);
    } 
    else if(y+x<0 && y-x>=0) to_return = 3+4*((-x)-1);
    else if(y-x<0 && y+x-1<=0) to_return = 4+4*((-y)-1);
    else if(y+x-1>0 && y-x<=0) to_return = 5+4*(x-2);
    else cout << "no"<<endl;

    cout<<to_return<<endl;
    return 0;
}
