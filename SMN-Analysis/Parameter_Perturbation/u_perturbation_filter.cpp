#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define N 65

struct node{
    int x;
    int y;
}a[N];

int main()
{
    freopen("6-bit_precision_u_perturbation_map.txt","r",stdin);
    freopen("u_perturbation_filter.txt","w",stdout);
    int i = 0;
    int flag[N][N] = {0};
    while(cin>>a[i].x>>a[i].y)
    {
        flag[a[i].x][a[i].y] ++;
        if(flag[a[i].x][a[i].y] >= 2) continue;
        cout << a[i].x << "   " << a[i].y << endl;
    	i++;
    }
}
