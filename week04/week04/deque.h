/***********************************************************************
* Header:
*    deque.h
* Summary:
*    Create a class encapsulating the notion of a deque
* Author
*    Jeffry Simpson, David Perez 
************************************************************************///

#ifndef deque_h
#define deque_h
#include <iostream>
using namespace std;

#include <cassert>

/************************************************
* Deque
* A class that holds our Deque
***********************************************/
template <class T>
class Deque
{
private:
   int m_Capacity, numPop, numPush;
   T * m_Array;

public:
   //Constructors
   Deque() : m_Capacity(0), numPop(0), numPush(0), m_Array(NULL) {}   //Default
   Deque(int numElements) throw(const char *);            //Non-Default
   Deque(const Deque & original) throw(const char *);     //Copy

                                                          //Destructur
   ~Deque() { delete[] m_Array; }

   //Operator =
   Deque <T> & operator = (const Deque <T> & rightHandSide) throw(const char *);

   //Inline functions
   bool  empty()      const { return (size() == 0); }
   int   size()       const { return numPush - numPop; }
   int   capacity()   const { return m_Capacity; }
   void  clear() { numPop = numPush = 0; }
   int iTail()        const { return (numPush - 1) % m_Capacity; }
   int iHead()        const { return numPop % m_Capacity; }

   //Functions prototypes
   void display(ostream & out) const;

   void push(const T & newValue)  throw (const char *);
   void pop()                     throw (const char *);
   T & front()                    throw (const char *);
   T   front()              const throw (const char *);
   void front(int newValue) const throw (const char *);
   T back() const throw(const char *);

   void reallocate(const int &newSize = 0) throw (const char *);
};

/*******************************************
* Deque :: Non-Default Constructor
*******************************************/
template <class T>
Deque  <T> ::Deque(int numElements) throw(const char *)
{
   assert(numElements  > 0);

   // Allocate array
   m_Capacity = numElements;
   m_Array = new(nothrow) T[m_Capacity];

   // If allocated, set member values to default
   if (m_Array != NULL)
   {
      numPop = 0;
      numPush = 0;
   }
   else
      throw "Error: No memory to allocate";
}

/*******************************************
* Deque :: Copy Constructor
*******************************************/
template <class T>
Deque <T> ::Deque(const Deque & original) throw(const char *) : m_Capacity(original.m_Capacity), numPop(0), numPush(0)
{
   // No memory, lets make some!
   if (m_Capacity == 0 || m_Array == NULL)
   {
      m_Capacity = 2;
   }
   // Allocate memory
   m_Array = new T[m_Capacity];

   int j = 0;
   for (int i = original.numPop; i < original.numPush; i++)
   {
      m_Array[j++] = original.m_Array[i % original.capacity()];
      numPush++;
   }
}

/*******************************************
* Deque :: Operator =
*******************************************/
template <class T>
Deque <T> & Deque <T> ::operator=(const Deque <T> & rightHandSide) throw(const char *)
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
         m_Array[i] = rightHandSide.m_Array[i];
      }
   }
   return *this;
}

/*******************************************
* Deque :: Display()
*          Show array contents
*******************************************/
template <class T>
void Deque <T> ::display(ostream & out) const
{
   // Display, used for debugging
   out << "Head: " << m_Array[iHead()] << endl;
   out << "Tail: " << m_Array[iTail()] << endl;
   out << "Capacity: " << m_Capacity << endl;
}

/*******************************************
* Deque :: push()
*          Add content to end of array
*******************************************/
template <class T>
void Deque <T> ::push(const T & newValue) throw(const char *)
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
         throw "ERROR: Can't allocate memory for the Deque!";
      }
   }

   // Capacity full, double size
   if (size() == capacity())
   {
      m_Capacity *= 2;
      reallocate(m_Capacity);
   }

   // Push to new tail
   numPush++;
   m_Array[iTail()] = newValue;
}

/*******************************************
* Deque :: pop()
*          Remove/advance head by one
*******************************************/
template <class T>
void Deque <T> ::pop() throw(const char *)
{
   if (!empty())
      numPop++;
   else
   {
      throw "ERROR: attempting to pop from an empty deque";
   }
}

/*******************************************
* Deque :: front()
*          Return the head by reference
*******************************************/
template <class T>
T & Deque <T> ::front()       throw (const char *)
{
   if (!empty())
      return m_Array[iHead()];      // *X* return m_Array[m_Front];
   else
   {
      throw "ERROR: attempting to access an item in an empty deque";
      T garbage;
      return garbage;
   }
}

/*******************************************
* Deque :: front()
*          Return the head as copy
*******************************************/
template <class T>
T Deque <T> ::front() const throw (const char *)
{
   if (!empty())
      return m_Array[iHead()];      // *X* return m_Array[m_Front];
   else
   {
      throw "ERROR: attempting to access an item in an empty deque";
      T garbage;
      return garbage;
   }
}

/*******************************************
* Deque :: front()
*          Set the front with new value
*******************************************/
template <class T>
void Deque <T> ::front(int newValue) const throw (const char *)
{
   if (!empty())
      m_Array[iHead()] = newValue;    //*X*   m_Array[m_Front] = newValue;
   else
   {
      throw "ERROR: attempting to access an item in an empty deque";
   }
}

/*******************************************
* Deque :: back()
*          Return the tail
*******************************************/
template <class T>
T Deque <T> ::back() const throw (const char *)
{
   if (!empty())
      return m_Array[iTail()];     // *X* return m_Array[m_Back];
   else
   {
      throw  "ERROR: attempting to access an item in an empty deque";
   }
}

/***************************************************
* Deques :: reallocate()
* Used for changing the size of oldBuffer
**************************************************/
template <class T>
void Deque <T>::reallocate(const int &newSize) throw (const char *)
{
   // double the size
   int oldSize = newSize / 2;

   // Allocate new array
   T* newArray = new T[newSize];

   // Copy with wrap
   for (int i = 0; i < size(); i++)
      newArray[i] = m_Array[(iHead() + i) % oldSize];

   // Cleanup, set new pointer
   delete[] m_Array;
   m_Array = newArray;

   numPush = size();       //reset push
   numPop = 0;             //reset pop

}

#endif /* Deque_h */
