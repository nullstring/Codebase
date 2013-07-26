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
typedef long long int lli; 

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

#define sz(a) ((int)((a).size())) 
#define pb push_back 

#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

#define present(c,x) ((c).find(x) != (c).end())  // for set/map etc 
#define cpresent(c,x) (find(all(c),x) != (c).end())  // for vector 
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

#define F first
#define S second
const int INF = int(1e9);
const double EPS  = 1e-5;
const long long INF64 = (long long)1e18, mod = (long long)(1e9)+7;

int binarySearch(vector<lli> &sortedArray, int first, int last, lli key) {
   // function:
   //   Searches sortedArray[first]..sortedArray[last] for key.  
   // returns: index of the matching element if it finds key, 
   //         otherwise  -(index where it could be inserted)-1.
   // parameters:
   //   sortedArray in  array of sorted (ascending) values.
   //   first, last in  lower and upper subscript bounds
   //   key         in  value to search for.
   // returns:
   //   index of key, or -insertion_position -1 if key is not 
   //                 in the array. This value can easily be
   //                 transformed into the position to insert it.
   
   while (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (key > sortedArray[mid]) 
           first = mid + 1;  // repeat search in top half.
       else if (key < sortedArray[mid]) 
           last = mid - 1; // repeat search in bottom half.
       else
           return mid;     // found it. return position /////
   }
   return -(first + 1);    // failed to find key
}


int main(){

    int t;
    scanf("%d",&t);

    vector<lli> arr,res;
    bool check[t+1];
    memset(check,0,sizeof check);
    
   // check[0] = 1;
    
    for(int i=0;i<t;i++){
        lli x;
        cin >> x;
        arr.pb(x);
        res.pb(i+1);
    }

    sort(arr.begin(),arr.end());

    lli sum = 0;
    for(int i=0;i<t;i++){
        int index = binarySearch(res,0,t-1,arr[i]);
        if(index >= 0){
            if(!check[index]){
                check[index] = 1;
                continue;
            }
        }
        else{
            index = (-index)-1;
        }

        cout << index <<endl;
        int j,k;
        for(j = index; j<t; j++){
            if(!check[j])
                break;
        }
        for(k = index-1; k>=0; k--){
            if(!check[k])
                break;
        }
        cout << j <<" "<<k <<endl;
        int p;
        if(j == t) p = k;
        else if(k == -1) p = j;
        else{
            if((j+1-arr[i]) < abs(k+1-arr[i])){
                check[j] = 1;
                sum += abs(j+1-arr[i]);
                continue;
            }
            else{
                check[k] = 1;
                sum += abs(k+1-arr[i]);
                continue;
            }
        }
        
        check[p] = 1;
        sum += abs(p+1-arr[i]);
    }

    cout << sum <<endl;

    return 0;
}
