//
//  linkedlist.h
//  assignment_4
//
// reference of linked list implementation = dr. amr goneid's c++ linked list slides


#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <vector>
using namespace std;

// struct for linked list node
struct node
{
    int num; // value of each node
    int count; // number of occurrences of each value
    node* next; // pointer to next node
    
    // constructor
    node(int n, int c) : num(n), count(c), next(nullptr)
    {
        
    }
};


// class that implements a linked list
class linkedlist
{
private:
    node* head; // first node pointed to by head
    
public:
    linkedlist() : head(nullptr)
    {
        
    }
    
    // function that adds a node
    void add(int num, int count)
    {
        // pnew is a pointer to a new node
        node* pnew;
        pnew = new node(num, count);
        
        // if the pointer to first node is empty
        if (head == nullptr)
        {
            head = pnew; // insert new node at head
        }
        else
        {
            node* cursor = head; // current node
            while (cursor->next != nullptr)
            {
                cursor = cursor->next;
            }
            cursor->next = pnew;
        }
    }
    
    // function that removes a node
    void remove(int num)
    {
        node* cursor = head; // curent node
        node* prev = nullptr; // previous node
        
        while (cursor != nullptr && cursor->num != num)
        {
            prev = cursor;
            cursor = cursor->next;
        }
        
        if (cursor == nullptr)
        {
            cout << "the integer you wish to remove was not found in the list." << endl;
        }
        else if (prev == nullptr)
        {
            head = cursor->next;
            delete cursor;
        }
        else
        {
            prev->next = cursor->next;
            delete cursor;
        }
    }
    
    // function that prints all elements of linked list & their occurence
    void print()
    {
        node* cursor = head;
        
        while (cursor != nullptr)
        {
            cout << cursor->num << "(" << cursor->count << ")" << " ";
            cursor = cursor->next;
        }
        cout << endl;
    }
    
    // returns the sum of all nodes by traversing through linked list
    int sum()
    {
        int sum = 0;
        node* cursor = head;
        
        while (cursor != nullptr)
        {
            sum = sum + cursor->num * cursor->count;
            cursor = cursor->next;
        }
        return sum;
    }
    
};

// creates linked list based on the vector’s elements
linkedlist create(vector <int> & v)
{
    int size = v.size();
    linkedlist mylist;
    
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        int num = v[i];
        
        for (int j = i + 1; j < size; j++)
        {
            if (v[j] == num)
            {
                count++;
                v.erase(v.begin() + j);
                size--;
                j--;
            }
        }
        mylist.add(num, count);
    }
    return mylist;
}


#endif /* linkedlist_h */
