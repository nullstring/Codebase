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

    vector<int> seq;
    vector< pair<int,int> > op;
    seq.pb(0);
    long long int sum = 0;
    while(t--){
        int n;
        cin >> n;

        if(n == 1){
            int x,y;
            cin >> x >> y;
            x = (seq.size() < x)?seq.size():x;
            op.pb(make_pair(x,y));
            sum += x*y;
            double ans = ((double)sum)/seq.size();
            printf("%.15lf\n",ans);
            //cout<<ans<<endl;
        }
        else if(n == 2){
            int x; cin >> x;
            seq.pb(x);
            sum += x;
            //cout << "sum" << sum << endl;
            double ans = ((double)sum)/seq.size();
            printf("%.15lf\n",ans);
            //cout<<ans<<endl;
        }
        else{
            int to = seq[seq.size()-1];
            for(int i=0;i<op.size();i++){
                if(seq.size() == op[i].first){
                    to += op[i].second; 
                    op[i].first--;
                }
            }
            sum -= to;
            seq.pop_back();
            double ans = ((double)sum)/seq.size();
            printf("%.15lf\n",ans);
            //cout<<ans<<endl;
        }
    
    }

    return 0;
}
