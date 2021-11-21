#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    ofstream outfile;
	outfile.open("6-bit_precision_cascade_map.txt");

	int i, k1, k2;
	int bit = 6;
    int n = 1 << bit;
    float r1 = 3.78125;
    float r2 = 0.96875;
    float former, latter1, latter2;

    if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            former = i * 1.0 / n;
            latter1 = r1 * former * (1 - former);
            k1 = (int)(latter1 * n + 0.5);

            printf("%d %d\n",i,k1);
            outfile << i << "   " << k1 << endl;

            latter2 = r2 * (1 - 2 * fabs(former - 0.5));
            k2 = (int)(latter2 * n + 0.5);

            printf("%d %d\n",i,k2);
            outfile << i << "   " << k2 << endl;
        }
		outfile.close();
	}

	return 0;
}
