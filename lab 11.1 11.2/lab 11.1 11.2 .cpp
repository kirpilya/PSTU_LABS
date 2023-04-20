#include <iostream>
#include <ctime>
#include <climits>
#include <string>
#include <fstream>
#include <windows.h>
#undef max()

using namespace std;


template <typename T>
void printarr(T* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int FileSize(string path)
{
    int size;
    ifstream file;
    file.open(path, ios::app | ios::binary);
    if (!file.is_open())
    {
        cout << "Ошибка открытия" << endl;
        return -1;
    }
    file.seekg(0, ios::end);
    size = file.tellg();
    file.close();
    return size;
}

int random(int start, int end)
{
    int a = (rand() % (end + 1));
    if (a < start && start > 0)
    {
        a += start;
    }
    return a;
}

void randarr(int* mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        mas[i] = random(0, 20);
    }
}


struct Node_od
{
    string data;
    Node_od* next = nullptr;
};

struct List_od
{
    int size = 0;
    Node_od* head = nullptr;
    Node_od* tail = nullptr;
};


bool ListIsEmpty(List_od* List)
{
    return (List == nullptr || List->size == 0);
}

void ListPushBack_od(List_od* List, string str)
{
    Node_od* new_node = new Node_od;
    new_node->data = str;
    if (ListIsEmpty(List))
    {
        List->head = new_node;
        List->tail = new_node;
    }
    else
    {
        List->tail->next = new_node;
        List->tail = new_node;
    }
    List->size++;
}

void ListPushFront_od(List_od* List, string str)
{
    Node_od* new_node = new Node_od;
    new_node->data = str;
    if (ListIsEmpty(List))
    {
        List->head = new_node;
        List->tail = new_node;
    }
    else
    {
        new_node->next = List->head;
        List->head = new_node;
    }
    List->size++;
}

List_od* CreateList_od(int size)
{
    List_od* List = new List_od;
    string str;
    if (size > 0)
    {
        cout << "Создание списка:\n";
        for (int i = 1; i <= size; i++)
        {
            cout << i << ". ";
            getline(cin, str);
            ListPushBack_od(List, str);
        }
        cout << endl;
    }
    return List;
}

void NodesOutput(Node_od* start_node, int c = 1)
{
    if (start_node == nullptr)
    {
        return;
    }
    else
    {
        cout << c << ". " << start_node->data << endl;
        NodesOutput(start_node->next, c + 1);
    }
}

void PrintList_od(List_od* List)
{
    if (ListIsEmpty(List))
    {
        cout << "Список пуст\n";
    }
    else
    {
        cout << "Содержимое списка(" << List->size << "):\n";
        NodesOutput(List->head, 1);
    }
}

