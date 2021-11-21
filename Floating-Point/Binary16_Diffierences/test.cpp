#include <iostream>
#include <cmath>
#include <deque>
#include <iomanip>
#include <cstdio>
#include "v_bit.hpp"
using namespace std;
int main()
{
    float x;
	types r(3.78125),state(1);
    freopen("16bit_floating_point_format1_5_10.txt","r",stdin);
    freopen("16bit_out.txt","w",stdout);
    int i = 0;
    while(cin>>x)
    {
    	i++;
		types y(x);
		float a = (r.Out(r)*y.Out(y)) * (state.Out(state)-y.Out(y));
		types sb(a);
		cout<<i<<"  "<<setprecision(32)<<y.Out(y)<<" ";
		cout<<setprecision(32)<<sb.Out(sb)<<endl;
    }
    /*
    float r = 3.78125;
    float x = 0.9921875;
    float y = r*x*(1-x);
    cout<<setprecision(32)<<y<<endl;*/
    return 0;
}
