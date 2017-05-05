/***********************************************************************
 * Header:
 *    queue.h
 * Summary:
 *    Create a class encapsulating the notion of a queue
 * Author
 *    David Donovan, David Perez Jeffry Simpson
 ************************************************************************///

#ifndef queue_h
#define queue_h
#include <iostream>

using namespace std;

#include <cassert>

/************************************************
 * Queue
 * A class that holds our Queue
 ***********************************************/
template <class T>
class Queue
{
private:
   int m_Capacity, numPop, numPush, count;
   T * m_Array;
   
public:
   //Constructors
   Queue() : m_Capacity(0), numPop(0), numPush(0), m_Array(NULL), count(0) {}   //Default
   Queue(int numElements) throw(const char *);            //Non-Default
   Queue(const Queue & original) throw(const char *);     //Copy

   //Destructur
   ~Queue()    {  delete [] m_Array;  }
   
   //Operator =
   Queue <T> & operator = (const Queue <T> & rightHandSide) throw(const char *);
   
   
   //Inline functions
   bool  empty()      const    { return (size() == 0);         }

   bool isFull()      const    { return (count == m_Capacity); }
   bool triggered;

   int   size()       const    { return numPush - numPop;           } 
   int   capacity()   const    { return m_Capacity;      }
   void  clear()               { numPop = numPush = 0; }
   
   //Functions   
   void display(ostream & out) const;
   
   void push(const T & newValue)  throw (const char *);
   void pop()                     throw (const char *);
   T & front()                    throw (const char *);
   T   front()              const throw (const char *);
   void front(int newValue) const throw (const char *);
   T back() const throw(const char *);

   int iTail() const { return (numPush - 1) % m_Capacity; }
   int iHead() const { return numPop % m_Capacity; }

   void reallocate(const int &newSize = 0) throw (const char *);
   
};

/*******************************************
 * Queue :: Non-Default Constructor
 *******************************************/
template <class T>
Queue  <T> ::Queue(int numElements) throw(const char *)
{
   assert (numElements  > 0);
   
   // Allocate array
   m_Capacity = numElements;
   m_Array = new(nothrow) T[m_Capacity];
   
   // If allocated, set member values to default
   if (m_Array != NULL)
   {
      numPop = 0;
      numPush = 0;
      count = 0;
      triggered = false;
   }
   else
      throw "Error: No memory to allocate";
}

/*******************************************
 * Queue :: Copy Constructor
 *******************************************/
template <class T>
Queue <T> ::Queue(const Queue & original) throw(const char *) : m_Capacity(original.m_Capacity), numPop(original.numPop), numPush(original.numPush), count(original.count)
{
   int i, j;
   m_Array = new T[m_Capacity];
   for (i = this->numPop, j = 0; j < this->size(); i++, j++)
   {
      if (i == m_Capacity)
      {
         i = 0;
      }
      m_Array[i] = original.m_Array[i];
   }
}

/*******************************************
 * Queue :: Operator =
 *******************************************/
template <class T>
Queue <T> & Queue <T> ::operator=(const Queue <T> & rightHandSide) throw(const char *)
{

   if (this != &rightHandSide)                // check that not st = st
   {
      this->m_Capacity = rightHandSide.capacity();
      this->numPop = rightHandSide.numPop;
      this->numPush = rightHandSide.numPush;
      m_Array = new T[m_Capacity];

      int i, j;
      for (i = this->numPop, j = 0; j < this->size(); i++, j++)
      {
         if (i == m_Capacity)
         {
            i = 0;
         }
         m_Array[i] = rightHandSide.m_Array[i];
      }  
   }
   return *this;
}

/*******************************************
 * Queue :: Display()
 *******************************************/
template <class T>
void Queue <T> :: display(ostream & out) const
{
   int i, j;

   for (i = numPop, j = 0; j < size(); i++, j++)
   {
      if (i == m_Capacity)
      {
         i = 0;
      }
      out << m_Array[i] << endl;
   }

   out << "Front: " << iHead() << endl;
   out << "Back: " << iTail() << endl;
   out << "Capacity: " << m_Capacity << endl;
}

/*******************************************
 * Queue :: push()
 *******************************************/
template <class T>
void Queue <T> ::push(const T & newValue) throw(const char *)
{
   // Make sure memory is allocated
   if (m_Array == NULL)
   {
      m_Capacity = 2;
      try
      {
         m_Array = new T[m_Capacity];
      }
      catch (bad_alloc)
      {
         throw "ERROR: Can't allocate memory for the Queue!";
      }
   }

   if (size() == capacity())
   {
      m_Capacity *= 2;
      reallocate(m_Capacity);
   }
   
   numPush++;
   m_Array[iTail()] = newValue;
}

/*******************************************
 * Queue :: back()
 *******************************************/
template <class T>
void Queue <T> :: pop() throw(const char *)
{
   if (!empty())
   {
      numPop++;
   }
   else
      throw "ERROR: attempting to pop from an empty queue";
}

/*******************************************
 * Queue :: front()
 *******************************************/
template <class T>
T & Queue <T> :: front()       throw (const char *)
{
   if (!empty())
      return m_Array[iHead()];
   else
   {
      throw "ERROR: attempting to access an item in an empty queue";
      T garbage;
      return garbage;
   }
}

/*******************************************
 * Queue :: front()
 *******************************************/
template <class T>
T Queue <T> :: front() const throw (const char *)
{
   if (!empty())
      return m_Array[iHead()];
   else
   {
      throw "ERROR: attempting to access an item in an empty queue";
      T garbage;
      return garbage;
   }
}

template <class T>
void Queue <T> ::front(int newValue) const throw (const char *)
{
   if (!empty())
      m_Array[iHead()] = newValue;
   else
   {
      throw "ERROR: attempting to access an item in an empty queue";
   }
}

template <class T>
T Queue <T> ::back() const throw (const char *)
{
   if (!empty())
      return m_Array[iTail()];
   else
   {
      throw  "ERROR: attempting to access an item in an empty queue";
   }
}

/***************************************************
 * Queues :: REALLOCATE
 * Used for changing the size of oldBuffer
 **************************************************/
template <class T>
void Queue <T>::reallocate(const int &newSize) throw (const char *)
{
   // double the size
   int oldSize = newSize / 2;

   // Allocate new array
   T* newArray = new T[newSize];
   
   int i, j;

   for (i = numPop, j = 0; j < oldSize; i++, j++)
   {
      if (i == m_Capacity)
      {
         i = 0;
      }
      newArray[j] = m_Array[i];
   }

   // Cleanup
   delete[] m_Array;
   m_Array = newArray;
}

#endif /* Queue_h */


