#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H

#include <iostream>

template <class T>
class EntertainmentCollection {
public:
    EntertainmentCollection();
    ~EntertainmentCollection();
    void addItem(T* item);
    T* removeItem();
    int getNumItems() const;
    T* getItem(int index);
private:
    static const int MAX_ITEMS = 100;
    T* items[MAX_ITEMS];
    int num_items;
};

class EmptyCollection : public std::exception {
public:
    const char* what() const throw();
};

/*
A class exception is a type of exception that is defined as a class in C++.
It is usually derived from the std::exception class
, which is a built-in C++ class that provides a basic interface for all exceptions.
By deriving from std::exception, a class exception can inherit the basic properties
and methods of the std::exception class.
*/

class FullCollection : public std::exception {
public:
    const char* what() const throw();
};

/*
The what() method is a virtual method in the std::exception class that returns a C-style string
describing the exception. By overriding the what() method in the FullCollection class,
we can provide a custom message to describe the specific error that occurred.
*/

/*
The throw() keyword at the end of the what() method declaration indicates that
this method will not throw any exceptions itself. This is necessary because the what() method
is declared as const, which means it cannot modify the object's state. By declaring the what()
method as throw(), we are indicating that it will not throw any exceptions that would violate
this const requirement.
*/

#endif // ENTERTAINMENTCOLLECTION_H
