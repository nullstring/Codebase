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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class node{
public:
    int xr,xc,yr,yc;
    int steps;

    node(int a,int b,int c,int d,int s){
        xr = a;
        xc = b;
        yr = c;
        yc = d;
        steps = s;
    }
};

class PathFinding {
    bool fill[20][20][20][20];
    public:
            int minTurns(vector <string> board) {
                int nr = board.size();
                int nc = board[0].length();
                memset(fill,0,sizeof(fill));
                int ar,ac,br,bc;
                for(int i=0; i<nr; i++){
                    for(int j=0; j<nc; j++){
                        if(board[i][j]=='A'){
                            ar = i;
                            ac = j;
                        }
                        if(board[i][j]=='B'){
                            br = i;
                            bc = j;
                        }
                    }
                }

                node start(ar,ac,br,bc,0);

                queue< node > qu;
                qu.push(start);

                while(!qu.empty()){
                    node cur = qu.front();
                    qu.pop();

                    // out of bounds or on an x
                    if(cur.xr<0 || cur.xr>=nr || cur.xc<0 || cur.xc>=nc || cur.yr<0 || cur.yr>=nr || cur.yc<0 || cur.yc>=nc)continue;
                    if(board[cur.xr][cur.xc] == 'X' || board[cur.yr][cur.yc]=='X')continue;
                    //on top of eachother
                    if(cur.xr == cur.yr && cur.xc == cur.yc)continue;
                    //if visited
                    if(fill[cur.xr][cur.xc][cur.yr][cur.yc])continue;
                    fill[cur.xr][cur.xc][cur.yr][cur.yc] = 1;

                    //see if this is the final config
                    if(cur.xr == br && cur.xc == bc && cur.yr == ar && cur.yc == ac)return cur.steps;

                    //go to all config and push to queue if not exchanging positions
                    for(int p = -1 ; p<= 1 ;p++){
                        for(int q = -1; q<= 1; q++){
                            for(int r = -1; r<= 1 ; r++){
                                for(int s = -1; s<=1 ; s++){

                                    if( cur.xr+p == cur.yr && cur.yr+r==cur.xr && cur.xc+q==cur.yc && cur.yc+s==cur.xc ) continue;
                                    node tmp(cur.xr+p,cur.xc+q,cur.yr+r,cur.yc+s,cur.steps+1);
                                    qu.push(tmp);
                                }
                            }
                        }
                    }

                }
            
            return -1;
            }
};

bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    PathFinding *obj;
    int answer;
    obj = new PathFinding();
    clock_t startTime = clock();
    answer = obj->minTurns(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;
    
    vector <string> p0;
    int p1;
    
    {
    // ----- test 0 -----
    string t0[] = {"....",".A..","..B.","...."};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 2;
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 1 -----
    string t0[] = {"XXXXXXXXX","A...X...B","XXXXXXXXX"};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = -1;
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 2 -----
    string t0[] = {"XXXXXXXXX","A.......B","XXXXXXXXX"};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = -1;
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    string t0[] = {"XXXXXXXXX","A.......B","XXXX.XXXX"};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 8;
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 4 -----
    string t0[] = {"...A.XXXXX.....",".....XXXXX.....","...............",".....XXXXX.B...",".....XXXXX....."};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 13;
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
    // ------------------
    }
    
    {
    // ----- test 5 -----
    string t0[] = {"AB.................X","XXXXXXXXXXXXXXXXXXX.","X..................X",".XXXXXXXXXXXXXXXXXXX","X..................X","XXXXXXXXXXXXXXXXXXX.","X..................X",".XXXXXXXXXXXXXXXXXXX","X..................X","XXXXXXXXXXXXXXXXXXX.","X..................X",".XXXXXXXXXXXXXXXXXXX","X..................X","XXXXXXXXXXXXXXXXXXX.","X..................X",".XXXXXXXXXXXXXXXXXXX","X..................X","XXXXXXXXXXXXXXXXXXX.","...................X",".XXXXXXXXXXXXXXXXXXX"};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    p1 = 379;
    all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
    // ------------------
    }
    
    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}

