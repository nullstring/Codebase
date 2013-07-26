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

typedef long long int lli;

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

#define sz(a) ((int)((a).size())) 
#define pb push_back 

#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

#define present(c,x) ((c).find(x) != (c).end())  // for set/map etc 
#define cpresent(c,x) (find(all(c),x) != (c).end())  // for vector 

using namespace std;

#define MAX 1000000007





long long int count1(long long int a, long long int b, long long int c){

		/*
		long long int ab = ((min(a,b)%MAX)*(c%MAX))%MAX;
		long long int bc = ((min(b,c)%MAX)*(a%MAX))%MAX;
		long long int ac = ((min(a,c)%MAX)*(b%MAX))%MAX;
		long long int abc = (2*(min(min(a,b),c)%MAX))%MAX;

		 a = a%MAX;
		 b = b%MAX;
		 c = c%MAX;
		return ((((a*b)%MAX)*c)%MAX - ((((ab+bc)%MAX)+ac)%MAX - abc)%MAX);
		*/
		

		vector<long long int> v;
		v.pb(a);
		v.pb(b);
		v.pb(c);
		sort(v.begin(),v.end());


		lli x = v[0]%MAX;
		lli y = v[1]%MAX;
		lli z = v[2]%MAX;

		lli ab = (x*(y-1))%MAX;
		lli ans = (ab*(z-2))%MAX;
		return ans;
}		


int main(){

	int t;
	scanf("%d",&t);
	
	while(t--){
		long long int a,b,c;
		cin>>a>>b>>c;
		cout<<count1(a,b,c)<<endl;
	}

	return 0;
}






