#pragma once
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class List
{

private:
    int size;
    Node* head;
    Node* tail;

public:
    List();
    List(int s, int k);
    List(const List&);
    List(initializer_list<int> i_l);
    ~List();

    void push_back(int val);
    void pop_back();
    void push_front(int val);
    void pop_front();
    int get_size();

    List& operator=(const List& a);
    List& operator=(initializer_list<int> i_l);
    friend ostream& operator<<(ostream& os, const List& list);
    friend istream& operator>>(istream& is, List& list);
    int& operator[](int idx);
    List& operator +(int);
    List& operator +(List&);

public:
    class iter
    {
    private:
        Node* p;
        List* bl;
    public:

        friend class List;
        iter();
        iter(const List::iter& it);

        iter& operator=(const List::iter& it);
        bool operator ==(const List::iter& it);
        bool operator !=(const List::iter& it);
        iter& operator ++(int v);
        iter& operator --(int v);
        int& operator *();
    };

public:
    List::iter begin();
    List::iter end();
};

