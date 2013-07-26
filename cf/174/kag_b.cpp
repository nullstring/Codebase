#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX 1000000

int main () {
        int n, x =0;
            int a[MAX], g[MAX];
                scanf ("%d\n", &n);
                    
                    for (int i=0; i<n; i++) {
                                cin >> a[i] >> g[i];
                                    }

                        if (n == 1) {
                                    if (abs(a[0]-g[0]) <= 500) cout << "A" << endl;
                                            else cout << -1 << endl;

                                                    return 0;
                                                        }

                            int a1,a2,g1,g2;
                                a1 = a2 = g1=g2 =0;
                                    string s1,s2;
                                        bool turn = true;

                                            for (int i=0; i<n; i++) {
                                                        if (abs(a1+a[i]-g1) <= 500) { a1 += a[i]; s1 += "A"; }
                                                                else if (abs(g1+g[i]-a1) <= 500) { g1 += g[i]; s1 += "G"; }
                                                                        else {
                                                                                        cout << -1 << endl;
                                                                                                    return -1;
                                                                                                            }
                                                                            }

                                                cout  << s1 << endl;

                                                    return 0;
}
