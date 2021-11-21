#include<bits/stdc++.h>
#include <math.h>
using namespace std;

const unsigned int MAXN = 245762;
struct node{
    float value;
    unsigned int index;
}a[MAXN];

int main()
{
    float interval[15], fixed[14];
    interval[0] = 0;
    int x = 1;
    int y = -13;
    while(y)
    {
        interval[x++] = pow(2,y++);
    }
    interval[x] = 1;

    int c = 0;
    for(int z = -24; z <= -11; z ++)
    {
        fixed[c++] = pow(2,z);
    }

    unsigned int i = 0;
    a[0].value = 0;

    for(int j = 0; j < 14; j ++)
    {
        while(a[i].value >= interval[j] && a[i].value < interval[j+1])
        {
            a[i].index = i;
            a[i+1].value = a[i].value + fixed[j];
            i ++;
        }
    }
    a[i].index = i;

    int k = i;

	ofstream outfile;
	outfile.open("16bit_floating_point_format1_5_10.txt");

	if(outfile.is_open())
	{
		for(int i = 0; i <= k; i ++)
		{
			printf("%d\n",a[i].index);
			outfile << setprecision(32) << a[i].value << endl;
		}
		outfile.close();
	}
}
