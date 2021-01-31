#include <iostream>
#include <string>

using namespace std;
int counter =0;
void sPerm(string a, int k)
{
    static int arr[10] ={0};
    static string result(10, ' ');
    if(k == a.length())
    {
        cout << result << endl;
        counter++;
    }
    else
    {
        for(int i=0;i<a.length();i++)
        {
            if(arr[i] == 0)
            {
                result[k] = a[i];
                arr[i] = 1;
                sPerm(a,k+1);
                arr[i] = 0;
            }
        }
    }

}

int main()
{
    string c ="abc";
    sPerm(c,0);
    cout << counter;
}
