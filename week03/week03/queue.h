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
<<<<<<< HEAD
   int m_Capacity, m_Front, m_Back, count;
=======
   int m_Capacity, numPop, numPush;
>>>>>>> origin/master
   T * m_Array;
   
public:
   //Constructors
<<<<<<< HEAD
   Queue() : m_Capacity(0), m_Front(0), m_Back(0), m_Array(NULL), count(0) {}   //Default
=======
   Queue() : m_Capacity(0), numPop(0), numPush(0), m_Array(NULL) {}   //Default
>>>>>>> origin/master
   Queue(int numElements) throw(const char *);            //Non-Default
   Queue(const Queue & original) throw(const char *);     //Copy
   
   //Destructur
   ~Queue()    {  delete [] m_Array;  }
   
   //Operator =
   Queue <T> & operator = (const Queue <T> & rightHandSide) throw(const char *);
   
   //Inline functions
<<<<<<< HEAD
   bool  empty()      const    { return (m_Front == m_Back);         }
   bool isFull()      const    { return (count == m_Capacity - 1); }
   bool triggered = false;
   
   int   size()       const    { return count;           }
   int   capacity()   const    { return m_Capacity;      }
   void  clear()               { m_Front = 0; m_Back = 0; }
   
   //Functions
=======
   bool  empty()      const    { return (size() == 0);      }
   int   size()       const    { return numPush - numPop;   } 
   int   capacity()   const    { return m_Capacity;         }
   void  clear()               { numPop = numPush = 0;      }
   int iTail()        const    { return (numPush - 1) % m_Capacity; }
   int iHead()        const    { return numPop % m_Capacity; }

   //Functions prototypes
>>>>>>> origin/master
   void display(ostream & out) const;
   
   void push(const T & newValue)  throw (const char *);
   void pop()                     throw (const char *);
   T & front()                    throw (const char *);
   T   front()              const throw (const char *);
   void front(int newValue) const throw (const char *);
   T back() const throw(const char *);
<<<<<<< HEAD
   
   T * reallocate(T * oldBuffer, int size) throw (const char *);
   
   // friend std::ostream & operator << (std::ostream & out, const T & rhs);
=======

   void reallocate(const int &newSize = 0) throw (const char *);
>>>>>>> origin/master
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
<<<<<<< HEAD
      m_Front = 0;
      m_Back = 0;
      count = 0;
=======
      numPop = 0;
      numPush = 0;
>>>>>>> origin/master
   }
   else
      throw "Error: No memory to allocate";
}

/*******************************************
 * Queue :: Copy Constructor
 *******************************************/
template <class T>
<<<<<<< HEAD
Queue <T> ::Queue(const Queue & original) throw(const char *) : m_Capacity(original.m_Capacity), m_Front(original.m_Front), m_Back(original.m_Back), count(original.count)
=======
Queue <T> ::Queue(const Queue & original) throw(const char *) : m_Capacity(original.m_Capacity), numPop(original.numPop), numPush(original.numPush)
>>>>>>> origin/master
{
   // No memory, lets make some!
   if (m_Capacity == 0 || m_Array  == NULL)
   {
<<<<<<< HEAD
      for (int pos = m_Front; pos != m_Back; pos = (pos + 1) % m_Capacity)
         m_Array[pos] = original.m_Array[pos];
=======
      m_Capacity = 2;
   }
   // Allocate memory
   m_Array = new T[m_Capacity];


   // Copy contents to new array
   int i, j;
   for (i = iHead(), j = 0; j < this->size(); i++, j++)
   {
      if (i == m_Capacity)
      {
         i = 0;
      }
      m_Array[i] = original.m_Array[i];
>>>>>>> origin/master
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
      // Copy all member variables
      this->m_Capacity = rightHandSide.capacity();
      this->numPop = rightHandSide.numPop;
      this->numPush = rightHandSide.numPush;
      m_Array = new T[m_Capacity];

      // Copy contents to new array
      int i, j;
      for (i = this->numPop, j = 0; j < this->size(); i++, j++)
      {
         if (i == m_Capacity)
         {
            i = 0;
         }
<<<<<<< HEAD
      }
      
      m_Front = rightHandSide.m_Front;             // copy m_Front member
      m_Back = rightHandSide.m_Back;               // copy m_Back member
      count = rightHandSide.count;                 // copy counter member
      for (int pos = m_Front; pos != m_Back; pos = (pos + 1) % m_Capacity)  // copy Queue elements
         m_Array[pos] = rightHandSide.m_Array[pos];
         
         }
=======
         m_Array[i] = rightHandSide.m_Array[i];
      }  
   }
>>>>>>> origin/master
   return *this;
}

/*******************************************
 * Queue :: Display()
 *          Show array contents
 *******************************************/
