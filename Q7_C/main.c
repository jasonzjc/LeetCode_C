#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
    int MaxNum = 0x7FFFFFFF;
    int MinNum = 0x80000000;
    int maxMsb;
    int flag;
    int bit[32];
    int mbit[32];
    int Msb = 0;
    int i;
    int result = 0;
    int temp;

    temp = x;
    for(i = 0; i < 32; i++)
    {
        bit[i] = temp - (temp/10)*10;
        temp = temp/10;
        if(temp)
            Msb = i + 1;
    }

    if (x > 0)
    {
        temp = MaxNum;
        for(i = 0; i < 32; i++)
        {
            mbit[i] = temp - (temp/10)*10;
            temp = temp/10;
            if(temp)
                maxMsb = i + 1;
        }
        if(Msb == maxMsb)
        {
            for(i=0; i < Msb + 1; i++)
            {
                if(bit[i] < mbit[Msb-i])
                    break;
                if(bit[i] > mbit[Msb-i])
                    return 0;
            }
        }
    }

    if (x < 0)
    {
        temp = MinNum;
        for(i = 0; i < 32; i++)
        {
            mbit[i] = temp - (temp/10)*10;
            temp = temp/10;
            if(temp)
                maxMsb = i + 1;
        }
        if(Msb == maxMsb)
        {
            for(i=0; i < Msb + 1; i++)
            {
                if(bit[i] > mbit[Msb-i])
                    break;
                if(bit[i] < mbit[Msb-i])
                    return 0;
            }
        }
    }

    for(i = 0; i < Msb + 1; i++)
    {
        result = result*10 + bit[i];
    }

    return result;
}

int reverse1(int x)
{
    int sig = 1;
    int temp;
    int ux;
    int res = 0;

    if (x ==0)
        return 0;

    if (x < 0)
    {
        ux = -x;
        sig = -1;
    }

    while(ux)
    {
        temp = ux%10;
        if(res > 0x80000000/10)
            return 0;
        res = res*10;
        if(res > 0x80000000 - temp)
            return 0;
        res += temp;
        ux = ux/10;
    }

    if (sig == -1)
        return 0-(int)res;
    return res;
}

int main()
{
    int input = -2147483412;
    int result;
    result = reverse1(input);
    printf("%i \n",result);
    return 0;
}
