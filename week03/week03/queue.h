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
   int m_Capacity, m_Top;
   T * m_Array;
   
public:
   //Constructors
   Queue() : m_Capacity(0), m_Top(-1), m_Array(NULL) {}   //Default
   Queue(int numElements) throw(const char *);            //Non-Default
   Queue(const Queue & original) throw(const char *);     //Copy
   
   //Destructur
   ~Queue()    {  delete [] m_Array;  }
   
   //Operator =
   Queue <T> & operator = (const Queue <T> & rightHandSide) throw(const char *);

   
   //Inline functions
   bool  empty()      const    { return (m_Top == -1); }
   int   size()       const    { return (m_Top + 1);   }
   int   capacity()   const    { return m_Capacity;    }
   void  clear()               { m_Top = 0;            }
   
   //Functions
   T top() const throw(const char *);
   
   void display(ostream & out) const;
   
   void push(const T & newValue)  throw (const char *);
   void pop()                     throw (const char *);
   T & front()                    throw (const char *);
   T   front()              const throw (const char *);
   
   T * reallocate(T * oldBuffer, int size) throw (const char *);
};

/*******************************************
 * Queue :: Non-Default Constructor
 *******************************************/
template <class T>
Queue  <T> ::Queue(int numElements) throw(const char *)
{
   assert (numElements  > 0);
   
   m_Capacity = numElements;
   
   m_Array = new(nothrow) T[m_Capacity];
   
   if(m_Array != 0)
      m_Top = -1;
      else
         throw "Error: No memory to allocate";
}

/*******************************************
 * Queue :: Copy Constructor
 *******************************************/
template <class T>
Queue <T> ::Queue(const Queue & original) throw(const char *) : m_Capacity(original.m_Capacity), m_Top(original.m_Top)
{
   // Get new array for copy
   m_Array = new(nothrow) T[m_Capacity];
   
   if (m_Array != 0)
   {
      for (int pos = 0; pos <= m_Top; pos++)
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
      
      m_Top = rightHandSide.m_Top;            // copy myTop member
      for (int pos = 0; pos <= m_Top; pos++)  // copy Queue elements
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
   for (int i = m_Top; i >= 0; i--)
      out << m_Array[i] << endl;
}


/*******************************************
 * Queue :: push()
 *******************************************/
template <class T>
void Queue <T> :: push(const T & newValue) throw(const char *)
{
   m_Top++;
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
   
   // Out of space
   if (m_Top == m_Capacity - 1 && m_Array != NULL)
   {
      m_Capacity *= 2;
      m_Array = reallocate(m_Array, m_Capacity);
   }
   
   m_Array[m_Top] = newValue;
}

/*******************************************
 * Queue :: pop()
 *******************************************/
template <class T>
void Queue <T> :: pop() throw(const char *)
{
   if (!empty())
      m_Top--;
   
   else
      throw "ERROR: Unable to pop from an empty Queue";
}

template <class T>
T & Queue <T> :: front()       throw (const char *)
{
   return this;
}

template <class T>
T   Queue <T> :: front() const throw (const char *)
{
   return this;
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
   int i;
   for (i = 0; i < oldSize; i++)
   {
      newBuffer[i] = oldBuffer[i];
   }
   newBuffer[i] = '\0';
   
   // Delete old buffer
   delete[] oldBuffer;
   
   return newBuffer;
}

#endif /* Queue_h */


