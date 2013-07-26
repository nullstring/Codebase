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

    long long int n,t;
    //scanf("%d %d",&n,&t);
    cin >> n >> t;
    long long int sum = 0;
    vector<long long int> arr;
    arr.push_back(0);
    for(int i=0;i<n;i++){
        long long int x;
        cin >> x;
        sum += x;
        arr.push_back(sum);
    }

    int i_max=0;
    int i=0,j=0;
    sum = 0;
    while(j<=n && i<=n){
        sum = arr[j]-arr[i];
        if(sum<=t){
            j++;
        }
        else{
            i++;
        }
        i_max = max(i_max,j-i-1);
        //cout<<i_max<<endl;
    }
/*
    long long int i_max = 0;
    for(int i=0;i<n;i++){
        long long int sum = 0,j=0;
        for(j=i;j<n;j++){
            sum += arr[j];
            if(sum>t)
                break;
        }
        i_max = max(j-i,i_max);
    }
*/
    /*
    long long int sum = 0,j=0;
    for(typeof(arr.rbegin())  i = arr.rbegin(); i != arr.rend() ; i++){
        sum += *i;
        if(sum > t)
            break;
        j++;
    }
    */
    cout<<i_max<<endl;
    return 0;
}
