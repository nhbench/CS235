/***********************************************************************
 * Header:
 *    stack.h
 * Summary:
 *    Create a class encapsulating the notion of a stack
 * Author
 *    David Donovan, David Perez Jeffry Simpson
 ************************************************************************///


#ifndef stack_h
#define stack_h
using namespace std;

#include <cassert>


/************************************************
 * Stack
 * A class that holds our Stack
 ***********************************************/

template <class T>
class Stack
{
private:
   int m_Capacity,
       m_Top;
   T * m_Array;
   
public:
   //Constructors
   Stack() : m_Capacity(0), m_Top(-1), m_Array(NULL) {}   //Default
   Stack(int numElements) throw(const char *);            //Non-Default
   Stack(const Stack & original);                         //Copy
   
   //Destructur
   ~Stack()    {  delete [] m_Array;  }
   
   //Operator =
   Stack <T> & operator=(const Stack <T> & rightHandSide) throw(const char *);
   
   //Inline functions
   bool  empty()      const    { return (m_Top == -1); }
   int   size()       const    { return (m_Top);       }
   int   capacity()   const    { return (m_Capacity);  }
   void  clear()               { m_Top = 0;           }
   
   //Functions
   T top() const;
   
   void display(ostream & out) const;
   
   void push(const T & newValue) throw (const char *);;
   
   void pop();
   
   
};


/*******************************************
 * Stack :: Non-Default Constructor
 *******************************************/
template <class T>
Stack  <T> ::Stack(int numElements) throw(const char *)
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
 * Stack :: Copy Constructor
 *******************************************/
 
template <class T>
Stack <T> ::Stack(const Stack & original)  : m_Capacity(original.m_Capacity), m_Top(original.m_Top)
{
   
   // Get new array for copy
   m_Array = new(nothrow) T[m_Capacity];
   
   if(m_Array != 0)
   {
      for(int pos = 0; pos <= m_Top; pos++)
         m_Array[pos] = original.m_Array[pos];
   }
   
}


/*******************************************
 * Stack :: Operator =
 *******************************************/

template <class T>
Stack <T> & Stack <T> ::operator=(const Stack <T> & rightHandSide) throw(const char *)
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
      for (int pos = 0; pos <= m_Top; pos++)  // copy stack elements
         m_Array[pos] = rightHandSide.m_Array[pos];
      
   }
   return *this;
}

/*******************************************
 * Stack :: Display()
 *******************************************/

template <class T>
void Stack <T> :: display(ostream & out) const
{
   for (int i = m_Top; i >= 0; i--)
      out << m_Array[i] << endl;
}

/*******************************************
 * Stack :: Top()
 *******************************************/

template <class T>
T Stack <T> ::top() const
{
   if ( !empty() )
      return (m_Array[m_Top]);
   else
   {
      cerr << "*** Stack is empty -- returning garbage value ***\n";
      T garbage;
      return garbage;
   }
}

/*******************************************
 * Stack :: push()
 *******************************************/
template <class T>
void Stack <T> :: push(const T & newValue) throw (const char *)
{

   if(!capacity())
      m_Array = new T[++m_Capacity];
   
   if (size() >= capacity()-1)
   {
      try
      {
      
         T * temp_Array = new T[++m_Capacity];
         
         for (int pos = 0; pos <= m_Top; pos++)  // copy stack elements
            temp_Array[pos] = m_Array[pos];
            
          delete[] m_Array;
         m_Array = new T[m_Capacity];
         
         for (int pos = 0; pos <= m_Top; pos++)  // copy stack elements
            m_Array[pos] = temp_Array[pos];
            
         delete [] temp_Array;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate buffer";
      }
      
   }
   
   m_Array[++m_Top] = newValue;   //Add new Value to top of array
   
   
}


/*******************************************
 * Stack :: pop()
 *******************************************/
template <class T>
void Stack <T> :: pop()
{
   
   m_Top--;
   
}


#endif /* stack_h */
