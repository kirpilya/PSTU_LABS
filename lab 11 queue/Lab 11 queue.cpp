#include <iostream>
#include <ctime>
#include <climits>
#include <string>
#include <fstream>
#include <windows.h>
#undef max()

using namespace std;

struct Node
{
	string data;
	Node* next = nullptr;
};

struct Queue
{
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
};

bool IsEmpty(Queue* queue)
{
	return (queue->size == 0 || queue->head == nullptr);
}

void Push(Queue* queue, string str)
{
	if (!IsEmpty(queue))
	{
		Node* new_node = new Node;
		new_node->data = str;
		new_node->next = nullptr;
		queue->tail->next = new_node;
		queue->tail = new_node;
		queue->size++;
	}
	else
	{
		Node* new_node = new Node;
		new_node->data = str;
		new_node->next = nullptr;
		queue->head = new_node;
		queue->tail = new_node;
		queue->size++;
	}
}

void Pop(Queue* queue)
{
	Node* temp = queue->head;
	if (queue->size > 1)
	{
		queue->head = temp->next;
	}
	else
	{
		queue->head = temp->next;
		queue->tail = nullptr;
	}
	queue->size--;
	delete temp;
}

Queue* CreateQueue(int size)
{
	Queue* queue = new Queue;
	string str;
	cout << "Создание списка:\n";
	for (int i = 1; i <= size; i++)
	{
		cout << i << ". ";
		getline(cin, str);
		Push(queue, str);
	}
	return queue;
}

void PrintQueue(Queue* queue)
{
	if (IsEmpty(queue))
	{
		cout << "Очередь пуста\n";
	}
	else
	{
		cout << "Содержимое очереди(" << queue->size << "):\n";
		Node* temp = queue->head;
		int i = 1;
		while (temp != nullptr)
		{
			cout << i << ". " << temp->data << endl;
			temp = temp->next;
			i++;
		}
	}
}

void RemoveByData(Queue* queue, string data)
{
	int i = 0;
	while (i < queue->size)
	{
		if (queue->head->data != data)
		{
			Push(queue, queue->head->data);
			Pop(queue);
			i++;
		}
		else
		{
			Pop(queue);
		}
	}
}

void AddToQueue(Queue* queue, int k, int n)
{
	for (int i = 0; i < k; i++)
	{
		Push(queue, queue->head->data);
		Pop(queue);
	}
	cout << "Ввод элементов(" << n << "):\n";
	string str;
	for (int i = 1; i <= n; i++)
	{
		cout << i << ". ";
		getline(cin, str);
		Push(queue, str);
	}
	for (int i = 0; i < queue->size - n - k; i++)
	{
		Push(queue, queue->head->data);
		Pop(queue);
	}
}

void QueueToFile(Queue* queue, string path)
{
	ofstream file;
	file.open(path);
	if (!file.is_open())
	{
		cout << "Ошибка открытия\n";
	}
	else
	{
		if (IsEmpty(queue))
		{
			cout << "Очередь пуста\n";
		}
		else
		{
			for (int i = 0; i < queue->size; i++)
			{
				file << queue->head->data << "\n";
				Push(queue, queue->head->data);
				Pop(queue);
			}
		}
	}
	file.close();
}

void QueueFromFile(Queue* queue, string path)
{
	ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		cout << "Ошибка открытия\n";
	}
	else
	{
		string str;
		while (!file.eof())
		{
			str = "";
			file >> str;
			if (str != "")
			{
				Push(queue, str);
			}
		}
	}
	file.close();
}

void ClearQueue(Queue* queue)
{
	while (queue->head != nullptr)
	{
		Pop(queue);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	string path = "C:/Users/1/Desktop/lab8/Queue.txt";
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Размер очереди: ";
	int size;
	cin >> size;
	cout << "\n\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Queue* q = CreateQueue(size);
	cout << "\n\n";
	PrintQueue(q);
	cout << "\n\nУдалить элемент с ключом: ";
	string key;
	getline(cin, key);
	RemoveByData(q, key);
	cout << "\n\n";
	PrintQueue(q);
	cout << "\n\nДобавить элементов в начало очереди: ";
	int n;
	cin >> n;
	cout << "\n\n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	AddToQueue(q, 0, n);
	cout << "\n\n";
	PrintQueue(q);
	cout << "\n\nЗапись очереди в файл " << path << "\n\n\n";
	QueueToFile(q, path);
	ClearQueue(q);
	PrintQueue(q);
	cout << "\n\n";
	cout << "Чтение очереди из файла " << path << "\n\n\n";
	QueueFromFile(q, path);
	PrintQueue(q);
	cout << "\n\n\n\n";
}