Node_od* GetNodeByIndex_od(List_od* List, int index)
{
    if (!ListIsEmpty(List) && index < List->size)
    {
        if (index == 0)
        {
            //cout << List->head->data;
            return List->head;
        }
        else if (index == List->size - 1)
        {
            //cout << List->tail->data;
            return List->tail;
        }
        else
        {
            Node_od* temp = List->head;
            for (int i = 0; i < index; i++)
            {
                //cout << temp->data << endl;
                temp = temp->next;
            }
            return temp;
        }
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
Node_od* GetNodeByData_od(List_od* List, T data, int* index = nullptr)
{
    if (!ListIsEmpty(List))
    {
        int* idx = new int;
        *idx = 0;
        Node_od* temp = List->head;
        while (temp->data != data && temp->next != nullptr)
        {
            temp = temp->next;
            (*idx)++;
        }
        if (temp->data == data)
        {
            if (index != nullptr)
            {
                *index = *idx;
                delete idx;
            }
            else
            {
                delete idx;
            }

            return temp;
        }
        else
        {
            delete idx;
            return nullptr;
        }
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
void ListRemoveByData_od(List_od* List, T data)
{
    if (ListIsEmpty(List))
    {
        cout << "Список пуст\n";
    }
    else
    {
        Node_od* temp = List->head;
        if ((List->head == List->tail) && (data == List->head->data))
        {
            delete List->head;
            List->head = nullptr;
            List->tail = nullptr;
            List->size--;
        }
        else if (data == List->head->data)
        {
            temp = List->head;
            List->head = List->head->next;
            delete temp;
            List->size--;
        }
        else
        {
            while (temp->next != nullptr)
            {
                if (temp->next->data == data)
                {
                    if (temp->next == List->tail)
                    {
                        delete List->tail;
                        List->tail = temp;
                        List->tail->next = nullptr;
                    }
                    else
                    {
                        Node_od* temp2 = temp->next->next;
                        delete temp->next;
                        temp->next = temp2;
                    }
                    List->size--;
                    return;
                }
                temp = temp->next;
            }
            cout << "Элемент не найден\n";
        }
    }
}

void ListClear_od(List_od* List)
{
    Node_od* temp;
    while (List->head != nullptr)
    {
        temp = List->head->next;
        delete List->head;
        List->head = temp;
    }
    List->size = 0;
    List->tail = nullptr;
}

void push_before_node(List_od* List, int k, int n, Node_od* node)
{
    if (k == 0)
    {
        return;
    }
    Node_od* new_node = new Node_od;
    string str;
    getline(cin, str);
    new_node->data = str;
    push_before_node(List, k - 1, n, node);
    if (n == 1)
    {
        new_node->next = List->head;
        List->head = new_node;
    }
    else
    {
        new_node->next = node->next;
        node->next = new_node;
    }
    List->size++;

}

void ListPush_od(List_od* List, int k, int n)
{
    if (!ListIsEmpty(List) && n >= 1 && k > 0 && n <= List->size)
    {
        Node_od* node = GetNodeByIndex_od(List, n - 1);
        cout << "Ввод элементов:\n";
        push_before_node(List, k, n, node);
    }
    else
    {
        cout << "Список пуст или неверны значения\n";
    }
}

void ListToFile_od(List_od* List, string path)
{
    ofstream file;
    file.open(path);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла\n";
    }
    else
    {
        if (List->head != nullptr)
        {
            Node_od* temp = List->head;
            file << temp->data;
            file << '\n';
            while (temp->next != nullptr)
            {
                temp = temp->next;
                file << temp->data;
                file << '\n';
            }
        }
    }
    file.close();
}

void ListFromFile_od(List_od* List, string path)
{
    ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла\n";
    }
    else
    {
        string str = "-1";
        while (!file.eof())
        {
            getline(file, str);
            if (str != "")
            {
                ListPushBack_od(List, str);
            }
        }
    }
    file.close();
}


struct Node_td
{
    string data;
    Node_td* next = nullptr;
    Node_td* prev = nullptr;
};

struct List_td
{
    int size = 0;
    Node_td* head = nullptr;
    Node_td* tail = nullptr;
};


bool ListIsEmpty(List_td* List)
{
    return (List == nullptr || List->size == 0);
}

void ListPushBack_td(List_td* List, string str)
{
    Node_td* new_node = new Node_td;
    new_node->data = str;
    if (ListIsEmpty(List))
    {
        List->head = new_node;
        List->tail = new_node;
    }
    else
    {
        List->tail->next = new_node;
        new_node->prev = List->tail;
        List->tail = new_node;
    }
    List->size++;
}

void ListPushFront_td(List_td* List, string str)
{
    Node_td* new_node = new Node_td;
    new_node->data = str;
    if (ListIsEmpty(List))
    {
        List->head = new_node;
        List->tail = new_node;
    }
    else
    {
        new_node->prev = nullptr;
        new_node->next = List->head;
        List->head->prev = new_node;
        List->head = new_node;
    }
    List->size++;
}

List_td* CreateList_td(int size)
{
    List_td* List = new List_td;
    string str;
    if (size > 0)
    {
        cout << "Создание списка:\n";
        for (int i = 1; i <= size; i++)
        {
            cout << i << ". ";
            getline(cin, str);
            ListPushBack_td(List, str);
        }
        cout << endl;
    }
    return List;
}

void NodesOutput(Node_td* start_node, int c = 1)
{
    if (start_node == nullptr)
    {
        return;
    }
    else
    {
        cout << c << ". " << start_node->data << endl;
        NodesOutput(start_node->next, c + 1);
    }
}

void PrintList_td(List_td* List)
{
    if (ListIsEmpty(List))
    {
        cout << "Список пуст\n";
    }
    else
    {
        cout << "Содержимое списка(" << List->size << "):\n";
        NodesOutput(List->head, 1);
    }
}

Node_td* GetNodeByIndex_td(List_td* List, int index)
{
    if (!ListIsEmpty(List) && index < List->size)
    {
        if (index == 0)
        {
            //cout << List->head->data;
            return List->head;
        }
        else if (index == List->size - 1)
        {
            //cout << List->tail->data;
            return List->tail;
        }
        else
        {
            if (index < (List->size) / 2)
            {
                Node_td* temp = List->head;
                for (int i = 0; i < index; i++)
                {
                    //cout << temp->data << endl;
                    temp = temp->next;
                }
                return temp;
            }
            else
            {
                Node_td* temp = List->tail;
                for (int i = List->size - 1; i > index; i--)
                {
                    //cout << temp->data << endl;
                    temp = temp->prev;
                }
                return temp;
            }
        }
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
Node_td* GetNodeByData_td(List_td* List, T data, int* index = nullptr)
{
    if (!ListIsEmpty(List))
    {
        int* idx = new int;
        *idx = 0;
        Node_td* temp = List->head;
        while (temp->data != data && temp->next != nullptr)
        {
            temp = temp->next;
            (*idx)++;
        }
        if (temp->data == data)
        {
            if (index != nullptr)
            {
                *index = *idx;
                delete idx;
            }
            else
            {
                delete idx;
            }

            return temp;
        }
        else
        {
            delete idx;
            return nullptr;
        }
    }
    else
    {
        return nullptr;
    }
}

template <typename T>
void ListRemoveByData_td(List_td* List, T data)
{
    Node_td* node = GetNodeByData_td(List, data);
    if (node == nullptr)
    {
        cout << "Элемент отсутствует\n";
        return;
    }
    if (node->next != nullptr)
    {
        node->next->prev = node->prev;
    }
    if (node->prev != nullptr)
    {
        node->prev->next = node->next;
    }
    if (List->head == node)
    {
        List->head = node->next;
    }
    if (List->tail == node)
    {
        List->tail = node->prev;
    }
    List->size--;
    delete node;
}

void ListClear_td(List_td* List)
{
    Node_td* temp;
    while (List->head != nullptr)
    {
        temp = List->head->next;
        delete List->head;
        List->head = temp;
    }
    List->size = 0;
    List->tail = nullptr;
}

void ListAddBackNode_td(List_td* List, Node_td* node, int k)
{
    if (k == 0)
    {
        return;
    }
    Node_td* new_node = new Node_td;
    string str;
    getline(cin, str);
    new_node->data = str;
    new_node->prev = node;
    new_node->next = node->next;
    node->next = new_node;
    if (new_node->next != nullptr)
    {
        new_node->next->prev = new_node;
    }
    else
    {
        List->tail = new_node;
    }
    ListAddBackNode_td(List, new_node, k - 1);
    List->size++;
}

void ListAddFrontNode_td(List_td* List, Node_td* node, int k)
{
    if (k == 0)
    {
        return;
    }
    Node_td* new_node = new Node_td;
    string str;
    getline(cin, str);
    new_node->data = str;
    new_node->next = node;
    new_node->prev = node->prev;
    node->prev = new_node;
    if (new_node->prev == nullptr)
    {
        List->head = new_node;
    }
    else
    {
        new_node->prev->next = new_node;
    }
    ListAddFrontNode_td(List, node, k - 1);
    List->size++;
}

void ListAddBack_td(List_td* List, int index, int k)
{
    if (k == 0)
    {
        return;
    }
    Node_td* node = GetNodeByIndex_td(List, index);
    if (node != nullptr)
    {
        cout << "Ввод элементов:\n";
        ListAddBackNode_td(List, node, k);
    }
    else
    {
        cout << "Неверные данные\n";
    }
}

void ListAddFront_td(List_td* List, int index, int k)
{
    if (k == 0)
    {
        return;
    }
    Node_td* node = GetNodeByIndex_td(List, index);
    if (node != nullptr)
    {
        cout << "Ввод элементов:\n";
        ListAddFrontNode_td(List, node, k);
    }
    else
    {
        cout << "Неверные данные\n";
    }
}

void ListToFile_td(List_td* List, string path)
{
    ofstream file;
    file.open(path);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла\n";
    }
    else
    {
        if (List->head != nullptr)
        {
            Node_td* temp = List->head;
            file << temp->data;
            file << '\n';
            while (temp->next != nullptr)
            {
                temp = temp->next;
                file << temp->data;
                file << '\n';
            }
        }
    }
    file.close();
}

void ListFromFile_td(List_td* List, string path)
{
    ifstream file;
    file.open(path);
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла\n";
    }
    else
    {
        string str = "-1";
        while (!file.eof())
        {
            getline(file, str);
            if (str != "")
            {
                ListPushBack_td(List, str);
            }
        }
    }
    file.close();
}


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    string path = "C:/Users/1/Desktop/lab8/List.txt";

    cout << "Длина списка: ";
    int size;
    cin >> size;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    List_td* List = CreateList_td(size);
    PrintList_td(List);
    cout << "\nУдалить элемент с заданным ключем: ";
    string key;
    getline(cin, key);
    ListRemoveByData_td(List, key);
    cout << endl;
    PrintList_td(List);
    cout << "\nДобавить элементов в начало списка: ";
    int k;
    cin >> k;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ListAddFront_td(List, 0, k);
    cout << endl;
    PrintList_td(List);
    cout << "\nЗапись списка в файл " << path << "\n\n";
    ListToFile_td(List, path);
    ListClear_td(List);
    PrintList_td(List);
    cout << "\nЧтение списка из файла " << path << "\n\n";
    ListFromFile_td(List, path);
    PrintList_td(List);
    cout << "\n\n\n\n";
}