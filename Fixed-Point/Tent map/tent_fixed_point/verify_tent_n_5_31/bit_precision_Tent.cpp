#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    ofstream outfile;
	outfile.open("5bit_precision_value_index.txt");

    int bit = 5;
    int n = 1 << bit;
    float r = 0.96875;

	if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            float former = i * 1.0 / n;
            float latter = r * (1 - 2 * fabs(former - 0.5));
            int k = (int)(latter * n + 0.5);

            printf("%d %d\n",i,k);
            //cout << setiosflags(ios::fixed);
            //outfile << setprecision(32) << former << "   " << latter << endl;
            outfile << setprecision(32) << i << "   " << k << endl;
        }
		outfile.close();
	}
    return 0;
}

