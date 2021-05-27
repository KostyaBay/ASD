#include <iostream>
#include <queue>
  
using namespace std;

void showq(queue<int> gq) //Выводит окончательный вид очереди
{
    queue<int> g = gq;
        while (!gq.empty()) //empty () - Возвращает, пуста ли очередь
        { 
        cout << '\t' << gq.front(); 
        gq.pop();
        }
    cout << endl;
}

int main()
{
    queue<int> gquiz,gq;
    int n,del;
    int add_elem;

    cout << "Count of likes elements to add: ";
    cin >> n;
    cout << endl;
        for(int i=0; i < n; i++)
          {
            cout << "Enter your element: ";
            cin >> add_elem;
            gquiz.push(add_elem); //push () - добавляет элемент в конец очереди
            cout << endl;
          }
  
    cout << "The queue gquiz is: ";
    showq(gquiz);
  
    cout << "Size of the queue: " << gquiz.size() << endl; //size() - возвращает размер очереди
    cout << "First elem of the queue : " << gquiz.front() << endl; //front() - возвращает ссылку на первый элемент очереди
    cout << "Last elem of the queue : " << gquiz.back() << endl; //back() - возвращает ссылку на последний элемент очереди

    cout << "Count of likes elements to delete: ";
    cin >> del;
    cout << endl;
    cout << "The queue gquiz is: ";
        for(int i = 0; i < del; i++)
         {
        gquiz.pop(); //pop() - удаляет первый элемент очереди
         }
    showq(gquiz);
    cout << endl;
    return 0;
}


//swap () - обменивается содержимым двух очередей, но очереди должны быть одного типа, хотя размеры могут отличаться.
//emplace () - вставляет новый элемент в контейнер очереди, новый элемент добавляется в конец очереди.