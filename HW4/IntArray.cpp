// IntArray.cpp G.G
// IntArray.cpp Bad comment line
//Sikder Ishaq (S.I)
// ET580 Homework 4 - Task 3 implementation
// Implements all IntArray member functions per specifications.

#include "IntArray.h"
#include <cassert>   // for index range assertions (getValue)
#include <iostream>  // for print()
using namespace std; // sikder forgot to add this line G.G
// Initialize static field to track total entries across all live instances
int IntArray::total_entries = 0;

// Default constructor: size = 5, allocate dynamic array, add to total_entries
IntArray::IntArray()
{
   size = 5;
    arr = new int[size];
    // Initialize elements to 0 for predictable output
    for (int i = 0; i < size; ++i) arr[i] = 0;
    total_entries += size;
}
// Parameterized constructor: use provided size, allocate, add to total_entries
IntArray::IntArray(int size)
{
    this->size = size;
    arr = new int[this->size];
    for (int i = 0; i < this->size; ++i) arr[i] = 0;
    total_entries += this->size;
}

// Destructor: release dynamic memory and update total_entries to reflect live instances
IntArray::~IntArray()
{
      /*if (arr != nullptr) //No need to check arr != nullptr or set arr = nullptr in the destructor. 
      Just delete[] arr; (like we did in Project 1) is the pattern used in class. GG
    
        delete[] arr;
        arr = nullptr;
        Decrement total_entries so it reflects the current total across live instances
        total_entries -= size;
        */
    
    delete[] arr;
    total_entries -= size;
}

// Return the number of values in this instance
int IntArray::getSize() const
{
    return size;
}

// Return value at index; use assertion to enforce legal index
int IntArray::getValue(int index) const
{
    assert(index >= 0 && index < size);
    return arr[index];
}

// If index is legal, replace value at that index
void IntArray::replace(int index, int value)
{
    /*if (index >= 0 && index < size) no need for use if 
    Use assert (not “if-guards”) in replace and swap.
    The spec explicitly says: “Use an assertion to determine if the specified index is legal.”
    Right now replace and swap use if (...) { ... } and silently do nothing on illegal index. 
    That deviates from the instructions. G.G*/
        assert(index >=0 && index < size);
         arr[index] = value;
    
    // If index is illegal, do nothing (no I/O per spec)
}

// If both indexes are legal, swap their values
void IntArray::swap(int index_1, int index_2)
{
    /*if (index_1 >= 0 && index_1 < size && index_2 >= 0 && index_2 < size) // again we cannot use if G.G
    */
        assert(index_1 >= 0 && index_1 < size);
        assert(index_2 >= 0 && index_2 < size);
        int tmp = arr[index_1];
        arr[index_1] = arr[index_2];
        arr[index_2] = tmp;
    
}

// Print all array values on a single line
void IntArray::print() const
{
    /*for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i];
        if (i < size - 1) std::cout << ' ';
    }
    std::cout << std::endl;*/ //Use using namespace std; (consistent with header) and plain cout.G.G
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Return current total number of entries across all live instances
int IntArray::get_total_entries()
{
    return total_entries;
}

// Return percent: (size / total_entries) * 100 as float
float IntArray::get_instance_percent() const
{
    if (total_entries <= 0) return 0.0f; // avoid divide-by-zero
    //return static_cast<float>(size) / static_cast<float>(total_entries) * 100.0f; no need for this G.G
    return (size * 100.0f) / total_entries;
}
