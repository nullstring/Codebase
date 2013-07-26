//Harsh Mehta

//library includes 
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>


using namespace std;
// Usefull macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
typedef long long int lli; 



long long int countCells(int a,int b,int numRows,int numColumns,int k){

    int mn=2*min(a,b);
    int mx=2*max(a,b);
    int r=numRows;
    int c=numColumns;

    long long int ans_8,ans_6,ans_4,ans_2;
    ans_8 = (r-mx)*(c-mx);
    ans_6 = ((r-mx)*(c-mn)+(r-mn)*(c-mx)-2*ans_8);
    ans_2 = mn*mn*4;
    ans_4 = r*c-ans_2-ans_6-ans_8;

    switch(k){

        case 0:
            return 0;
            break;
        case 1:
            return 0;
            break;
        case 3:
            return 0;
            break;
        case 5:
            return 0;
            break;
        case 7:
            return 0;
            break;
        case 2:
            return ans_2;
            break;
        case 4:
            return ans_4;
            break;
        case 6:
            return ans_6;
            break;
        case 8:
            return ans_8;
            break;
    }
    
}


int main(){

	int t;
	scanf("%d",&t);

    int a[t];

    for(int i=0;i<t-1;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<=8;i++)
    cout<< countCells(a[0],a[1],a[2],a[3],i)<<endl;


	return 0;
}
