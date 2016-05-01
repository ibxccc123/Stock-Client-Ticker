#ifndef DLIST_H_
#define DLIST_H_

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::iostream;
using std::ostringstream;
using std::cout;
using std::cerr;
using std::endl;



template <typename I>  
class DList;

template <typename I>
struct DNode {

  DList<I>* myList;

  I data;
  DNode<I>* prev;
  DNode<I>* next;

  DNode(DList<I>* myList, const I& item, DNode<I>* prev = NULL,
                                         DNode<I>* next = NULL)
   : myList(myList), data(item), next(next), prev(prev)
  { }
};


template <typename I>    //Written by KWR.
class DList {
   DNode<I>* firstNode;  //by convention, a "real" node
   DNode<I>* endNode;    //by convention, a dummy node. Use to end while loops.

   // INV: firstNode points to first node, endNode to dummy node
   // INV: Empty list exactly when firstNode == endNode == the dummy node
   // INV: endNode never changes;

 public:
   DList<I>()
    : firstNode(new DNode<I>(NULL, I(), NULL, NULL))
    , endNode(firstNode)
   { firstNode->myList = endNode->myList = this;}

   /** Example of destructor added by KWR.  Using "cerr" guarantees
       immediate screen output.
    */
   virtual ~DList<I>() {
      //cerr << "This list will self-destruct in 5 nanoseconds..." << endl;
      DNode<I>* current = endNode;
      while (current != firstNode) {

          //cerr << "Deleting: " << current->data << "; ";

          current = current->prev;
         delete(current->next);
      }
      //delete(current);  //do you dare comment this in?
      //cerr << "Deleting: " << current->data << "; done." << endl;
 delete(current);  //i.e. delete(firstNode);
   }

   void clear()
   {
          //cerr << "This list will self-destruct in 5 nanoseconds..." << endl;
      DNode<I>* current = endNode;
      while (current != firstNode) {
         //cerr << "Deleting: " << current->data << "; ";
         current = current->prev;
         delete(current->next);
      }
      //delete(current);  //do you dare comment this in?
      //cerr << "Deleting: " << current->data << "; done." << endl;
      delete(current);  //i.e. delete(firstNode);

          endNode = firstNode = new DNode<I>(this, I(), NULL, NULL);
   }

   class iterator {
      friend class DList<I>;
      friend struct DNode<I>;  //needed?

      DNode<I>* curr;

      explicit iterator(DNode<I>* given) : curr(given) { }

     public:
 //default copy-ctor and operator= are OK
          iterator():curr(NULL){}

      I& operator*() const { return curr->data; }  //allows assignment

      //REQ
      iterator& operator++() {
         curr = curr->next;
         return *this;
      }

      //REQ
      iterator operator++(int x) {
         iterator oldMe = *this;
         curr = curr->next;
         return oldMe;
      }

      bool operator==(const iterator& other) const {
         return curr == other.curr;
      }
      bool operator!=(const iterator& other) const {
         return curr != other.curr;
      }
   };
  DNode<I>* pbegin() const { return firstNode; }
   DNode<I>* pend() const { return endNode; }

   iterator begin() const { return iterator(firstNode); }
   iterator end() const { return iterator(endNode); }

   void insert(DNode<I>* beforeMe, I newItem) {
      DNode<I>* newNode = new DNode<I>(this,newItem,beforeMe->prev,beforeMe);
      if (beforeMe->prev != NULL) {   //i.e. if we're not inserting a new first
         beforeMe->prev->next = newNode;
         beforeMe->prev = newNode;  //don't forget!
      } else {
         beforeMe->prev = newNode;
         firstNode = newNode;
      }
   }

   iterator insert(iterator it_beforeMe, I newItem) {
          DNode<I>* beforeMe = it_beforeMe.curr;
          insert(beforeMe, newItem);
          return iterator(beforeMe->prev);
   }
   size_t size() const {            //illustrates size_t (unsigned int) type
      size_t count = 0;
      DNode<I>* current = firstNode;
      while (current != endNode) {
         count++;
         current = current->next;
      }
      return count;
   }


   string toString() const {
      ostringstream OUT;

      iterator itr = begin();

      while (itr != end()) {

         OUT << *itr << " ";
         ++itr;
      }
      return OUT.str();
   }
   string str() const {
      return toString();
   }

};
#endif
