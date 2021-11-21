#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define MAXN 65

int main()
{
    ofstream outfile;
    outfile.open("6-bit_precision_u_perturbation_map.txt");

    int i, k, te;
	int bit = 6;
    int n = 1 << bit;
    float r1 = 3.78125;
    float r2 = 3.875;
    float former, latter;
    int flag_count[MAXN];

    if(outfile.is_open())
	{
	    te = 0;
	    while(te <= 64)
        {
            i = te;
            memset(flag_count,0,sizeof(flag_count));
            while(1)
            {
                flag_count[i] ++;
                if(flag_count[i] == 2) break;
                former = i * 1.0 / n;
                latter = r1 * former * (1 - former);
                k = (int)(latter * n + 0.5);

                outfile << i << "   " << k << endl;

                flag_count[k] ++;
                if(flag_count[k] == 2) break;
                former = k * 1.0 / n;
                latter = r2 * former * (1 - former);
                i = (int)(latter * n + 0.5);

                //cout << setiosflags(ios::fixed);
                //outfile << setprecision(32) << former << "   " << latter << endl;
                outfile << k << "   " << i << endl;
            }
            te ++;
        }
		outfile.close();
	}

	return 0;
}
