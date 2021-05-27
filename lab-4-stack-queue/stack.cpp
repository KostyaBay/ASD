#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// STACK_LIST

struct Node
{
    string prop_symbol; // свойство/значение ключа
    Node *next, *prev;
};

class List
{
    public:
    void Fill(Node *&tail);
    void AddSymbols(Node *&tail);
    void del_end(Node *&tail);
    void Show(Node *&tail);
};
    // tail - переменная которая хранит указатель на хвост

void List::Fill(Node *&tail)
{
    string symbol;
    if(tail == NULL)
        {
        cout << "Add symbol: ";
        cin >> symbol;
        cout << endl;
        tail = new Node;
        tail -> prop_symbol = symbol;
        }
        return;
}

void List::AddSymbols(Node *&tail)
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
            tail -> next -> prev = tail;
            tail -> next -> prop_symbol = symbol;
            tail = tail -> next;
        }
        return;
}

void List::del_end(Node *&tail)
{
    int n;
    cout << "Count of likes elements to delete: ";
    cin >> n;
    cout << endl;
        for(int i = 0; i < n; i++)
        {
            if(tail->prev == NULL)
            {
                tail = NULL;
                break;
            }
            tail = tail -> prev;
            tail -> next -> prev = NULL;
            delete tail -> next;
        }
    return;
}

void List::Show(Node *&tail)
{
    while(tail -> prev != NULL)
        tail = tail -> prev;
    while(tail -> next != NULL)
    {
        cout << tail -> prop_symbol << " ";
        tail = tail -> next;
    }
    cout << endl;
    return;
}

int main()
{	
	srand(time(NULL));
    double time1 = clock() / 1000.0;
	List lst;
    Node *tail = NULL;
	string str;
    lst.Fill(tail);
    lst.AddSymbols(tail);
    lst.del_end(tail);
    lst.Show(tail);
	double time2 = clock() / 1000.0;
    cout << "\nTime : " << time2 - time1 << endl;
    return 0;
}