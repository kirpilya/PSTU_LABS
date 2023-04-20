#include <iostream>
#include "List.h"
#include "Pair.h"

using namespace std;

// class List
/*

template <typename T>
struct Node
{
    T data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

template <typename T>
class List
{

private:
    int size;
    Node<T>* head;
    Node<T>* tail;

public:
    List();
    List(int s, T k);
    List(const List<T>&);
    List(initializer_list<T> i_l);
    ~List();

    void push_back(T val);
    void pop_back();
    void push_front(T val);
    void pop_front();
    int get_size();

    List<T>& operator=(const List<T>& a);
    List<T>& operator=(initializer_list<T> i_l);

    template <typename T>
    friend ostream& operator<<(ostream& os, const List<T>& list);

    template <typename T>
    friend istream& operator>>(istream& is, List<T>& list);

    T& operator[](int idx);


public:

    class iter
    {
    private:
        Node<T>* p;
        List<T>* bl;
    public:

        friend class List<T>;

        iter()
        {
            this->p = nullptr;
            this->bl = nullptr;
        }

        iter(const List<T>::iter& it)
        {
            this->p = it.p;
            this->bl = it.bl;
        }

        List<T>::iter& operator=(const List<T>::iter& it)
        {
            this->p = it.p;
            this->bl = it.bl;
            return *this;
        }

        bool operator ==(const List<T>::iter& it)
        {
            return this->p == it.p;
        }

        bool operator !=(const List<T>::iter& it)
        {
            return this->p != it.p;
        }

        List<T>::iter& operator ++(int v)
        {
            this->p = this->p->next;
            return *this;
        }

        List<T>::iter& operator --(int v)
        {
            this->p = this->p->prev;
            return *this;
        }

        T& operator *()
        {
            return this->p->data;
        }
    };

public:

    List<T>::iter begin()
    {
        List<T>::iter temp;
        temp.p = this->head;
        temp.bl = this;
        return temp;
    }

    List<T>::iter end()
    {
        List<T>::iter temp;
        temp.p = this->tail->next;
        temp.bl = this;
        return temp;
    }

};



template <typename T>
List<T>::List()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
List<T>::List(int s, T k)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (int i = 0; i < s; i++)
    {
        this->push_back(k);
    }
}

template <typename T>
List<T>::List(const List<T>& a)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    if (a.size != 0)
    {
        Node<T>* temp = a.head;
        while (temp != nullptr)
        {
            this->push_back(temp->data);
            temp = temp->next;
        }
    }
}

template <typename T>
List<T>::List(initializer_list<T> i_l)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    const T* p = i_l.begin();
    while (p != i_l.end())
    {
        this->push_back(*p);
        p++;
    }
}

template <typename T>
List<T>::~List()
{
    Node<T>* temp;
    while (this->head != nullptr)
    {
        temp = this->head->next;
        delete this->head;
        this->head = temp;
    }
    this->size = 0;
    this->tail = nullptr;
}



template <typename T>
void List<T>::push_back(T val)
{
    Node<T>* new_node = new Node<T>;
    new_node->data = val;
    if (this->size != 0)
    {
        new_node->prev = this->tail;
        new_node->next = nullptr;
        this->tail->next = new_node;
        this->tail = new_node;
    }
    else
    {
        this->head = new_node;
        this->tail = new_node;
    }
    (this->size)++;
}

template <typename T>
void List<T>::pop_back()
{
    if (this->size == 0)
    {
        std::cout << "pop_back() : список пуст\n";
    }
    else if (this->size == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        (this->size)--;
    }
    else
    {
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        (this->size)--;
    }
}

template <typename T>
void List<T>::push_front(T val)
{
    Node<T>* new_node = new Node<T>;
    new_node->data = val;
    if (this->size != 0)
    {
        new_node->prev = nullptr;
        new_node->next = this->head;
        this->head->prev = new_node;
        this->head = new_node;
    }
    else
    {
        this->head = new_node;
        this->tail = new_node;
    }
    (this->size)++;
}

template <typename T>
void List<T>::pop_front()
{
    if (this->size == 0)
    {
        std::cout << "pop_front() : список пуст\n";
    }
    else if (this->size == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        (this->size)--;
    }
    else
    {
        this->head = this->head->next;
        delete this->head->prev;
        this->head->prev = nullptr;
        (this->size)--;
    }
}

template <typename T>
int List<T>::get_size()
{
    return this->size;
}



template <typename T>
List<T>& List<T>::operator=(const List<T>& a)
{
    if (this->head != a.head)
    {
        // очищение контейнера которому присваивается другой
        this->~List();

        //копирование присваемого контейнера
        if (a.size != 0)
        {
            Node<T>* temp = a.head;
            while (temp != nullptr)
            {
                this->push_back(temp->data);
                temp = temp->next;
            }
        }
    }
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(initializer_list<T> i_l)
{
    // очищение контейнера
    Node<T>* temp4del;
    while (this->head != nullptr)
    {
        temp4del = this->head->next;
        delete this->head;
        this->head = temp4del;
    }
    this->size = 0;
    this->tail = nullptr;

    const T* p = i_l.begin();
    while (p != i_l.end())
    {
        this->push_back(*p);
        p++;
    }

    return (*this);
}

template <typename T>
ostream& operator<<(ostream& os, const List<T>& list)
{
    Node<T>* temp = list.head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    return os;
}

template <typename T>
istream& operator>>(istream& is, List<T>& list)
{
    // очищение контейнера
    Node<T>* temp4del;
    while (list.head != nullptr)
    {
        temp4del = list.head->next;
        delete list.head;
        list.head = temp4del;
    }
    list.size = 0;
    list.tail = nullptr;

    std::cout << "Размер списка: ";
    int new_size = 0;
    T tmp;
    std::cin >> new_size;

    for (int i = 0; i < new_size; i++)
    {
        std::cout << i + 1 << ". ";
        std::cin >> tmp;
        list.push_back(tmp);
    }
    return is;
}

template <typename T>
T& List<T>::operator[](int idx)
{
    if (idx < 0)
    {
        cout << "Error index < 0\n";
    }
    else if (idx >= size)
    {
        cout << "Error index >= size\n";
    }
    else
    {
        Node<T>* temp = this->head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}
*/


int main()
{
    setlocale(LC_ALL, "Rus");

    List<int> L1 = { 1, 2, 3, 4, 5 };
    L1.push_back(10);
    cout << L1 << endl << endl;

    List<float> L2(5, 0.33);
    L2.pop_back();
    cout << L2 << endl << endl;

    List<double> L3 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    L3.push_front(9.99);
    cout << L3 << endl << endl;

    List<Pair> L4;

    Pair p1(1, 0.1);
    Pair p2(2, 1.1);
    Pair p3(0, 4.5);

    L4.push_back(p1);
    L4.push_back(p2);
    L4.push_back(p3);

    cout << ' ' << L4;

}