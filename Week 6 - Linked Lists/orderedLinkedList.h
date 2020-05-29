#ifndef H_orderedListType
#define H_orderedListType
 
#include "linkedList.h"
 
using namespace std; 
 
template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const; 
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise it returns false.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the proper place in the
      //               list, and count is incremented by 1.

    void insertFirst(const Type& newItem);
      //Function to insert newItem in the list.
      //Because the resulting list must be sorted, newItem is 
      //inserted at the proper in the list.
      //This function uses the function insert to insert newItem.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the proper in the list,
      //               and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem in the list.
      //Because the resulting list must be sorted, newItem is 
      //inserted at the proper in the list.
      //This function uses the function insert to insert newItem.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the proper in the list,
      //               and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list;
      //               first points to the first node of the 
      //               new list, and count is decremented by 1.
      //               If deleteItem is not in the list, an
      //               appropriate message is printed.
    void deleteSmallest();//Cottrell added

    void mergeLists(orderedLinkedList<Type>& list1, orderedLinkedList<Type>& list2);
};//end of class


template <class Type>
bool orderedLinkedList<Type>::
                 search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //pointer to traverse the list

    current = this->first;  //start the search at the first node

    while (current != nullptr && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
 
    if (found)
       found = (current->info == searchItem); //test for equality

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent = nullptr; //pointer just 
                                      //before current
    nodeType<Type> *newNode;  //pointer to create a node

    bool  found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;  //store newItem in the node
    newNode->link = nullptr;  //set the link field of the node
                              //to nullptr

    if (this->first == nullptr)  //Case 1
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        current = this->first;
        found = false;

        while (current != nullptr && !found) //search the list
           if (current->info >= newItem)
               found = true;
           else
           {
               trailCurrent = current;
               current = current->link;
           }
 
        if (current == this->first)      //Case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else                       //Case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == nullptr)
                this->last = newNode;

            this->count++;
        }
    }//end else
}//end insert

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent = nullptr; //pointer just 
                                            //before current
    bool found;

    if (this->first == nullptr) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;

        while (current != nullptr && !found)  //search the list
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == nullptr)   //Case 4
            cout << "The item to be deleted is not in the " 
                 << "list." << endl;
        else
            if (current->info == deleteItem) //the item to be 
                                   //deleted is in the list
            {
                if (this->first == current)       //Case 2
                {
                    this->first = this->first->link;

                    if (this->first == nullptr)
                        this->last = nullptr;

                    delete current;
                }
                else                         //Case 3
                {
                    trailCurrent->link = current->link;

                    if (current == this->last)
                        this->last = trailCurrent;

                    delete current;
                }
                this->count--;
            }
            else                            //Case 4
                cout << "The item to be deleted is not in the "
                     << "list." << endl;
    }
}//end deleteNode

//Cottrell added
template<class Type>
void orderedLinkedList<Type>::deleteSmallest()
{
    nodeType<Type>* current;
    nodeType<Type>* small;//hold smallest item in the list
    nodeType<Type>* trailCurrent = nullptr;
    nodeType<Type>* trailSmall = nullptr;

    //check for empty list
    if (this->first == nullptr) {
        cout << "Cannot delete from empty list\n";
        return;
    }

    //assume first entry is smallest
    small = this->first;
    trailCurrent = this->first;
    current = this->first->link;//start at second item in the list
    //traverse
    while (current != nullptr) {
        if (small->info > current->info) {
            trailSmall = trailCurrent;
            small = current;//make the current the smallest
        }
        trailCurrent = current;
        current = current->link;
    }//end of while, small will hold smallest item in the list

    //check to see if small is first in list
    if (small == this->first) {
        //move first to the second item
        this->first = this->first->link;
    }//end if
    else {
        trailSmall->link = small->link;//hold onto what small is pointing to
        if (small == this->last) {
            this->last = trailSmall;
        }//end nested if
    }//end else
    delete small;   //delete kills pointers in C++
    this->count--;  //subtract the one from count
}

template<class Type>
void orderedLinkedList<Type>::mergeLists(orderedLinkedList<Type>& list1, orderedLinkedList<Type>& list2)
{
    nodeType<Type>* newLast;//the last node of the new list
    nodeType<Type>* current1 = list1.first;
    nodeType<Type>* current2 = list2.first;

    this->initializeList();

    if (list1.first == nullptr && list2.first == nullptr) {
        return;//cannot merge two empty lists
    }
    else if (list1.first == nullptr) {//first list is empty
        //newlist is just the second list
        this->first = list2.first;
        this->count = list2.count;
        list2.destroyList();//kill the list - optional
        return;
    }
    else if (list2.first == nullptr) {
        this->first = list1.first;
        this->count = list1.count;
        list1.destroyList();//kill the list - optional
        return;
    }

    //neither list is empty
    
    //find the beginning of the new list
    //smaller of the two list first positions
    if (current1->info < current2->info) {
        this->first = current1;
        current1 = current1->link;
        newLast = this->first;
    }
    else {
        this->first = current2;
        current2 = current2->link;
        newLast = this->first;
    }

    //walk through both lists, 
    //moving the smallest of the current two items into the new list
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->info < current2->info) {
            //move current1's info into the list
            newLast->link = current1;
            newLast = current1;//newlast = current1 works as well
            current1 = current1->link;//walk to the next item in list1
        }
        else {
            //move current2's info into the list
            newLast->link = current2;
            newLast = current2;//newlast = current2 works as well
            current2 = current2->link;//walk to the next item in list1
        }
    }//end while

    //got to the end of one list, must handle the end of the new list
    if (current1 == nullptr) {
        newLast->link = current2;
    }
    else{
        newLast->link = current1;
    }
    this->last = newLast;
    this->count = list1.count + list2.count;
    list2.first = nullptr;
    list1.last = nullptr;
    list2.first = nullptr;
    list2.last = nullptr;
    //clear original lists
   // list1.destroyList();
    //list2.destroyList();
}

#endif