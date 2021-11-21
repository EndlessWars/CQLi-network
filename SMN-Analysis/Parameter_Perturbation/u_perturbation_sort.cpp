#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define N 89

struct node{
    int x;
    int y;
}a[N];

int main()
{
    freopen("u_perturbation_filter.txt","r",stdin);
    freopen("u_perturbation_sort.txt","w",stdout);
    int i = 0;
    while(cin>>a[i].x>>a[i].y)
    {
        i++;
    }


    for(int k = 0; k < N; k ++)
    {
        for(int t = 0; t < N; t ++)
        {
            if(a[t].x == k)
            {
                cout << a[t].x << "   " << a[t].y << endl;
            }
        }
    }

    return 0;
}
