#include <iostream>
#include <string>

using namespace std;

int main()
{
    string c ="finding";
    int h = 0,x =0;
    for(int i=0; i<c.length(); i++)
    {
        x=1;
        x=x <<  c[i] - 97;
        if((x & h) > 0)
        {
            cout << c[i] << endl;
        }
        else
            h = x|h;
    }
}
