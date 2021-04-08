#include <iostream>
using namespace std;
int NSD(unsigned int n,unsigned int m);
int main()
{
unsigned int a,b;
cout << "Введіть 1-ше число: ";
cin >> a;
cout << "\n" << "Введіть 2-ге число: ";
cin >> b;
cout << "\n" << "НСД (" <<a<< "," <<b<< ") = " << NSD(a,b)<<endl;
return 0;
}

int NSD(unsigned int n,unsigned int m)
{
 if (m==0) return n;
 return NSD(m,n%m);
}