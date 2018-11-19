#include <iostream>
#include <iterator>
#include "reflection.hpp"

using namespace agm::reflection;
using namespace std;

template <class T> class Widget
{
    CLASS(Widget, NullClass);

    CONSTRUCTOR(public, Widget, ())
    : storage()
    {
	cout << "default constructor called" << endl;
    }

    CONSTRUCTOR(public, Widget, (const Widget& x) )
    : storage(x.storage)
    {
	cout << "copy constructor called" << endl;
    }

    CONSTRUCTOR(public, Widget, (const T& y) )
    : storage(y)
    {
	cout << "Widget(T) called with " << y << endl;
    }

    METHOD(public, void, store, (T x))
    {
	cout << "calling store with " << x << endl;
	this->storage = x;
    }

    virtual ~Widget() {}

private:
    T storage;
};

template <class X, class Y> class Label : public Widget<X>
{
    CLASS(Label, Widget<X>);
    CONSTRUCTOR(public, Label, ())
    : Widget<X>(), y_store()
    {
	cout << "default constructor called" << endl;
    }

    CONSTRUCTOR(public, Label, (const Label& x) )
    : Widget<X>(x), y_store(x.y_store)
    {
	cout << "copy constructor called" << endl;
    }

    CONSTRUCTOR(public, Label, (const X& x, const Y& y) )
    : Widget<X>(x), y_store(y)
    {
	cout << "Label(x,y) called with " << y << endl;
    }

    METHOD(public, void, store2nd, (Y y))
    {
	cout << "calling store2nd with " << y << endl;
	y_store = y;
    }

    
private:
    Y y_store;
};

int main()
{
    // remember to we must instanate because it is in the Class registry
    Label<int, double> j(12,23.34);
    Label<string, string> k("base parameter", "deviced parameter");

    cout << "Dump Classes: " << j.getClass() << endl;

    // automatic down casting
    j.getClass().getMethod("store2nd").invokeVoid(&j, 99.99);


    k.getClass().getMethod("store").invokeVoid(&k, string("my example"));

}
