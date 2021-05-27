#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    string prop_symbol; // свойство/значение ключа
    Node *next, *prev;
    //tail,head - переменные которые хранят указатели
};

class List
{
    public:
    void Fill(Node *&head,Node *&tail);
    void AddSymbols(Node *&head,Node *&tail);
    void del_end(Node *&head,Node *&tail);
    void Show(Node *&head);
};

void List::Fill(Node *&head,Node *&tail)
{
    string symbol;
    if(head == NULL)
        {
        cout << "Add symbol: ";
        cin >> symbol;
        cout << endl;
        tail = new Node;
        tail -> next = NULL;
        head = tail;
        tail -> prop_symbol = symbol;
        }
        return;
}

void List::AddSymbols(Node *&head,Node *&tail)
{
    string symbol;
    int n;
    cout << "Count of likes elements to add: ";
    cin >> n;
    cout << endl;
        for(int i=0; i < n; i++)
        {
            cout << "Add symbol: ";
            cin >> symbol;
            cout << endl;
            tail -> next = new Node;
            tail = tail -> next;
            tail -> prop_symbol = symbol; //добавление в конец
            tail -> next = NULL; //обнуление указателя на next
        }
        return;
}

void List::del_end(Node *&head, Node *&tail)
{
    int n;
    cout << "Count of likes elements to delete: ";
    cin >> n;
    cout << endl;
        for(int i = 0; i < n; i++)
        {
            if(head -> next == NULL)
            {
                head = NULL;
                break;
            }
            head = head -> next;
            head -> prev -> next = NULL;
            delete head -> prev;  //удаление с головы
            head -> prev = NULL;        
        }
    return;
}

void List::Show(Node *&head)
{
    while(head != NULL)
    {
        cout << head -> prop_symbol << " ";
        head = head -> next;
    }
    cout << endl;
    return;
}

int main()
{	
	srand(time(NULL));
    double time1 = clock() / 1000.0;
	List lst;
    Node *head = NULL;
    Node *tail = NULL;
	string str;
    lst.Fill(head,tail);
    lst.AddSymbols(head,tail);
    lst.del_end(head,tail);
    lst.Show(head);
	double time2 = clock() / 1000.0;
    cout << "\nTime : " << time2 - time1 << endl;
    return 0;
}