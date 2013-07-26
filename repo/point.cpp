#include <iostream>
#include <cmath>
using namespace std;
typedef long long int lli;

class point{

public:
    lli x,y;

    point(lli a,lli b){
        x=a;
        y=b;
    }

    point(){}

    point operator+(point a){
        point c(a.x+x,a.y+y);
        return c;
    }
    
    point operator-(point a){
        point c(x-a.x,y-a.y);
        return c;
    }

    //dot product
    lli operator*(point a){
        return a.x*x + a.y*y;
    }
   
    //scaler product
    point operator*(lli a){
        point c(a*x,a*y);
        return c;
    }
    
    //cross product
    lli operator^(point a){
        return x*a.y - y*a.x;
    }

    void print(){
        cout <<x<<" "<<y<<endl;    
    }

    //mod
    double mod(){
        return sqrt(x*x+y*y);
    }

    //less than and assignment operator for sorting 
    bool operator<(const point a)const{
        if(x<a.x)return true;
        if(x==a.x && y<a.y)return true;
        return false;
    }

    void operator=(point a){
        x=a.x;
        y=a.y;
    }

};

//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePointDist(point A, point B, point C, bool isSegment){
    double dist = ((B-A)^(C-A))/(B-A).mod();
    if(isSegment){
        int dot1 = (C-B)*(B-A);
        if(dot1 > 0) return (C-B).mod();

        int dot2 = (C-A)*(A-B);
        if(dot1 > 0) return (C-A).mod();
    }
    return dist;
}

/*

int main(){

    //point x(2,3),y(4,6);
    //cout << x.x<<" "<<x.y<<endl;
    //point z = x*3;    
    
    //cout << (x*y) <<endl;
    //cout << (x^y) <<endl;
    //cout << linePointDist(x,y,z,0)<<endl;
    //cout << linePointDist(x,y,z,1)<<endl;
    
    
    //sort
    point x[2];
    x[1].x=2;
    x[1].y=1;
    x[0].x=2;
    x[0].y=2;

    x[0].print();
    x[1].print();
    sort(x,x+2);
    x[0].print();
    x[1].print();
    

    //z.print();

    return 0;

}
*/
