#include <iostream>
using namespace std;
int deg(int n,unsigned int x);
int main()
{
    int k;
    unsigned int m;
    cout<<"Введіть число: ";
    cin>>k;
    cout<<"\nВведіть степінь числа: ";
    cin>>m;
    cout<<"\nЧисло "<<k<<" в степені "<<m<< " дорівнює "<< deg(k,m)<<endl;
return 0;
}

int deg(int n, unsigned int x)
{
    int d;
    if (n==0) return 0;
    //if (x<0) return 0;
    if (x==0) return 1;
    d = n*deg(n,x-1);
    return d;
}