#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    string prop_symbol; // свойство/значение ключа
    Node *next, *prev;
	Node *head;
};

class List
{
	
    public:
    void AddSymbols(Node *head);
    void AddToBegin(Node *head);
    void AddToMiddle(Node *head);
    void AddToEnd(Node *head);
    void del_middle(Node *head);
    void del_end(Node *head);
	bool Check(string str);
    void Task(Node *head);
};

void List::AddSymbols(Node *head) //рекурсивная, сначала заполняет, потом создает новый узел
{
    string symbol;
	cout << "Add symbol: ";
    cin >> symbol;
	cout << endl;
	if (Check(symbol))
	{
		if (symbol[symbol.length() - 1] == '.')
		{
			head -> prop_symbol = symbol.erase(symbol.length() - 1, 1);
			return;
		}
		else
		{
			head -> prop_symbol = symbol;
			head -> next = new Node;
			head -> next -> prev = head;
			return AddSymbols(head -> next);
		}
	}
	else
	{
		cout << "Error enter!" << endl;
		return AddSymbols(head); //показывает указателем на новый узел
	}
}

void List::AddToBegin(Node *head) //создает сначала новый узел, потом заполняет, создать узел перед 1 узлом!
{
    while(head -> prev != NULL)
    {
        head = head -> prev;
    }
    string symbol;
	cout << "Enter symbol in begin: ";
    cin >> symbol;
	cout << endl;
    head -> prev = nullptr;
    head -> prev = new Node;
    head -> prev -> next = head;
    head = head -> prev;
    if (symbol[symbol.length() - 1] == '.')
	{
		head -> prop_symbol = symbol.erase(symbol.length() - 1, 1);
		return;
	}
	else
	{
		head -> prop_symbol = symbol;
		return AddToBegin(head);
	}
}

void List::AddToMiddle(Node *head) // добавление после текущего узла
{
    int n = 0;
	cout << "Enter value of node to add: "; //выбираем номер текущего узла,после которого мы создадим новый узел середина=универсально(можем добавить после любого,кроме последнего)
	cin >> n;
	cout << endl;
	while (head -> prev != NULL)
    {
	    head = head -> prev;
    }
	for (int i = 1; i < n; i++)
	{
		if (head -> next == NULL)
		{
			cout << "Error: few words entered!" << endl;
			AddToEnd(head);
			return;
		}
		head = head -> next;
	}
	string symbol;
	//cout << "Enter symbol in middle:";
    cin >> symbol;
	cout << endl;
	head -> next -> prev = new Node;
	head -> next -> prev -> next = head->next;
	head -> next -> prev -> prev = head;
	head -> next = head -> next -> prev;
	if (symbol[symbol.length() - 1] == '.')
	{
		head -> prop_symbol = symbol.erase(symbol.length() - 1, 1);
		return;
	}
	else
	{
		head -> prop_symbol = symbol;
		return AddToMiddle(head);
	}
}

void List::AddToEnd(Node *head) //создаем новый узел после последнего
{
    while (head -> next != NULL)
	{
        head = head -> next;
    }

	string symbol;
	cout << "Enter symbol in end: ";
    cin >> symbol;
	cout << endl;
	head -> next = new Node;
	head -> next -> prev = head;
	head = head -> next;
	if (symbol[symbol.length() - 1] == '.')
	{
		head -> prop_symbol = symbol.erase(symbol.length() - 1, 1);
		return;
	}
	else
	{
		head -> prop_symbol = symbol;
		return AddToEnd(head);
	}
}

Node *del_begin(Node *head) //указатель структуры для удаления 1 узла
{
	while (head -> prev != NULL)
	{
        head = head -> prev;
    }
	Node *temp = head -> next;
	head -> next = NULL;
	delete head;
	return temp;
}

void List::del_end(Node *head) 
{
	while (head -> next != NULL)
    {
	    head = head -> next;
    }
	head -> prev = NULL;
	delete head;
	return;
}

void List::del_middle(Node *head)
{
	cout << "Enter value of node which delete: ";
	int n = 0;
	cin >> n;
	cout << endl;
	while (head -> prev != NULL)
		{
            head = head -> prev;
        }
	for (int i = 1; i < n; i++)
	{
		if (head -> next == NULL)
		{
			cout << "Error: few words entered!" << endl;
			return AddToEnd(head);
		}
		head = head -> next;
	}
	head -> next-> prev = head -> prev;
	head -> prev -> next = head -> next;
	head -> next = NULL;
	head -> prev = NULL;
	delete head;
	return;
}

bool List::Check(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!((str[i] >= 'a') && (str[i] <= 'z')))
			if (str[i] != '.')
				return 0;
	}
	return 1;
}

void List::Task(Node *head)
{
    while (head -> prev != NULL)
		head = head -> prev;
	while (head != NULL)
	{
		if (head -> prop_symbol.length() % 2 == 1)
		{
			head -> prop_symbol.erase(head -> prop_symbol.length() - 1, 1);
			head -> prop_symbol.erase(0, 1);
			cout << head -> prop_symbol << endl;
		}
		head = head -> next;
	}
	return;
}

int main()
{	
	srand(time(NULL));
    double time1 = clock() / 1000.0;
	List lst;
    Node *head = new Node;
	string str;
    lst.AddSymbols(head);
    lst.AddToBegin(head);
    lst.AddToMiddle(head);
    lst.AddToEnd(head);
    lst.del_middle(head);
    lst.del_end(head);
	lst.Check(str);
    lst.Task(head);
	double time2 = clock() / 1000.0;
    cout << "\nTime : " << time2 - time1 <<endl;
    return 0;
}

//----------------------------------------------------------------

// head -> next // указатель на след елем/узел в ячейке next
// head -> next -> key //просмотр что в след елем/обьект=узел находится - получаем слово,которое там лежит (2 узел)
// head -> next -> next -> key // получим,что в 3 лежит (3 узел)
// //elem = object
// head -> next = nullptr;
// head -> next = new Node // указатель на новый узел структуры Node 
// //2указатели и слова - в каждом узле 
// head -> next -> prev //переназначаем голову на предыдущий елем,чтобы потом сделать след действие
// head = head -> next //указатель с именем head на 1 елем будет теперь указывать на след елем -2 

// struct
// {head
// data}
// head -> next = new Node//создаем указ новый узел в конец/чтобы выделть память на новый узел
// head -> prev = new Node//создаем указ новый узел в начало/
// next, prev, key
// head -> next -> key = "abcd" 
// head -> next -> prev = head
// head = head -> next //можем теперь стартовать с 2 узла

// -> //доступ с указателя на свойство структуры
// // гетч - ждет,пока нажмешь клавишу на клавиатуре для меню