#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    ofstream outfile;
	outfile.open("6bit_precision_value_index_even.txt");

    int bit = 6;
    int n = 1 << bit;
    float r = 0.65625;

    if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            float former = i * 1.0 / n;
            float latter = r * (1 - 2 * fabs(former - 0.5));
            int k = (int)(latter * n + 0.5);

            if(i % 2 == 0)
            {
                printf("%d %d\n",i,k);
                outfile << setprecision(32) << i << "   " << k << endl;
            }

        }
		outfile.close();
	}

    return 0;
}

