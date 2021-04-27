#include <iostream>
#include <string>

using namespace std;
int counter =0;
void sPerm(string a, int l, int h)
{
    if(l==h)
    {
        cout << a << endl;
        counter++;
    }
    else
    {
        for(int i=l; i<a.length(); i++)
        {
            swap(a[i], a[l]);
            sPerm(a,l+1,h);
            swap(a[i], a[l]);
        }
    }

}

int main()
{
    string c ="abc";
    sPerm(c,0,c.length()-1);
    cout << counter;
}