template <class T>
void Queue <T> :: display(ostream & out) const
{
<<<<<<< HEAD
   for (int i = m_Front; i != m_Back; i = (i + 1) % m_Capacity)
      out << m_Array[i] << endl;
   
   out << "Front: " << m_Front << endl;
   out << "Back: " << m_Back << endl;
=======
   // Display, used for debugging
   int i, j;
   for (i = numPop, j = 0; j < size(); i++, j++)
   {
      if (i == m_Capacity)
      {
         i = 0;
      }
      out << m_Array[i] << endl;
   }

   out << "Head: " << iHead() << endl;
   out << "Tail: " << iTail() << endl;
>>>>>>> origin/master
   out << "Capacity: " << m_Capacity << endl;
}

/*
 template <class T>
 std::ostream & operator << (std::ostream & out, const T & rhs)
 {
 for (int i = rhs.m_Front; i != rhs.m_Back; i = (i + 1) % rhs.m_Capacity)
 out << rhs.m_Array[i] << endl;
 
 return out;
 } */

/*******************************************
 * Queue :: push()
 *          Add content to end of array
 *******************************************/
template <class T>
void Queue <T> :: push(const T & newValue) throw(const char *)
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
<<<<<<< HEAD
   
   if (count == m_Capacity - 1)
   {
      m_Capacity *= 2;
      m_Array = reallocate(m_Array, m_Capacity);
   }
   
   // Circular array capacity
   int newBack = (m_Back + 1) % m_Capacity;
   
   // Queue isn't full
   if (newBack != m_Front)
   {
      m_Array[m_Back] = newValue;
      m_Back = newBack;
      count++;
   }
   else
      throw "The queue is full!\n";
   
=======

   // Capacity full, double size
   if (size() == capacity())
   {
      m_Capacity *= 2;
      reallocate(m_Capacity);
   }
   
   // Push to new tail
   
      numPush++;
      m_Array[iTail()] = newValue;
>>>>>>> origin/master
}

/*******************************************
 * Queue :: pop()
 *          Remove/advance head by one
 *******************************************/
template <class T>
void Queue <T> :: pop() throw(const char *)
{
<<<<<<< HEAD
   if (!empty())
   {
      count--;
      m_Front = (m_Front + 1) % m_Capacity;
   }
   else
      throw "ERROR: attempting to pop from an empty queue";
=======
   
      numPop++;
>>>>>>> origin/master
}

/*******************************************
 * Queue :: front()
 *          Return the head by reference
 *******************************************/
template <class T>
T & Queue <T> :: front()       throw (const char *)
{
   if (!empty())
      return m_Array[m_Front];
   else
   {
      throw "ERROR: attempting to access an item in an empty queue";
      T garbage;
      return garbage;
   }
}

/*******************************************
 * Queue :: front()
 *          Return the head as copy
 *******************************************/
template <class T>
T Queue <T> :: front() const throw (const char *)
{
   if (!empty())
      return m_Array[m_Front];
   else
   {
      throw "ERROR: attempting to access an item in an empty queue";
      T garbage;
      return garbage;
   }
}

/*******************************************
* Queue :: front()
*          Set the front with new value
*******************************************/
template <class T>
void Queue <T> ::front(int newValue) const throw (const char *)
{
   if (!empty())
      m_Array[m_Front] = newValue;
      else
      {
         throw "ERROR: attempting to access an item in an empty queue";
      }
}

/*******************************************
* Queue :: back()
*          Return the tail
*******************************************/
template <class T>
T Queue <T> ::back() const throw (const char *)
{
   if (!empty())
      return m_Array[m_Back];
   else
   {
      throw  "ERROR: attempting to access an item in an empty queue";
   }
}

/***************************************************
 * Queues :: reallocate()
 * Used for changing the size of oldBuffer
 **************************************************/
template <class T>
<<<<<<< HEAD
T * Queue <T>::reallocate(T * oldBuffer, int size) throw (const char *)
{
   // Used to iterate through old buffer
   int oldSize = size / 2;
   
   // Allocate new buffer
   T * newBuffer = new T[size];
   
   // Allocation failure check
   if (NULL == newBuffer)
   {
      //size /= 2;
      throw "ERROR: Unable to allocate a new buffer for Queue";
      return oldBuffer;
   }
   
   // Copy contents
   int i, j;
   for (i = m_Front, j = 0; j < oldSize; i++, j++)
=======
void Queue <T>::reallocate(const int &newSize) throw (const char *)
{
   // double the size
   int oldSize = newSize / 2;

   // Allocate new array
   T* newArray = new T[newSize];
   
   // Copy with wrap
   int i, j;
   for (i = numPush, j = 0; j < oldSize; i++, j++)
>>>>>>> origin/master
   {
      if (i == oldSize)
      {
         i = 0;
      }
      newBuffer[j] = oldBuffer[i];
   }
<<<<<<< HEAD
   //newBuffer[j] = '\0';
   
   m_Front = 0;
   m_Back = j - 1;
   
   // Delete old buffer
   delete[] oldBuffer;
   
   return newBuffer;
=======

   // Cleanup, set new pointer
   delete[] m_Array;
   m_Array = newArray;
>>>>>>> origin/master
}

#endif /* Queue_h */
