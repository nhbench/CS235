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
   int m_Capacity, m_Front, m_Back, count;
   T * m_Array;
   
public:
   //Constructors
   Queue() : m_Capacity(0), m_Front(0), m_Back(0), m_Array(NULL), count(0) {}   //Default
   Queue(int numElements) throw(const char *);            //Non-Default
   Queue(const Queue & original) throw(const char *);     //Copy
   
   //Destructur
   ~Queue()    {  delete [] m_Array;  }
   
   //Operator =
   Queue <T> & operator = (const Queue <T> & rightHandSide) throw(const char *);

   
   //Inline functions
   bool  empty()      const    { return (m_Front == m_Back);         }
   bool isFull()      const    { return (count == m_Capacity - 1); }
   bool triggered = false;

   int   size()       const    { return count;           } 
   int   capacity()   const    { return m_Capacity;      }
   void  clear()               { m_Front = 0; m_Back = 0; }
   
   //Functions   
   void display(ostream & out) const;
   
   void push(const T & newValue)  throw (const char *);
   void pop()                     throw (const char *);
   T & front()                    throw (const char *);
   T   front()              const throw (const char *);
   T back() const throw(const char *);

   T * reallocate(T * oldBuffer, int size) throw (const char *);
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
   if (m_Array != 0)
   {
      m_Front = 0;
      m_Back = 0;
      count = 0;
   }
      else
         throw "Error: No memory to allocate";
}

/*******************************************
 * Queue :: Copy Constructor
 *******************************************/
template <class T>
Queue <T> ::Queue(const Queue & original) throw(const char *) : m_Capacity(original.m_Capacity), m_Front(original.m_Front), m_Back(original.m_Back), count(original.count)
{
   // Get new array for copy
   m_Array = new(nothrow) T[m_Capacity];
   
   if (m_Array != 0)
   {
      for (int pos = m_Front; pos != m_Back; pos = (pos + 1) % m_Capacity)
         m_Array[pos] = original.m_Array[pos];
   }
   else
      throw "Inadequate memory to allocate Queue\n";
}

/*******************************************
 * Queue :: Operator =
 *******************************************/
template <class T>
Queue <T> & Queue <T> ::operator=(const Queue <T> & rightHandSide) throw(const char *)
{
   if (this != &rightHandSide)                // check that not st = st
   {
      //-- Allocate a new array if necessary
      if (m_Capacity != rightHandSide.m_Capacity)
      {
         delete[] m_Array;                    // destroy previous array
         
         m_Capacity = rightHandSide.m_Capacity;  // copy myCapacity
         m_Array = new(nothrow) T[m_Capacity];
         if (m_Array == 0)                    // check if memory available
         {
            throw "Error: No memory to allocate";
         }
      }
      
      m_Front = rightHandSide.m_Front;             // copy m_Front member
      m_Back = rightHandSide.m_Back;               // copy m_Back member
      count = rightHandSide.count;                 // copy counter member
      for (int pos = m_Front; pos != m_Back; pos = (pos + 1) % m_Capacity)  // copy Queue elements
         m_Array[pos] = rightHandSide.m_Array[pos];
         
   }
   return *this;
}

/*******************************************
 * Queue :: Display()
 *******************************************/
template <class T>
void Queue <T> :: display(ostream & out) const
{
   for (int i = m_Front; i != m_Back; i = (i + 1) % m_Capacity)
      out << m_Array[i] << endl;

   out << "Front: " << m_Front << endl;
   out << "Back: " << m_Back << endl;
   out << "Capacity: " << m_Capacity << endl;
}

/*******************************************
 * Queue :: push()
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
      
}

/*******************************************
 * Queue :: back()
 *******************************************/
template <class T>
void Queue <T> :: pop() throw(const char *)
{
   if (!empty())
   {
      count--;
      m_Front = (m_Front + 1) % m_Capacity;
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
*******************************************/
template <class T>
T   Queue <T> :: front() const throw (const char *)
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

template <class T>
T   Queue <T> ::back() const throw (const char *)
{
   if (!empty())
      return m_Array[m_Back];
   else
   {
      throw  "ERROR: attempting to access an item in an empty queue";
      T garbage;
      return garbage;
   }
}

/***************************************************
 * Queues :: REALLOCATE
 * Used for changing the size of oldBuffer
 **************************************************/
template <class T>
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
   {
      if (i == oldSize)
      {
         i = 0;
      }
      newBuffer[j] = oldBuffer[i];
   }
   newBuffer[j] = '\0';
   
   m_Front = 0;
   m_Back = j - 1;

   // Delete old buffer
   delete[] oldBuffer;
   
   return newBuffer;
}

#endif /* Queue_h */


