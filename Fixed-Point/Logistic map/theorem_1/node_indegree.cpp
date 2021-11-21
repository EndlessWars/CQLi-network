#include<bits/stdc++.h>
#include <math.h>
using namespace std;

#define N 33554432
int indegree[N];
int father[N];
int main()
{
    int b, n, i, j;
    double t, mu;
    mu = 121*1.0/32;
    scanf("%d",&b);
    n = 1 << b;
    memset(indegree,0,sizeof(indegree));
    for(i = 0; i <= n; i ++)
    {
        t = mu*(i*1.0/n)*(1-i*1.0/n);
        j = round(t*n);
        father[i] = j;
        indegree[j] ++;
    }

    ofstream outfile;
	outfile.open("node_indegree_20bit.txt");

	if(outfile.is_open())
	{
	    for(i = 0; i <= n; i ++)
        {
            outfile << i << " " << indegree[i] << endl;
        }
		outfile.close();
	}

    return 0;
}
