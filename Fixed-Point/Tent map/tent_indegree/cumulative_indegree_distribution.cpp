#include<bits/stdc++.h>
#include <math.h>
using namespace std;

#define N 33554432
int indegree[N];
int father[N];
int ind_num[N];
int new_ind_num[N];
int main()
{
    int b, n, i, j;
    double t, mu;
    mu = 31*1.0/32;
    scanf("%d",&b);
    n = 1 << b;
    memset(ind_num,0,sizeof(ind_num));
    memset(indegree,0,sizeof(indegree));
    memset(new_ind_num,0,sizeof(new_ind_num));
    for(i = 0; i <= n; i ++)
    {
        t = mu*(1-2*fabs(i*1.0/n-0.5));
        j = round(t*n);
        father[i] = j;
        indegree[j] ++;
    }

    for(i = 0; i <= n; i ++)
        ind_num[indegree[i]] ++;  // calculate distribution of in-degree

    int x, y;
    for(x = 0; x <= n; x ++)
    {
        int sum = 0;
        for(y = x; y <= n; y ++)
        {
            sum += ind_num[y];
        }
        new_ind_num[x] = sum;
    }

    /*
    FILE *fp;
    for(i = 0; i <= n; i ++)
    {
        if(new_ind_num[i] != 0)
        {
            //printf("%d indegree point have %d.\n",i,ind_num[i]);
            if(!(fp=fopen("cumulative_indegree_distribution.txt","a+")))
            {
                printf("Cannot open the file!\n");
                exit(1);
            }
            fprintf(fp,"%d %d\n",i,new_ind_num[i]);
        }
    }
    fclose(fp);
    */

    ofstream outfile;
	outfile.open("cumulative_indegree_distribution18.txt");

	if(outfile.is_open())
	{
	    for(i = 0; i <= n; i ++)
        {
            if(new_ind_num[i] != 0)
            {
                printf("%d %d.\n",i,new_ind_num[i]);
                outfile << i << " " << new_ind_num[i] << endl;
            }
        }
		outfile.close();
	}

    return 0;
}
