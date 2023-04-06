#include "EntertainmentCollection.h"
#include "Customer.h"

template <class T>
EntertainmentCollection<T>::EntertainmentCollection() : num_items(0) {}

template <class T>
EntertainmentCollection<T>::~EntertainmentCollection() {}

template <class T>
void EntertainmentCollection<T>::addItem(T* item) {
    if (num_items >= MAX_ITEMS) {
        throw FullCollection();
    }
    items[num_items] = item;
    num_items++;
}

template <class T>
T* EntertainmentCollection<T>::removeItem() {
    if (num_items == 0) {
        throw EmptyCollection();
    }
    T* item = items[num_items - 1];
    num_items--;
    return item;
}

template <class T>
int EntertainmentCollection<T>::getNumItems() const {
    return num_items;
}

template <class T>
T* EntertainmentCollection<T>::getItem(int index) {
    if(num_items==0 || index>= num_items){//first is redundant
        throw EmptyCollection();
    } else {
    
        return items[index];  //maybe this should be derefenreced.  things could go wrong here
    }
    
}

const char* EmptyCollection::what() const throw() {
    return "Error: Collection is empty.";
}

const char* FullCollection::what() const throw() {
    return "Error: Collection is full.";
}

template class EntertainmentCollection<Customer>;