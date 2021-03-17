#include <iostream>
#include <cmath> 
#include "labBack.h"
using namespace std;

float percent(int a, int n)
{
    return (float)a * 100 / n;
}

void taskOne()
{
    int  n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 100) - 50;
    }

    arrPrint(arr, n);

    int  e = 0, o = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0) {
            e++;
        }
        else if (arr[i] < 0) {
            o++;
        }
        else z++;
    }

    delete(arr);

    cout << "> 0 = " << e << " its " << percent(e, n) << "% of array;\n";
    cout << "< 0 = " << o << " its " << percent(o, n) << "% of array;\n";
    cout << "= 0 = " << z << " its " << percent(z, n) << "% of array\n";
}

void taskTwo()
{
    int  n;
    cin >> n;
    int* arr = new int[n];
    int bot, top;
    cin >> bot >> top;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % (top - bot)) + bot;
    }

    arrPrint(arr, n);

    for (int i = 0; i < n; i++)
    {
        int sumNums = 0;
        if ((arr[i] % 3) == 0)
        {
            while (arr[i] > 0)
            {
                sumNums += arr[i] % 10;
                arr[i] /= 10;
            }
            arr[i] = sumNums;
        }
    }
    arrPrint(arr, n);

    delete(arr);
}


void taskThree()
{
    int  n;
    do {
        cin >> n;
    } while (n % 2 == 0);

    float* arr = new float[n];

    int bot, top;
    cin >> bot >> top;

    for (int i = 0; i < n; i++)
    {
        arr[i] = ((rand() % (top - bot)) + bot) + (rand() % 10) * 0.1;
    }


    arrPrint(arr, n);

    for (int i = 0; i < n / 2; i++)
    {
        arr[i] += arr[n - 1 - i];
        arr[n - 1 - i] = arr[i] - arr[n - 1 - i];
        arr[i] -= arr[n - 1 - i];
    }

    arrPrint(arr, n);

    delete(arr);
}

void taskFour()
{
    int  n;
    cin >> n;
    int* arr = new int[n];

    int bot, top;
    cin >> bot >> top;

    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % (top - bot)) + bot;
    }
    arrPrint(arr, n);

    int min = 0, iMin = 0, mx = 0, iMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i]; iMin = i;
        }
        if (arr[i] >= mx)
        {
            mx = arr[i]; iMax = i;
        }
    }

    arr[iMin] += arr[iMax];
    arr[iMax] = arr[iMin] - arr[iMax];
    arr[iMin] -= arr[iMax];

    arrPrint(arr, n);
}


void taskFive()
{
    int  n;
    cin >> n;
    float* arr = new float[n];

    int bot, top;
    cin >> bot >> top;

    int n3, k;
    cin >> n3 >> k;

    for (int i = 0; i < n; i++)
    {
        arr[i] = ((rand() % (top - bot)) + bot) + (rand() % 10) * 0.1;
    }

    arrPrint(arr, n);

    float* secondArr = new float[n - n3];
    for (int i = 0; i < n - n3; i++)
    {
        secondArr[i] = arr[n3 + i];
    }

    float temp;
    for (int j = 0; j < k; j++)
    {
        temp = secondArr[(n - n3) - 1];
        for (int i = (n - n3) - 1; i >= 0; i--)
        {
            secondArr[i] = secondArr[i - 1];
        }
        secondArr[0] = temp;
    }


    for (int i = 0; i < n - n3; i++)
    {
        arr[n3 + i] = secondArr[i];
    }

    arrPrint(arr, n);
}

int main()
{
    // taskOne();
    // taskTwo();
    // taskThree();
    // taskFour();
     taskFive();
}
