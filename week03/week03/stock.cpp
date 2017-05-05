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
   int totalStock=0;      //Used to calculate Total stock owned
   Dollars proceeds = 0; // to calculate total proceeds

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
         cin.ignore();
         cin.clear();
         cout << "> ";
         cin >> chooser;                       //first word entered

         picked = string2enum(chooser);         //change string to enum
         
         switch (picked)
         {
            case BUY:
               cin >> stock >> stock.amount;       //get stock input
         
               buy.push(stock);                    //push new stock to Buy queue
               totalStock += stock.getQuantity();  //add to total owned
               
               break;
               
            case SELL:
               cin >> stock >> stock.amount;       //get stock data input

               if(buy.size() > 0)                  //check if we own stock
               {
                  if(stock.getQuantity() > totalStock)    //check if we are selling more than we own
                     stock.setQuantity(totalStock);      //only sell what we own
                  
                 // sell.push(stock);                      //add to Sell queue

                  //Need to manipulate buy queue here
                  
                  Stock buyChk;                          //Temp Stock ojbect
                  buyChk = buy.front();                  //Get first item
                  int sellQnty = stock.getQuantity();
                  
                  while((sellQnty > buyChk.getQuantity()) && (totalStock > 0))
                  {
                     stock.profit = ((stock.amount * buyChk.getQuantity()) -
                                      (buyChk.amount * buyChk.getQuantity()));
                                     
                     stock.setQuantity(buyChk.getQuantity());
                     
                     totalStock -= buyChk.getQuantity();    //deduce total stock owned
                     sellQnty -= buyChk.getQuantity();      //reduce selled quanity
                     
                     sell.push(stock);
                     buy.pop();                            //pop off queue
                     buyChk = buy.front();                  //get next item
                     
                     stock.profit = 0;    //Clean-up at the end
                  }
                  
                  if((sellQnty > 0) && (totalStock > 0))
                  {
                     
                     stock.setQuantity(sellQnty);
                     stock.profit = ((stock.amount * sellQnty) -
                                     (buyChk.amount * sellQnty));
                     sell.push(stock);
                     
                     //Change stock in buy.front
                     
                     buyChk.setQuantity(buyChk.getQuantity() - sellQnty);
                     buy.front() = buyChk;
    
                     stock.profit = 0;    //Clean-up at the end
                  }
                  
                  
               } //end if
            
           
               
               break;
               
            case DISPLAY:
              if(!buy.empty())
               {
                  show = buy;              // copy buy so that we can pop with out changing the orginal
                  cout << "Currently held:\n";
                  for(int i=0; i < buy.size(); i++)
                  {
                     cout << "\tBought "<< show.front() << endl;
                     show.pop();
                  }
               }
               
               if(!sell.empty())
               {
                  show = sell;     // making a copy
                  cout << "Sell History:\n";
                  for(int i=0; i < sell.size(); i++)
                  {
                     cout << "\tSold "<< show.front() << endl;
                     stock = show.front();
                     proceeds += stock.profit;
                     show.pop();
                  }
               }
               
               cout << "Proceeds: " << proceeds << endl;
               proceeds = 0;     //clean up at the end

               break;
               
            case QUIT:
               break;
               
            default:
               cout << "\tInvalid option.\n";
         }
      }
      while (picked != QUIT);
   
   
}


/*******************************************
 * Stock :: Friend streaming out function
 *******************************************/
ostream & operator << (ostream & out, const Stock & rhs)
{
   if(rhs.profit == 0)
      out << rhs.m_Quantity << " shares at " <<rhs.amount;
   else
      out << rhs.m_Quantity << " shares at " <<rhs.amount
      << " for a profit of " << rhs.profit;
   
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



