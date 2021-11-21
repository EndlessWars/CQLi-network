#include <cmath>
#include <iomanip>
#include <cstdio>
#include <deque>
using namespace std;
/*
 *   可调参数
 *
 */
#define e_length 5    //阶码长度
#define f_length 10   //尾数长度
#define e_max 14     //阶码极限值
//#define eps 0.999999  //精度1
#define eps 0.9999999999999999  //精度1

#define test 0
#define error 0xfffffffff


class types
{
    private:
    	//数据存储
        int sign;          //符号位
		deque <int> fraction;   //尾数
		deque <int> e_frame_shift;   //阶码---移码
        //运算部件
		int E;             //指数Dec
		int h;			   //隐藏位
		deque <int> fsign; //符号位 尾数
		deque <int> e_complement;  //阶段---补码
		deque <int> e_true_code;  //阶段---原码

    public:
    	types(){};
        types(float number);
        float operator+(const types &num2);
        float operator-(const types &num2);
        float operator*(const types &num2);
        float operator/(const types &num2);
        float Out(types number);
};
/*
float types::operator + (const types &num3)//*this
{

	types num1,num2;

	num1.h = h;
	num1.E = E;
	num1.sign = sign;
	num1.fraction = fraction;
	num1.e_frame_shift = e_frame_shift;
	num1.fsign = fsign;
	num1.e_complement = e_complement;
	num1.e_true_code = e_true_code;

	num2 = num3;

	float ans = num1.Out(num1)+num2.Out(num2);
	types sb(ans);
	ans = sb.Out(sb);

	return ans;

}
float types::operator - (const types &num3)//*this
{
	types num1,num2;

	num1.h = h;
	num1.E = E;
	num1.sign = sign;
	num1.fraction = fraction;
	num1.e_frame_shift = e_frame_shift;
	num1.fsign = fsign;
	num1.e_complement = e_complement;
	num1.e_true_code = e_true_code;

	num2 = num3;

	float ans = num1.Out(num1) - num2.Out(num2);
	types sb(ans);
	ans = sb.Out(sb);
	return ans;
}
float types::operator * (const types &num3)//*this
{
    types num1,num2;

	num1.h = h;
	num1.E = E;
	num1.sign = sign;
	num1.fraction = fraction;
	num1.e_frame_shift = e_frame_shift;
	num1.fsign = fsign;
	num1.e_complement = e_complement;
	num1.e_true_code = e_true_code;

	num2 = num3;

	float ans = num1.Out(num1)*num2.Out(num2);
	types sb(ans);
	ans = sb.Out(sb);

	return ans;

}
float types::operator / (const types &num3)//*this
{
	types num1,num2;

	num1.h = h;
	num1.E = E;
	num1.sign = sign;
	num1.fraction = fraction;
	num1.e_frame_shift = e_frame_shift;
	num1.fsign = fsign;
	num1.e_complement = e_complement;
	num1.e_true_code = e_true_code;

	num2 = num3;

	float ans = num1.Out(num1) / num2.Out(num2);
	types sb(ans);
	ans = sb.Out(sb);

	return ans;

}*/
types::types(float number)
{
    //types ans;
    int intager_count = 0;
    int decimal_count = 0;
    deque <int> decimals;
    int singed = 0;

    //step1: sign
    if(number >= 0)
        sign = 0;
    else
    {
        sign = 1;
        number = fabs(number);
    }
    int intager = ((int)number)/1;
    float decimal = number - intager;

    //step2.1: intager
    while(intager)
    {
        decimals.push_front(intager%2);
        intager /= 2;
    }
    intager_count = decimals.size();

    //step2.2: decimals
    while(decimals.size() < e_max + f_length)
    {
        if(fabs(decimal - 0) > 0)
        {	//cout<<decimal<<endl;
			if((decimal*2.0 - eps) > 0 )
            {
            	decimals.push_back(1);
            	decimal *= 2.0;
            	decimal -= eps;
            }
            else
            {
            	decimals.push_back(0);
            	decimal *= 2.0;
            	decimal -= int(decimal);
            }
        }
        else
            decimals.push_back(0);
    }

    if(number < 1.0 && fabs(number - 0) > 0)E = -1;
	else E = intager_count;
    if(decimals.front() == 0)
	{
	    int flag = 0;

		for(int i = 0; i < decimals.size(); i++)
		{
			if(decimals.at(i) != 0)
			{
				flag = !flag;
				break;
			}
		}
		while(flag)
		{
			int flag2 = decimals.front();
			if(flag2 != 0)break;
			if(decimals.size() == f_length + 1)break;
			decimals.pop_front();
			E--;
		}
		if(!flag)E = 0;
	}
	//step2.3: fraction
    if(sign)
    {
        singed = 1;
        for(int i =  decimals.size() - 1; i >= 0; i --)
        {
            fraction.push_front((!decimals.at(i) + singed)%2);
            singed = (!decimals.at(i) + singed) / 2;
            decimals.pop_back();
        }//补码
        fsign.push_back(1);
        fsign.push_back(1);

    }
    else
    {
        for(int i = 0; i < f_length + 1; i ++)
        {
            fraction.push_back(decimals.front());
            decimals.pop_front();
        }
        fsign.push_back(0);
        fsign.push_back(0);

    }
	if(E == -e_max)
	{
		E = 0;
		h = fraction.front();
		fraction.pop_front();
	}
	else
	{
		h = fraction.front();
		fraction.pop_front();
	}
	while(fraction.size() > f_length)
		fraction.pop_back();
	intager_count = fabs(E);


    //step 3:   e

    for(int i = e_length; i >= 0; i --)
    {
            while(intager_count)
            {
                e_true_code.push_front((intager_count%2) % 2);
                intager_count /= 2;
                i --;
            }
            while(i--)
                e_true_code.push_front(0);
    }
    if(E < 0) e_true_code.push_front(1);//阶码符号位
    else e_true_code.push_front(0);

    if(E >= 0)
	{
		int i = e_true_code.size();
		while(i -- > 0)
			e_complement.push_front(e_true_code.at(i));
		e_complement.push_front(0);
	}
	else
	{

		int i = e_true_code.size();
		int sb = 1;
		for(int i = e_true_code.size() - 1; i >= 1; i --)
		{
            e_complement.push_front((!e_true_code.at(i) + sb)%2);
        	if(e_complement.front()) sb = 0;
    	}
		e_complement.push_front(1);
		e_complement.push_front(1);
	}

	int i = e_complement.size();
	int j = -1;
	while(i --)
	{
		if(i <= 1)
			e_frame_shift.push_front(!e_complement.at(i));
		else
			e_frame_shift.push_front(e_complement.at(i));
    }

}
float types::Out(types num)
{
	float ans = 1;
	float de = 1;
	float db = 1;
	if(num.fsign.at(0) == 1 && num.fsign.at(1) == 1)
	{
		int j = 1;
		for(int i = num.fraction.size() - 1; i >= 0; i --)
		{
			num.fraction.push_front((!num.fraction.back()+j)%2);
			j = (!num.fraction.back()+j)/2;
			num.fraction.pop_back();
		}
	}
	if(num.E > 0)
	{
		while(--num.E)
			ans *= 2;
	}
	else if(num.E < 0)
		while(num.E++)
			ans /= 2.0;
	else
	{
		de = num.h;
		int ss = e_max;
		while(ss--)
			db /= 2.0;
		de *= db;
	}
	for(int i = 0; i < num.fraction.size(); i++)
	{
		if(num.fraction.at(i))
			de += db/2.0;
		db /= 2.0;
	}
	ans = ans*de;
	if(num.sign) ans = -ans;
	return ans;
}
/*
int main()
{
    float input1,input2;
    #if test
	types r(3.78125),sta(1);
    freopen("10bit.txt","r",stdin);
    freopen("10bit_out.txt","w",stdout);
    #endif
    while(cin>>input1>>input2)
    {
		types a(input1),b(input2);
		float c =  a*b;
		cout<<setprecision(32)<<c<<endl;
    }
    return 0;
}
*/
