#include<bits/stdc++.h>
#include <math.h>
using namespace std;

#define N 33554432
int indegree[N];
int father[N];
int ind_num[N];
int main()
{
    int i, j, k;
    memset(ind_num,0,sizeof(ind_num));
    memset(indegree,0,sizeof(indegree));

    freopen("20bit_out_index.txt","r",stdin);
    freopen("20indegree_distribution.txt","w",stdout);

    int n = 0;
    while(cin>>i>>j)
    {
        n ++;
    	father[i] = j;
    	indegree[j] ++;
    }

    for(k = 0; k < n; k ++)
        ind_num[indegree[k]] ++;  // calculate distribution of in-degree


	for(k = 0; k < n; k ++)
    {
        if(ind_num[k] != 0)
        {
            cout << k << " " << ind_num[k] << endl;
        }
    }

    return 0;
}
