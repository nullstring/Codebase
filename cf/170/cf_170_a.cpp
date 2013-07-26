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

// Usefull macros
//typedef vector<int> vi; 
//typedef vector<vi> vvi; 
//typedef pair<int,int> ii;
//typedef vector<string> vs;

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

#define sz(a) ((int)((a).size())) 
#define pb push_back 

#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

#define present(c,x) ((c).find(x) != (c).end())  // for set/map etc 
#define cpresent(c,x) (find(all(c),x) != (c).end())  // for vector 

using namespace std;
int main(){

    int t;
    scanf("%d",&t);
    
    vector <int> dist;
    for(int i=0;i<t;i++){
        int x;
        cin >> x;
        dist.push_back(x); 
    }
    vector<int> dist_long = dist;
    dist.insert(dist.end(),dist_long.begin(),dist_long.end());

    int p,q;
    cin >> p;
    cin >> q;
    if(p==q) {
        cout << 0 << endl;
        return 0;
    }

    int p1 = p-1, p2 = t+p-1;
    if(q < p) q = t+q-1;
    else q = q-1;

    int total1 = 0,total2=0;
    for(int i=p1;i<p2;i++){
        if(i<q)total1 += dist[i];
        if(i>=q)total2 += dist[i];
    }

    //cout<<total1<<endl<<total2<<endl;

    cout << ((total1<total2)?total1:total2) <<endl;
    return 0;
}
