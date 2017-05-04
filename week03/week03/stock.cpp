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
   string chooser;      //Menu chooser input
   eMenu picked;        //Enum converted from menu chooser
   Stock stock;         //Stock objects for BUying and selling

   //Two queues one for Buying one for Selling, and one for display (show)
   Queue<Stock> buy, sell, show;
   
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   
      do
      {
         cout << " > > ";                       //output
         cin  >> chooser;                       //first word entered

         picked = string2enum(chooser);         //change string to enum
         
         switch (picked)
         {
            case BUY:
               cin >> stock >> stock.amount;
         
               buy.push(stock);
               break;
               
            case SELL:
               cin >> stock >> stock.amount;

                sell.push(stock);
            
               //Need to manipulate buy queue here
               
               break;
               
            case DISPLAY:
               
               show = buy;
               
               if(buy.size() > 0)
               {
                  cout << "Currently held:\n";
                  for(int i=0; i < buy.size(); i++)
                  {
                     cout << "Bought "<< show.front() << endl;
                     show.pop();
                  }
               }

               break;
               
            case QUIT:
               break;
               
            default:
               cout << "\tInvalid option.\n Please see instructions above for Buy, Sell, Display or Quit\n";
         }
      }
      while (picked != QUIT);
   
   
}


/*******************************************
 * Stock :: Friend streaming out function
 *******************************************/
ostream & operator << (ostream & out, const Stock & rhs)
{
   out << rhs.m_Quantity << " shares at " <<rhs.amount;
   
   return out;
}

/*******************************************
 * Stock :: Friend streaming In function
 * Borrowed heavily from Dollor.cpp streaming in function
 *******************************************/
std::istream & operator >> (std::istream & in, Stock & rhs)
{
   rhs.m_Quantity = 0;  //start clean
   
   if (in.fail())
      return in;
   
   while (isspace(in.peek()))   //remove space
      in.get();
   
   while (isdigit(in.peek()))   // Get digits
      rhs.m_Quantity = rhs.m_Quantity * 10 + (in.get() - '0');
   
   return in;
}

/*******************************************
 * string2enum()
 * Function to change input string to output enum
 * for switch statement
 *******************************************/

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
   
   return MAX_VAL;  //got something else
   
   
}



