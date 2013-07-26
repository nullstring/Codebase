#include<iostream>
using namespace std;
 
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
 
int main()
{
    int a[100],cur=1,mul=2,add=19,MAX=65536,x,i;
    //Initialize the size by the
    //maximum value the tree can have
    BIT<int> B(MAX);
    for (i=0;i<50;i++)
    {
        a[i] = cur;
        B.update(a[i],1);
        cur = ((cur * mul + add) % MAX);
    }
    while (cin>>x)
    {
          cout<<B.read(x)<<endl;
    }
 
}