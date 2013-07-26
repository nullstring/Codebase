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


template<class T>
class BIT
{
      T *tree;
      int maxVal;
      public:
      BIT(int N)
      {
              tree = new T[N+1];
              memset(tree,0,sizeof(T)*(N+1));
              maxVal = N;
      }
      void update(int idx, T val)
      {
           while (idx <= maxVal)
           {
                 tree[idx] += val;
                 idx += (idx & -idx);
           }
      }
      //Returns the cumulative frequency of index idx
      T read(int idx)
      {
        T sum=0;
        while (idx>0)
        {
              sum += tree[idx];
              idx -= (idx & -idx);
        }
        return sum;
      }
      
    //divide by c  
	void scale(int c){
		for (int i = 1 ; i <= MaxVal ; i++)
			tree[i] = tree[i] / c;
	}
	
	// if in tree exists more than one index with a same
	// cumulative frequency, this procedure will return 
	// the greatest one
	int findG(T cumFre){
		int idx = 0;
	
		while ((bitMask != 0) && (idx < MaxVal)){
			int tIdx = idx + bitMask;
			if (cumFre >= tree[tIdx]){ 
		    	// if current cumulative frequency is equal to cumFre, 
		    	// we are still looking for higher index (if exists)
				idx = tIdx;
				cumFre -= tree[tIdx];
			}
			bitMask >>= 1;
		}
	
		if (cumFre != 0)
			return -1;
		else
			return idx;
	}

};

int main(){

    REP(i,10){    
        int t;
        scanf("%d",&t);
    
        char c;
        string s;
        REP(j,t) {
            scanf("%c",&c)
            s += c;
        }

        int q;
        cout << "TEST " << i+1 << ":"<<endl;
        REP(j,q){
            
        }
    }
    
    return 0;
}
