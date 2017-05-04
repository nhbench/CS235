/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;



/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   // interact
   string chooser, price;
   int quantity;
   eMenu picked;
   
      do
      {
         cout << " >> ";
         cin  >> chooser;

         picked = string2enum(chooser);
         
         switch (picked)
         {
            case BUY:
               cin >> quantity >> price;
               
               cout << "You Picked: " << chooser << " of " << quantity << " shares for "<< price << endl;
               //David D Buy Function goes here
               
               break;
            case SELL:
               cin >> quantity >> price;

               cout << "You Picked: " << chooser << " of " << quantity << " shares for "<< price << endl;
               //Jeffry Sell Function
               break;
            case DISPLAY:
               cout << "Got to display\n";
               
               //David D Display function

               break;
            case QUIT:
               break;
            default:
               cout << "\tInvalid option.\n Please see instructions above for Buy, Sell, and Display or Quit\n";
         }
      }
      while (picked != QUIT);
   
   
}

eMenu string2enum(string word )
{
   for (auto & c: word) c = toupper(c);

   if(word == "BUY")
      return BUY;
   
   if(word == "SELL")
      return SELL;
   
   if(word == "DISPLAY")
      return DISPLAY;
   
   if(word == "QUIT")
      return QUIT;
   
   
   return MAX_VAL;  //got somethign else
   
   
}

