// Giankarlo Gomez 7/11/26 Giankarlo Gomez = G.G
// Sikder Ishaq (S.I)
// ET580 Homework 4 - Task 4 implementation
// Tests all IntArray member functions without console input.

#include <iostream>
#include "IntArray.h"
using namespace std;

int main()
{
    IntArray a;  // just to confirm it compiles G.G
    IntArray b(10);    // parameterized size = 10

    // Test replace() with legal indexes
    for (int i = 0; i < a.getSize(); ++i)
    {
        a.replace(i, (i + 1) * 10); // 10,20,30,40,50
    }

    // Test swap() with legal indexes
    a.swap(0, a.getSize() - 1); // swap first and last: 50,20,30,40,10

    // Test getValue() with legal index and print()
    cout << "Array a values: ";
    a.print();
    cout << "a[2] = " << a.getValue(2) << endl; // expect 30

    /* Test replace() with illegal index (should do nothing)
    a.replace(-1, 999);
    a.replace(a.getSize(), 999);
    cout << "Array a after illegal replace attempts: ";
    a.print();//  Illegal index tests cause assert to abort the program
    // G.G*/

    // Populate b with identifiable values
    for (int i = 0; i < b.getSize(); ++i)
    {
        b.replace(i, i); // 0..9
    }
    cout << "Array b values: ";
    b.print();

    // Test swap() on b
    b.swap(3, 7); // swap values at indexes 3 and 7
    cout << "Array b after swap(3,7): ";
    b.print();

    // Test static get_total_entries() and instance percent
    cout << "Total entries across instances: " << IntArray::get_total_entries() << endl;
    cout.setf(ios::fixed); cout.precision(2);
    cout << "Instance a percent: " << a.get_instance_percent() << "%\n";
    cout << "Instance b percent: " << b.get_instance_percent() << "%\n";

    // Completed tests (no cin used). Program ends, destructors run.
    return 0;
}
