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
   // Utility
   int iAbsoluteFromIRelative(int i) const
   {
      return (i >= 0) ? (i % max) : (max - ((-1 - i) % max) - 1);
   }
   int getIBack()    const { return iAbsoluteFromIRelative(iBack); }
   int getIFront()   const { return iAbsoluteFromIRelative(iFront); }
   void resize(int & newValue) throw(const char *);
   // Member variables
   T * data;
   int max, iFront, iBack;
public:
   //Constructors
   Deque() : data(NULL), max(0), iFront(0), iBack(-1) {}
   Deque(int capacity)           throw (const char *);
   Deque(const Deque<T> & rhs)   throw (const char *);
   ~Deque() { if (!empty()) delete[] data; }

   //Operator =
   Deque <T> & operator = (const Deque <T> & rightHandSide) throw(const char *);
   //Display
   void display(ostream & out) const;
   //Inline functions
   bool empty()   const { return size() == 0; }
   int size()     const { return iBack - iFront + 1; }
   int capacity() const { return max; }
   void clear() { iFront = 0, iBack = -1; }

   // Unique deque functions
   void push_back(const T & t)   throw(const char *);
   void push_front(const T & t)  throw(const char *);
   void pop_back()               throw(const char *);
   void pop_front()              throw(const char *);

   // Front & back Getters
   T & front() throw(const char *);
   T & back()  throw(const char *);
   T front()   const throw(const char *);
   T back()    const throw(const char *);
};

/*******************************************
* Deque :: Non-Default Constructor
*******************************************/
template <class T>
Deque  <T> ::Deque(int capacity) throw(const char *)
{
   // Set custom capacity
   max = capacity;
   data = new T[capacity];

   if (data != NULL)
   {
      iFront = 0;
      iBack = -1;
   }
}

/*******************************************
* Deque :: Copy Constructor
*******************************************/
template <class T>
Deque <T> ::Deque(const Deque & original) throw(const char *)
{
   clear();
   if (data == NULL)
      max = 2;
   max = original.max;
   data = new T[max];
   
   int j = 0;
   for (int i = original.iFront; i <= original.iBack; i++)
   {
      iBack++;
      data[j++] = original.data[iAbsoluteFromIRelative(i)];
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
      clear();
      if (data == NULL)
         max = 2;
      max = rightHandSide.max;
      data = new T[max];

      int j = 0;
      for (int i = rightHandSide.iFront; i <= rightHandSide.iBack; i++)
      {
         data[j++] = rightHandSide.data[iAbsoluteFromIRelative(i)];
         iBack++;
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
   
}

/*******************************************
* Deque :: push_back()
*          Add content to end of array
*******************************************/
template <class T>
void Deque <T>::push_back(const T & t)   throw(const char *)
{
   // NULL CHECK
   if (data == NULL)
   {
      max = 2;
      data = new T[max];
   }

   if (size() == capacity())
      resize(max);

   iBack++;
   data[getIBack()] = t;
}

/*******************************************
* Deque :: push_front()
*          Add content to end of array
*******************************************/
template <class T>
void Deque<T>::push_front(const T & t)   throw(const char *)
{
   // NULL CHECK
   if(data == NULL)
   {
      max = 2;
      data = new T[max];
   }

   if (size() == capacity())
      resize(max);

   iFront--;
   data[getIFront()] = t;

}

/*******************************************
* Deque :: pop_back()
*          Remove/advance head by one
*******************************************/
template <class T>
void Deque<T>::pop_back()               throw(const char *)
{
   if (empty())
   {
      throw "ERROR";
   }
   else
      iBack--;
}

/*******************************************
* Deque :: pop_front()
*          Remove/advance head by one
*******************************************/
template <class T>
void Deque<T>::pop_front()               throw(const char *)
{
   if (empty())
   {
      throw "Error";
   }
   else
      iFront++;
}


/*******************************************
* Deque :: front()
*          Return the head by reference
*******************************************/
template <class T>
T & Deque<T>::front() throw(const char *)
{
   if (!empty())
      return data[getIFront()];
   else
   {
      throw "Nothing";
   }
}

/*******************************************
* Deque :: front()
*          Return the head as copy
*******************************************/
template <class T>
T Deque<T>::front()   const throw(const char *)
{
   if (!empty())
      return data[getIFront()];
   else
   {
      throw "nothing";
   }
}

/*******************************************
* Deque :: back()
*          Return the tail by reference
*******************************************/
template <class T>
T & Deque<T>::back() throw(const char *)
{
   if (!empty())
      return data[getIBack()];
   else
   {
      throw "nothing";
   }
}

/*******************************************
* Deque :: back()
*          Return the tail by copy
*******************************************/
template <class T>
T Deque<T>::back()   const throw(const char *)
{
   if (!empty())
      return data[getIBack()];
   else
   {
      return "nothing";
   }
}

/***************************************************
* Deques :: resize()
* Used for changing the size of oldBuffer
**************************************************/
template <class T>
void Deque<T>::resize(int & newValue) throw (const char *)
{
   const int oldCap = newValue;

   // Old values
   int oldBack = iBack;
   int oldFront = iFront;

   T* oldData = new T[oldCap];

   
   if (getIBack() < getIFront())
   {
      int back = 0;
      int front = getIFront();
      // Copy back
      for (back; back < getIFront(); back++)
      {
         oldData[back] = data[back];
      }
      
      // Copy front
      for (front; front < oldCap; front++)
      {
         oldData[front] = data[front];
        
      }

      // Reset settings and double
      iFront = 0;
      iBack = -1;
      newValue *= 2;
      T* newData = new T[newValue];

      // Copy back
      for (int i = 0; i < back; i++)
      {
         iBack++;
         newData[getIBack()] = oldData[i];
      }

      // Copy front
      for (int i = front; i >= back; i--)
      {
         iFront--;
         newData[getIFront() + 1] = oldData[i];
      }

      // Needs this for some reason...
      iFront++;

      delete[] data;
      delete[] oldData;
      data = newData;
   }
   else
   {
      int back = getIBack();
      int front = 0;
      
      // Copy back
      for (int i = 0; i <= getIBack(); i++)
         oldData[i] = data[i];

      // Reset settings
      iFront = 0;
      iBack = -1;
      newValue *= 2;
      T* newData = new T[newValue];

      // copy
      for (int i = 0; i <= back; i++)
      {
         iBack++;
         newData[getIBack()] = oldData[i];
      }

      delete[] data;
      delete[] oldData;
      data = newData;
   }
   
}


#endif /* Deque_h */
