#include <iostream>

using namespace std;

double power(int x, int b)
{
    if(b == 0)
        return 1;
    else
        return x * power(x,b-1);
}

double factorial(int b)
{
    if(b==1)
        return 1;
    else
        return b*factorial(b-1);
}

double sum(int x, int b)
{
    if(b == 0)
        return 1;
    else
        return power(x,b)/factorial(b) + sum(x,b-1);
}

int main()
{
    int x;
    cin >> x;
    cout << sum(x,100);
    return 0;
}
