#include <iostream>
using namespace std;
void han_tow(int num, int stem1, int stem2, int stem3, int* count);

int main()
{
   int number;
   int stem1=1, stem2=2, stem3=3;
   int count = 0;
   cout << "Введіть кількість кілець: "<<endl;
   cin >> number; 
   han_tow(number, stem1, stem2, stem3, &count);
   cout << "Мін.кількість кроків для " << number << " кілець дорівнює: " << count << endl;
return 0;

}
void han_tow(int num, int stem1, int stem2, int stem3, int* count)
{
    if(num>0)
    {
        (*count)++;
        han_tow(num-1, stem1, stem3, stem2, count);
        cout << stem1 << "-->" << stem3 << endl;
        han_tow(num-1, stem2, stem1, stem3, count);
    };
}
