// tent_binary16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <half.hpp>
using namespace std;
using half_float::half;

#define MAXN 10000


int _tmain(int argc, _TCHAR* argv[])
{
	half x[MAXN];
	int L[MAXN], DL[MAXN];
	int Sum = 0;
    memset(L,0,sizeof(L));
    memset(DL,0,sizeof(DL));
    srand((unsigned int)time(NULL));
    for(int i = 0; i < MAXN; i ++)
    {
        x[i] = rand() / half(RAND_MAX);
        //cout << setprecision(16) << x[i] << endl;
        while(x[i])
        {
            if(x[i] >= 0 && x[i] < 0.5)
                x[i] = 2 * x[i];
            else
                x[i] = 2 * (1 - x[i]);

            L[i] ++;
        }
        //cout << L[i] << endl;
		Sum += L[i];
    }
	cout << Sum*1.0/MAXN << endl;

    for(int i = 0; i < MAXN; i ++)
        DL[L[i]] ++;

    /*
    for(int i = 0; i < MAXN; i ++)
        cout << DL[i]*1.0/1000 << endl;*/

    ofstream outfile;
	outfile.open("DL_binary16.txt");

	if(outfile.is_open())
	{
	    for(int i = 0; i < MAXN; i ++)
        {
            if(DL[i] != 0)
            {
                printf("%d %d\n",i,DL[i]);
                outfile << i << " " << DL[i]*1.0/MAXN << endl;
            }
        }
		outfile.close();
	}
    return 0;
}



