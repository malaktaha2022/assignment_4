/*
 Malak Abdelhalim
 900222407
 Assignment 4
 Wed 19 April
 */

#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

// inserts the second value after each occurence of the first
void insertAfter (vector <int> & v, int firstValue, int secondValue)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        //traverses array and if value equal to firstvalue
        if (v[i] == firstValue)
        {
            // insert secondvalue in space right after
            v.insert(v.begin() + i + 1, secondValue);
            i++; // to skip the recently entered value
            size++; // updating size
        }
    }
}

int main()
{
    // n integers to be stored in vector of int
    int n;
    cout << "please enter the number of integers you wish to store in the vector: ";
    cin >> n;
    
    vector <int> v(n);
    
    // adding elements to vector
    cout << "please enter the elements of your vector: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    cout << "your vector: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    int firstValue, secondValue;
    
    cout << "please enter the first value: ";
    cin >> firstValue; // the value searched for in vector

    cout << "please enter the second value: ";
    cin >> secondValue; // the value added after each occurence of first value
    
    insertAfter(v, firstValue, secondValue);
    
    cout << "your modified vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    linkedlist mylist = create(v);
    
    cout << "your linked list: " << endl;
    mylist.print();
    
    cout << "sum of list's nodes: " << mylist.sum() << endl;;
    
    int add, count;
    cout << "please enter value to add and its occurences: ";
    cin >> add >> count;
    mylist.add(add,count);
    
    cout << "your linked list: " << endl;
    mylist.print();
    
    cout << "sum of list's nodes: " << mylist.sum() << endl;
    
    int remove;
    cout << "please enter value to remove: ";
    cin >> remove;
    mylist.remove(remove);
    
    cout << "your linked list: " << endl;
    mylist.print();
    
    cout << "sum of list's nodes: " << mylist.sum() << endl;;
}
