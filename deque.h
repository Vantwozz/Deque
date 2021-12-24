#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

template <class InfoType>

class deque
{
private:
    class QItem//класс элемента дека
    {
    public:
        InfoType info;
        QItem* next;
        QItem* prev;
        QItem(InfoType Ainfo) : info(Ainfo), prev(nullptr), next(nullptr) {}
    };
    QItem* first, * last;//указатели на первый и последний элементы
    unsigned size;//размер дека
    void Erase();//очистка дека
    void Clone(const deque& D);//создание точной копии дека
    InfoType GetElement(unsigned);//получить n-ный с начала элемент очереди
    bool Empty() const;//проверка на пустоту очереди
public:
    const InfoType GetFirst() const;//получение информации, которая хранится в первом элементе
    const InfoType GetLast() const;//получение информации, которая хранится в первом элементе
    unsigned GetSize();//узнать размер очереди
    deque();//конструктор по умолчанию, создающий пустой дек
    deque(const deque&);//конструктор копирования
    ~deque();//деструктор
    deque& operator = (const deque&);//оператор присваивания
    friend ostream& operator << (ostream&, const deque<InfoType>&);//оператор <<
    ostream& Print(ostream&);//вывод в поток всех элементов дека в нормальном порядке
    ostream& PrintReverse(ostream&);//вывод в поток всех эдементов дека в обратном порядке
    void PushLast(InfoType);//добавление элемента в конец дека
    bool PopLast();//удаление элемента из конца дека
    void PushFirst(InfoType);//добавление элемента в начало дека
    bool PopFirst();//удаление элемента из начала дека
};
template <class InfoType>
bool deque <InfoType> ::Empty() const {
    if (first == nullptr)
        return true;
    return false;
}

template <class InfoType>
const InfoType deque <InfoType> ::GetFirst() const
{
    if (Empty())
    {
        throw runtime_error("Deque is empty");
    }

    return first->info;
}
template <class InfoType>
const InfoType deque <InfoType> ::GetLast() const
{
    if (Empty())
    {
        throw runtime_error("Deque is empty");
    }

    return last->info;
}
template <class InfoType>
ostream& operator << (ostream& s, const deque<InfoType>& D)
{

    for (int i = 0; i < D.size; i++)
    {
        s << D.getElement(i) << " ";
    }
    s << endl;
    for (int i = D.size - 1; i >= 0; i--)
    {
        s << D.getElement(i) << " ";
    }
    s << endl;

    return s;
}

template <class InfoType>
void deque <InfoType> ::Erase() {
    while (PopLast());
    size = 0;
}

template <class InfoType>
void deque <InfoType> ::Clone(const deque<InfoType>& D) {
    QItem* tmp = D.last;
    for (unsigned i = 0; i < D.size; i++)
    {
        PushLast(tmp->info);
        tmp = tmp->next;
    }
}

template <class InfoType>
InfoType deque <InfoType> ::GetElement(unsigned number) {
    if (!Empty()) {
        QItem* tmp = last;
        for (int i = 0; i < number; i++)
        {
            tmp = tmp->next;
        }

        return tmp->info;
    }
    else {
        return NULL;
    }
}


template <class InfoType>
deque <InfoType> ::deque() : first(nullptr), last(nullptr), size(0) {

}

template <class InfoType>
deque<InfoType> ::deque(const deque<InfoType>& D) {
    size = 0;
    Clone(D);
}

template <class InfoType>
deque <InfoType> :: ~deque() {
    Erase();
}

template <class InfoType>
void deque <InfoType>::PushLast(InfoType Ainfo) {
    QItem* tmp = new QItem(Ainfo);
    if (size > 0)
    {
        tmp->prev = first;
        first->next = tmp;
    }
    else
    {
        last = tmp;
    }
    first = tmp;
    size++;
}
template <class InfoType>
void deque <InfoType>::PushFirst(InfoType Ainfo) {
    QItem* tmp = new QItem(Ainfo);
    if (size > 0)
    {
        tmp->next = last;
        last->prev = tmp;
    }
    else
    {
        first = tmp;
    }
    last = tmp;
    size++;
}

template <class InfoType>
bool deque <InfoType>::PopLast() {
    if (size == 0) {
        return false;
    }
    QItem* tmp = first;
    if (size > 1) {
        first = first->prev;
    }
    delete tmp;
    size--;
    first->next = nullptr;
    if (size == 0)
    {
        first = nullptr;
        last = nullptr;
    }
    return true;
}

template <class InfoType>
bool deque <InfoType>::PopFirst() {
    if (size == 0) {
        return false;
    }
    QItem* tmp = last;
    last = last->next;
    delete tmp;
    size--;
    if (last) {
        last->prev = nullptr;
    }
    if (size == 0)
    {
        first = nullptr;
        last = nullptr;
    }
    return true;
}
template <class InfoType>
deque<InfoType>& deque <InfoType>::operator = (const deque<InfoType>& D) {
    if (this != &D)
    {
        Erase();
        Clone(D);
    }
    return *this;

}

template <class InfoType>
unsigned deque <InfoType>::GetSize() {
    return size;
}

template<class InfoType>
ostream& deque<InfoType>::Print(ostream& s) {
    for (int i = 0; i < size; i++)
    {
        s << GetElement(i) << " ";
    }
    s << endl;
    return s;
}
template <class InfoType>
ostream& deque <InfoType> ::PrintReverse(ostream& s) {
    for (int i = size - 1; i >= 0; i--)
    {
        s << GetElement(i) << " ";
    }
    s << endl;
    return s;
}
