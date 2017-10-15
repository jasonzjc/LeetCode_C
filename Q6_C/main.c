// LeetCode 6 ZigZag Conversion
// 09/16/2017

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int sLengths;   // length of the string
    int numZigs;    // number of ZigZags
    int numRes;     // number of residual elements
    int eleZig;     // number of elements in each zigzag
    char* result;  // string to output
    int i, j;       // counter

    if(numRows == 1 || s == NULL)
        return s;

    eleZig = numRows * 2 - 2;
    sLengths = strlen(s);
    numZigs = sLengths / eleZig;
    numRes = sLengths % eleZig;

    //strncpy(result,s,sLengths-1);


    if (~numRes)
        // when no residual
    {
        for(i = 0; i < numRows; i++)
        {
            if(~i)
            {
                for(j = 0; j < numZigs; j++)
                    result[j] = s[j*eleZig];
            }
            else if(i < numRows - 1)
            {
                for (j = 0; j < 2*numZigs; j++)
                {
                    if (j%2 == 0)
                        result[numZigs + (i-1)*2*numZigs + j] = s[(j/2)*eleZig + i];
                    else
                        result[numZigs + (i-1)*2*numZigs + j] = s[(j/2)*eleZig + (2*numRows - i - 2)];
                }
            }
            else
            {
                for(j = 0; j < numZigs; j++)
                    result[numZigs + (numRows - 2)*2*numZigs + j] = s[(j/2)*eleZig + i];
            }
        }
    }
    else if(numRes <= numRows && numRes != 0)
        // when the residual has only part or one column
    {
        for(i = 0; i < numRows; i++)
        {
            if(~i)
            {
                for(j = 0; j < numZigs + 1; j++)
                    result[j] = s[j*eleZig];
            }
            else if(i < numRes && i < numRows - 1)
            {
                for (j = 0; j < 2*numZigs + 1; j++)
                {
                    if (j%2 == 0)
                        result[(numZigs + 1) + (i-1)*(2*numZigs + 1) + j] = s[(j/2)*eleZig + i];
                    else
                        result[(numZigs + 1) + (i-1)*(2*numZigs + 1) + j] = s[(j/2)*eleZig + (2*numRows - i - 2)];
                }
            }
            else if(i < numRows - 1 && i >= numRes)
            {
                for (j = 0; j < 2*numZigs; j++)
                {
                    if (j%2 == 0)
                        result[(numZigs + 1) + (numRes-1)*(2*numZigs + 1) + 2*(i-numRes)*numZigs + j] = s[(j/2)*eleZig + i];
                    else
                        result[(numZigs + 1) + (numRes-1)*(2*numZigs + 1) + 2*(i-numRes)*numZigs + j] = s[(j/2)*eleZig + (2*numRows - i - 2)];
                }
            }
            else if(i < numRes && i == numRows - 1)
            {
                for(j = 0; j < numZigs; j++)
                    result[(numZigs + 1) + (numRows - 2)*2*numZigs + numRes + j] = s[(j/2)*eleZig + i];
            }
            else
            {
                for(j = 0; j < numZigs + 1; j++)
                    result[(numZigs + 1) + (numRows - 2)*2*numZigs + numRes - 1 + j] = s[(j/2)*eleZig + i];
            }
        }
    }
    else if(numRes > numRows && numRes != 0)
        // when the residual has over one column
    {
        for(i = 0; i < numRows; i++)
        {
            if(~i)
            {
                for(j = 0; j < numZigs + 1; j++)
                    result[j] = s[j*eleZig];
            }
            else if(i < (2*numRows - numRes - 1) && i < numRows - 1)
            {
                for (j = 0; j < 2*numZigs + 1; j++)
                {
                    if (j%2 == 0)
                        result[(numZigs + 1) + (i-1)*(2*numZigs + 1) + j] = s[(j/2)*eleZig + i];
                    else
                        result[(numZigs + 1) + (i-1)*(2*numZigs + 1) + j] = s[(j/2)*eleZig + (2*numRows - i - 2)];
                }
            }
            else if(i < numRows - 1)
            {
                for (j = 0; j < 2*numZigs + 2; j++)
                {
                    if (j%2 == 0)
                        result[(numZigs + 1) + (2*numRows - numRes - 1)*(2*numZigs + 1) + (i-(2*numRows - numRes - 1))*(2*numZigs + 2) + j] = s[(j/2)*eleZig + i];
                    else
                        result[(numZigs + 1) + (2*numRows - numRes - 1)*(2*numZigs + 1) + (i-(2*numRows - numRes - 1))*(2*numZigs + 2) + j] = s[(j/2)*eleZig + (2*numRows - i - 2)];
                }
            }
            else    //i == numRows - 1
            {
                for(j = 0; j < numZigs + 1; j++)
                    result[numZigs + (numRows - 2)*2*numZigs + numRes - 1 + j] = s[(j/2)*eleZig + i];
            }
        }
    }
    result[sLengths] = '\0';
    return result;
}

int main()
{
    char input[] = "PAHNAPLSIIGYIR";
    char *result;
    int numRows = 3;
    result = convert(input, numRows);
    printf("Result: %s \n",result);
    return 0;
}
