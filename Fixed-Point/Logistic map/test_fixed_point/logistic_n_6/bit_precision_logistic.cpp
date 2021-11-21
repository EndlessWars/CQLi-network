#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    ofstream outfile;
	outfile.open("6bit_precision_value_index.txt");

    int bit = 6;
    int n = 1 << bit;
    float r = 3.78125;

	if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            float former = i * 1.0 / n;
            float latter = r * former * (1 - former);
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

