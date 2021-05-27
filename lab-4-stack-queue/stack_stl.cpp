#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    stack<int> stack;
    int n,add_elem,del;

    cout << "Count of likes elements to add: ";
    cin >> n;
    cout << endl;

        for(int i=0; i < n; i++)
         {
            cout << "Enter your element: ";
            cin >> add_elem;   
            cout << endl;
            stack.push(add_elem); //push() – добавляет элемент наверху стека - Сложность времени: O(1)
         }

    cout << "Count of likes elements to delete: " << endl;
    cin >> del;
    cout << endl;
        for(int i = 0; i < del; i++)
         {
            stack.pop(); //pop() – Удаляет самый верхний элемент стека - Сложность времени: O(1)
         }

    cout << "Stack contain: ";
        while (!stack.empty()) //empty() – Возвращает, пуст ли стек - Сложность времени: O(1) 
         {
            cout << ' ' << stack.top(); //top() – возвращает ссылку на самый верхний элемент стека - Сложность времени: O(1) 
            stack.pop();
         }
    stack.size(); //size() – Возвращает размер стека - Сложность времени: O (1)
    cout << endl;
}