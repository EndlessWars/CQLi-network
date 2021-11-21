#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("24bit_precision_value.txt");
	
    int bit = 24;
    int n = 1 << bit;
    double r = 3.78125;

    /*
    if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            float former = i * 1.0 / n;
            float latter = r * former * (1 - former);
            int k = (int)(latter * n + 0.5);

            if(i >= 0 && i <= 2048)
            {
                printf("%d %d %d\n",i,k,1);
                outfile << setprecision(32) << i << "   " << k << endl;
            }

            else if(i > 2048 && i <= 4096)
            {
                if(i % 2 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(32) << i << "   " << k << endl;
                }
            }
        }
		outfile.close();
	}*/

	/*
	if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            float former = i * 1.0 / n;
            float latter = r * former * (1 - former);
            //int k = (int)(latter * n + 0.5);

            if(i >= 0 && i <= 128)
            {
                //printf("%d %d %d\n",i,k,1);
                outfile << setprecision(32) << former << "   " << latter << endl;
                //outfile << setprecision(32) << i << "   " << k << endl;
            }

            else if(i > 128 && i <= 256)
            {
                if(i % 2 == 0)
                {
                    //printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(32) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 256 && i <= 512)
            {
                if(i % 4 == 0)
                {
                    //printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(32) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 512 && i <= 1024)
            {
                if(i % 8 == 0)
                {
                    //printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(32) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 1024 && i <= 2048)
            {
                if(i % 16 == 0)
                {
                    //printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(32) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 2048 && i <= 4096)
            {
                if(i % 32 == 0)
                {
                    //printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(32) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

        }
		outfile.close();
	}*/

	if(outfile.is_open())
	{
	    for(int i = 0; i <= n; i ++)
        {
            double former = i * 1.0 / n;
            double latter = r * former * (1 - former);
            int k = (int)(latter * n + 0.5);

            if(i >= 0 && i <= 2048)
            {
                printf("%d %d %d\n",i,k,1);
                outfile << setprecision(64) << former << "   " << latter << endl;
                //outfile << setprecision(32) << i << "   " << k << endl;
            }

            else if(i > 2048 && i <= 4096)
            {
                if(i % 2 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 4096 && i <= 8192)
            {
                if(i % 4 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 8192 && i <= 16384)
            {
                if(i % 8 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 16384 && i <= 32768)
            {
                if(i % 16 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 32768 && i <= 65536)
            {
                if(i % 32 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 65536 && i <= 131072)
            {
                if(i % 64 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 131072 && i <= 262144)
            {
                if(i % 128 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 262144 && i <= 524288)
            {
                if(i % 256 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 524288 && i <= 1048576)
            {
                if(i % 512 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 1048576 && i <= 2097152)
            {
                if(i % 1024 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 2097152 && i <= 4194304)
            {
                if(i % 2048 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 4194304 && i <= 8388608)
            {
                if(i % 4096 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }

            else if(i > 8388608 && i <= 16777216)
            {
                if(i % 8192 == 0)
                {
                    printf("%d %d %d\n",i,k,1);
                    outfile << setprecision(64) << former << "   " << latter << endl;
                    //outfile << setprecision(32) << i << "   " << k << endl;
                }
            }
        }
		outfile.close();
	}

    return 0;
}

