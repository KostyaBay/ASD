#include <iostream>
using namespace std;
int fibon(unsigned int n);

int main()
{
unsigned int m;
cout << "Введіть число: ";
cin >>m;
cout << "\n" << "Значення Фібоначчі числа " <<m<< " = " <<fibon(m)<<endl;
    return 0;
}

int fibon(unsigned int n)
{
if (n==0||n==1) return 1;
return fibon(n-1)+fibon(n-2);
}