#include <iostream>
using namespace std;
int fact(unsigned int n);

int main()
{
    unsigned int a;
    cout << "Введіть число: ";
    cin >> a;
    cout << "\n Факторіал числа " << a << " = " << fact(a) << endl;
    return 0;
} 

int fact(unsigned int n)
{
    if(n==0) return 1; 
    return n*fact(n-1);
}