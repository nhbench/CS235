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
    int linecount =  0,
         minsLeft =  0;
   
   deque<STUDENT> serving;
   
   STUDENT current, next;
   
   do
   {
      
      //cin.ignore();
      cin.clear();
      cout << "<" << linecount++ << "> ";
      cin >> chooser;
      
      picked = string2enum(chooser);         //change string to enum
      
      switch (picked)
      {
         case NONE:                          //Simulator incrementor
         {
            if( minsLeft <= 0)
               if(!serving.empty())
               {
                  current = serving.front();
                  serving.pop_front();
                  minsLeft = current.getMins();
               }
            break;
            
         }
         case OTHERTEXT:                     //Normal requests
         {
            
            string name,time;
            int mins=1;
            
            cin >> name >> time;
            
            next.setCourse(chooser);
            next.setName(name);
            mins = atoi(time.c_str());
            if(mins > 0)
               next.setMins(mins);
            else
               next.setMins(1);
            
            if(minsLeft <= 0)
            {
               if(serving.empty())
               {
                  current = next;
                  minsLeft = mins;
               }
               else
               {
                  current = serving.front();
                  serving.pop_front();
                  minsLeft = current.getMins();
                  serving.push_back(next);
               }
            }
            else
               serving.push_back(next);
            
            break;
         }
         case POUNDPOUND:                    //Emergancy Request
            
            cout << "!! \n";
            
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
    
          if(minsLeft > 0)       //Only Print if we have Minutes left
          {
             
             if(current.getEmgry()) //Current student has an emergancy
             {
                cout << "\tEmergency for ";
             }
             else
             {
                cout << "\tCurrently serving ";
             }
             
             cout << current.getName()  << " for class " << current.getCourse()
               << ". Time left: " << minsLeft << endl;
             
             minsLeft--;
          }

          
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



