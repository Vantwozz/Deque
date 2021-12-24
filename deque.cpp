#include <iostream>
#include "deque.h"

int main()
{
	cout << "deque <int> :" << endl;
	deque <int> a;
	a.PushLast(1);
	a.PushLast(5);
	a.PushLast(8);
	a.PushLast(0);
	deque <int> a2 = a;
	a2.Print(cout);
	a.Print(cout);
	a.PrintReverse(cout);
	cout << "deque <double> :" << endl;
	deque <double> d;
	d.PushLast(0.25);
	d.PushLast(4);
	d.PushFirst(3.5);
	d.PushLast(2.0);
	deque <double> d2 = d;
	d2.Print(cout);
	d.Print(cout);
	d.PrintReverse(cout);
	cout << "deque <char>:" << endl;
	deque<const char*> ch;
	ch.PushLast("Wow");
	ch.PushLast("!");
	ch.PushLast("it");
	ch.PushLast("works");
	ch.PushLast("!");
	deque <const char*> ch2 = ch;
	ch.Print(cout);
	ch2.Print(cout);
	ch.PrintReverse(cout);
}