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
//#include "deque.h"      // for DEQUE
#include <deque>

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

   string chooser;
   eChoice picked;
    int Linecount =  0,
         minsLeft =  0;
   
   deque<STUDENT> serving;
   
   STUDENT current, next;
   
   do
   {
      
      cin.ignore();
      cin.clear();
      cout << "> ";
      cin >> chooser;
      
      picked = string2enum(chooser);         //change string to enum
      
      switch (picked)
      {
         case NONE:                          //Simulator incrementor
           
            // if( minleft <= 0)
              // then check deque and grab next current.front()
            break;
            
         case OTHERTEXT:                     //Normal requests
            
            /*
             make sure its structured is right  XXXX(class)   and XXXXX(name) 
               and either NN minutes or 1 default
             
             next.course, next.student, and next.min
             
             if we are not serving anyone i=MinLeft <= 0
             current = next
             minLeft = min
             else
             next -> push to back()
             */
            
            break;
            
         case POUNDPOUND:                    //Emergancy Request
         /*   if we are not serving anyone (minleft < 0)
               next.emg = true
               then current = next
               minLeft = next.min
               
               else
                  Next. push to front()  */
            break;
            
         case FINISH:                      //Quit Simulation
            break;
            
      }
      
      if(picked != FINISH)       //Display update if we aren't finished
      {
         /*
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
          */
      }
      
      
   }
   while(picked != FINISH);
   
   
   // end
   cout << "End of simulation\n";
   
}

/*******************************************
 * string2enum()
 * Function to change input string to output enum
 * for switch statement
 *******************************************/

eChoice string2enum(string word )
{
   for (auto & c: word) c = toupper(c);
   
   if(word == "!!")
      return POUNDPOUND;
   
   if(word == "NONE")
      return NONE;
   
   if(word == "FINISHED")
      return FINISH;
   
   return OTHERTEXT;  //got something else
   
}



