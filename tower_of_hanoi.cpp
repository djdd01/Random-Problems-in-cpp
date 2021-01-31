#include <iostream>

using namespace std;

int moves = 0;

void TOH(int n, int a, int b, int c)
{
    if(n > 0)
    {
        TOH(n-1,a,c,b);
        cout << a << " to " << c << endl;
        moves++;
        TOH(n-1,b,a,c);
    }
}

int main()
{
    int n=0;
    cin >> n;
    TOH(n,1,2,3);
    cout << moves << " moves required" ;
}
