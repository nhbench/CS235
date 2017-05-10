/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here

   /*
    int Linecount = 0, minLeft;
    
    enum choices
    !!
    none
    finished
    Max_out
    
    class  Lab
    string course
    string name
    int min
    bool emg
    
    deque <Lab> Peoples
    Lab current, next
    
    do(
    
    switch
    {
    
    case: !!
    if we are not serving anyone (minleft < 0)
    next.emg = true
    then current = next
    minLeft = next.min
    
    else
    Next. push to front()
    
    
    case: none
    if( minleft <= 0)
    then check deque and grab next current.front()
    
    case: Finish
    quit(0)
    
    default: case
    make its structured right  XXXX(class)   and XXXXX(name) and either NN minutes or 1 default
    next.course, student, and min
    
    if we are not serving anyone i=MinLeft <= 0
    current = next
    minLeft = min
    else
    next -> push to back()
    
    
    }
    
    
    
    //display
    if minLeft > 0
    {
    if current.emg == True
    emergancy << current.student
    else 
    current.course << current.student << "time left: << i
    }
    else // min == 0	
    //do nothing
    
    cout << <linecount++ >
    if(minLeft > 0
    minLeft--
    
    
    while( xxx != "finished)
    
    
    */
   
   // end
   cout << "End of simulation\n";
   
}


