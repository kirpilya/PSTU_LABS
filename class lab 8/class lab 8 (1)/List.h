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
    List(List&);
    List(initializer_list<int> i_l);
    ~List();

    void push_back(int val);
    void pop_back();
    void push_front(int val);
    void pop_front();
    int get_size();

    List& operator=(List& a);
    List& operator=(initializer_list<int> i_l);
    friend ostream& operator<<(ostream& os, const List& list);
    friend istream& operator>>(istream& is, List& list);


    int& operator[](int idx);
    List& operator +(List&);
    void operator +(int);

};

