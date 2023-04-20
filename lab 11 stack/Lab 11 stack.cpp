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
    Node* next_ptr = nullptr;
};

struct Stack
{
    Node* head = nullptr;
    int size = 0;
};


void Push(Stack& stack, string data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next_ptr = stack.head;
    stack.head = new_node;
    stack.size++;
}

void Pop(Stack& stack)
{
    if (stack.head != nullptr)
    {
        Node* temp = stack.head;
        stack.head = stack.head->next_ptr;
        delete temp;
        stack.size--;
    }
}

Stack CreateStack(int size)
{
    Stack stack;
    string str;
    cout << "Создание стека(" << size << "):\n";
    for (int i = 1; i <= size; i++)
    {
        cout << i << ". ";
        getline(cin, str);
        Push(stack, str);
    }
    stack.size = size;
    return stack;
}

void ClearStack(Stack& stack)
{
    while (stack.head != nullptr)
    {
        Pop(stack);
    }
}

void print_node(Node* node, int i)
{
    if (node->next_ptr == nullptr)
    {
        cout << i << ". " << node->data << endl;
        return;
    }
    print_node(node->next_ptr, i - 1);
    cout << i << ". " << node->data << endl;
    return;
}

void PrintStack(Stack& stack)
{
    if (stack.head == nullptr)
    {
        cout << "Список пуст\n";
        return;
    }
    cout << "Содержимое стека(" << stack.size << "):\n";
    print_node(stack.head, stack.size);
}

void RemoveByData(Stack& stack1, string data)
{
    Stack stack2;
    //Node* temp = stack1.head;
    //cout << stack1.head->data << endl << (stack1.head->next_ptr != nullptr || stack1.head->data != data) << endl;
    while ((stack1.head->next_ptr != nullptr) && (stack1.head->data != data))
    {
        //cout << stack1.head->data << endl;
        Push(stack2, stack1.head->data);
        Pop(stack1);
    }
    if (stack1.head->data == data)
    {
        Pop(stack1);
        while (stack2.head != nullptr)
        {
            Push(stack1, stack2.head->data);
            Pop(stack2);
        }
    }
    else
    {
        cout << "Элемент отсутсвует\n";
        while (stack2.head != nullptr)
        {
            Push(stack1, stack2.head->data);
            Pop(stack2);
        }
    }

}

void AddToStack(Stack& stack1, int k, int n)
{
    Stack stack2;
    for (int i = stack1.size; i > k; i--)
    {
        Push(stack2, stack1.head->data);
        Pop(stack1);
    }
    cout << "Добавление элементов:\n";
    for (int i = 0; i < n; i++)
    {
        string str;
        cout << i + 1 << ". ";
        getline(cin, str);
        Push(stack1, str);
    }
    while (stack2.head != nullptr)
    {
        Push(stack1, stack2.head->data);
        Pop(stack2);
    }
}

void StackToFile(Stack& stack1, string path)
{
    ofstream file;
    file.open(path);
    if (!file.is_open())
    {
        cout << "Ошибка открытия\n";
    }
    else
    {
        Stack stack2;
        while (stack1.head != nullptr)
        {
            Push(stack2, stack1.head->data);
            Pop(stack1);
        }
        while (stack2.head != nullptr)
        {
            file << stack2.head->data << "\n";
            Push(stack1, stack2.head->data);
            Pop(stack2);
        }
    }
    file.close();
}

void StackFromFile(Stack& stack, string path)
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
            getline(file, str);
            if (str != "")
            {
                Push(stack, str);
            }
        }
    }
    file.close();
}


int main()
{
    setlocale(LC_ALL, "Rus");
    string path = "C:/Users/1/Desktop/lab8/Stack.txt";

    cout << "Размер стека: ";
    int size;
    cin >> size;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Stack stack = CreateStack(size);
    cout << "\n\n";
    PrintStack(stack);
    cout << "\n\nУдалить элемент с ключем: ";
    string key;
    getline(cin, key);
    RemoveByData(stack, key);
    cout << "\n\n";
    PrintStack(stack);
    cout << "\n\n";
    cout << "Добавить элементов в начало списка: ";
    int n;
    cin >> n;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    AddToStack(stack, 0, n);
    cout << "\n\n";
    PrintStack(stack);
    cout << "\n\n";
    cout << "Запись стека в файл " << path << "\n";
    StackToFile(stack, path);
    cout << "\n\n";
    ClearStack(stack);
    PrintStack(stack);
    cout << "\n\nЧтение стрека из файла " << path << "\n";
    StackFromFile(stack, path);
    cout << "\n\n";
    PrintStack(stack);
    cout << "\n\n\n\n";
}