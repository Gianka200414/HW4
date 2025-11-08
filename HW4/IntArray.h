// IntArray.h  G.G
#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
using namespace std;

class IntArray
{
private:
    int* arr;                  // pointer to a dynamic integer array G.G
    static int total_entries;  // total number of array entries across all instances G.G
    int size;                  // number of values in this instance G.G

public:
    // Constructors and Destructor G.G
    IntArray();          // default constructor (size = 5) G.G
    IntArray(int size);  // parameterized constructor G.G
    ~IntArray();         // destructor (release dynamic memory) G.G

    // Member Functions
    int getSize() const;                // return number of values in this instance G.G
    int getValue(int index) const;      // return value at index (assert index is legal) G.G
    void replace(int index, int value); // replace value at index (assert index is legal) G.G
    void swap(int index_1, int index_2);// swap two values (assert both indexes are legal) G.G

    void print() const;                 // print all array values on one line G.G

    static int get_total_entries();     // return total number of entries across all instances G.G
    float get_instance_percent() const; // (size / total_entries) * 100 G.G
};

#endif
