/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

//#include "deque.h"     // for DEQUE

//Temp items here
#include <deque>
#include <iostream>
using namespace std;
#include <cassert>
//To here


// the interactive nowServing program
void nowServing();


class STUDENT
{
private:
   string m_Course;
   string m_Name;
   int m_Mins;
   bool m_Emrgcy;
   
public:
   STUDENT() : m_Course(""), m_Name(""), m_Mins(0), m_Emrgcy(false) {}
   
   
   string getCourse() { return m_Course;  }
   string getName()   { return m_Name;    }
   int getMins()      { return m_Mins;    }
   bool getEmgry()    { return m_Emrgcy;  }
   
   void setCourse(string course) { m_Course = course;}
   void setName(string student)  { m_Name = student;}
   void setMins(int minutes)     { m_Mins = minutes; }
   void setEmrgcy(bool value)    { m_Emrgcy = value; }
   
   
};

enum eChoice
{
   POUNDPOUND,
   NONE,
   FINISH,
   OTHERTEXT,
   MAX_VAL
};

//Menu Function definiton
eChoice string2enum(string word );

#endif // NOW_SERVING_H

