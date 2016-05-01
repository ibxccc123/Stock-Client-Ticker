#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ChainedHashRMS.h"
#include "StockDP.h"
#include "HeapDP.h"

using namespace std;
int main(int arg, char** argv){
   ChainedHash<Stock> table;
   Heap<Proxy_byVolume> heap_byVolume;
   Heap<Proxy_byPercentUp> heap_byPercentUp;
   Heap<Proxy_byPercentDown> heap_byPercentDown;
   Heap<Proxy_byPercentChange> heap_byPercentChange;
   Heap<Proxy_byMomentum> heap_byMomentum;
   Heap<Proxy_byTrend> heap_byTrend;
   int x = 0;
   string file_name(argv[1]); //Stores the input argument into a string.
   ifstream fin(file_name.c_str());  //Creates an input stream from the input argument string. 
     if(fin.is_open()){
       string insert = "add?";
       string volume = "printTopByVolume?";
       string percent_up = "printTopByPercentUp?";
       string percent_down = "printTopByPercentDown?"; 
       string percent_change = "printTopByPercentChange?";
       string momentum = "printTopByMomentum?";
       string trend_trades = "printTopByTrendTrades?";
       while(!fin.eof()){
         string input;
         fin >> input;
         if(input == insert){
            string ticker;
            fin >> ticker;
            size_t num_shares;
            fin >> num_shares;
            fin.ignore(256, 's');
            double price_stock; 
            fin >> price_stock;
            Stock stock(ticker, num_shares, price_stock);
            Stock* stock_ptr = &*table.insert(stock);
            // "insert" returns an interator.
            // "*" dereferences that iterator and returns a stock.
            // "&" returns the address of that stock.
            heap_byVolume.push(stock_ptr);
            heap_byPercentUp.push(stock_ptr);
            heap_byPercentDown.push(stock_ptr);
            heap_byPercentChange.push(stock_ptr);
            heap_byMomentum.push(stock_ptr);
            heap_byTrend.push(stock_ptr);
         }
         else if(input == volume){
            size_t query_num;
            fin >> query_num;
            cout << "The top " << query_num << " stocks for volume are: " << endl;
            cout << " ------------------------------------------ " << endl << endl;
            heap_byVolume.make_heap();
            vector<Proxy_byVolume> top;
            for (size_t i = 0; i < query_num && heap_byVolume.size() > 0; i++){
               top.push_back(heap_byVolume.pop());
               const Stock& stock = *top[top.size() - 1];
               cout << stock.str() << " " << stock.current() << " " << stock.PercentChange() 
                    << " " << stock.Volume() <<  endl;
            // "top[top.size() - 1]" is a proxy.
            // "top[top.size() - 1]" is a proxy.
            // "*" dereferences that proxy and returns a stock.
            }
            for (size_t i = 0; i < top.size(); i++){
               heap_byVolume.push(top[i]);
            }
            cout << " ------------------------------------------ " << endl << endl;
            }
         else if(input == percent_up){
            size_t query_num;
            fin >> query_num;
            cout << "The top " << query_num << " stocks for percent up are: " << endl;
            cout << " ------------------------------------------ " << endl << endl;
            heap_byPercentUp.make_heap();
            vector<Proxy_byPercentUp> top;
            for (size_t i = 0; i < query_num && heap_byPercentUp.size() > 0; i++){
               top.push_back(heap_byPercentUp.pop());
               const Stock& stock = *top[top.size() - 1];
               cout << stock.str() << " " << stock.current() << " " << stock.PercentChange() 
                    << " " << stock.Volume() <<  endl;
            // "top[top.size() - 1]" is a proxy.
            // "top[top.size() - 1]" is a proxy.
            // "*" dereferences that proxy and returns a stock.
            }
            for (size_t i = 0; i < top.size(); i++){
               heap_byPercentUp.push(top[i]);
            }
            cout << " ------------------------------------------ " << endl << endl;
         }
         else if(input == percent_down){
            size_t query_num;
            fin >> query_num;
            cout << "The top " << query_num << " stocks for percent down are: " << endl;
            cout << " ------------------------------------------ " << endl << endl;
            heap_byPercentDown.make_heap();
            vector<Proxy_byPercentDown> top;
            for (size_t i = 0; i < query_num && heap_byPercentDown.size() > 0; i++){
               top.push_back(heap_byPercentDown.pop());
               const Stock& stock = *top[top.size() - 1];
               cout << stock.str() << " " << stock.current() << " " << stock.PercentChange() 
                    << " " << stock.Volume() <<  endl;
            // "top[top.size() - 1]" is a proxy.
            // "top[top.size() - 1]" is a proxy.
            // "*" dereferences that proxy and returns a stock.
            }
            for (size_t i = 0; i < top.size(); i++){
               heap_byPercentDown.push(top[i]);
            }
            cout << " ------------------------------------------ " << endl << endl;
         }
         else if(input == percent_change){
            size_t query_num;
            fin >> query_num;
            cout << "The top " << query_num << " stocks for percent change are: " << endl;
            cout << " ------------------------------------------ " << endl << endl;
            heap_byPercentChange.make_heap();
            vector<Proxy_byPercentChange> top;
            for (size_t i = 0; i < query_num && heap_byPercentChange.size() > 0; i++){
               top.push_back(heap_byPercentChange.pop());
               const Stock& stock = *top[top.size() - 1];
               cout << stock.str() << " " << stock.current() << " " << stock.PercentChange() 
                    << " " << stock.Volume() <<  endl;
            // "top[top.size() - 1]" is a proxy.
            // "top[top.size() - 1]" is a proxy.
            // "*" dereferences that proxy and returns a stock.
            }
            for (size_t i = 0; i < top.size(); i++){
               heap_byPercentChange.push(top[i]);
            }
            cout << " ------------------------------------------ " << endl << endl;
         }
         else if(input == momentum){
            size_t query_num;
            fin >> query_num;
            cout << "The top " << query_num << " stocks for momentum are: " << endl;
            cout << " ------------------------------------------ " << endl << endl;
            heap_byMomentum.make_heap();
            vector<Proxy_byMomentum> top;
            for (size_t i = 0; i < query_num && heap_byMomentum.size() > 0; i++){
               top.push_back(heap_byMomentum.pop());
               const Stock& stock = *top[top.size() - 1];
               cout << stock.str() << " " << stock.current() << " " << stock.PercentChange() 
                    << " " << stock.Volume() <<  endl;
            // "top[top.size() - 1]" is a proxy.
            // "top[top.size() - 1]" is a proxy.
            // "*" dereferences that proxy and returns a stock.
            }
            for (size_t i = 0; i < top.size(); i++){
               heap_byMomentum.push(top[i]);
            }
            cout << " ------------------------------------------ " << endl << endl;
         }
         else if(input == trend_trades){
            size_t query_num;
            fin >> query_num;
            cout << "The top " << query_num << " stocks for trend trades are: " << endl;
            cout << " ------------------------------------------ " << endl << endl;
            heap_byTrend.make_heap();
            vector<Proxy_byTrend> top;
            for (size_t i = 0; i < query_num && heap_byTrend.size() > 0; i++){
               top.push_back(heap_byTrend.pop());
               const Stock& stock = *top[top.size() - 1];
               cout << stock.str() << " " << stock.current() << " " << stock.PercentChange() 
                    << " " << stock.Volume() <<  endl;
            // "top[top.size() - 1]" is a proxy.
            // "*" dereferences that proxy and returns a stock.
            }
            for (size_t i = 0; i < top.size(); i++){
               heap_byTrend.push(top[i]);
            }
            cout << " ------------------------------------------ " << endl << endl;
         }
         else if(input == "pause?"){
         }
         else{
            size_t num_shares;
            fin >> num_shares;
            fin.ignore(256, 's');
            double price_stock; 
            fin >> price_stock;
            ChainedHash<Stock>::iterator itr = table.find(input);
            if(itr != table.end()){
               Stock* stock_ptr = &*itr;
               // "find" returns an interator.
               // "*" dereferences that iterator and returns a stock.
               // "&" returns the address of that stock.
               stock_ptr->process_trade(num_shares, price_stock);
            }
         }
       }//End of while loop.
     fin.close(); 
     }//End of if statement.
     else{ //If the input filename does not exist as a file.
       cout << "This file cannot be open." << endl; 
       return 0;
     }
     return 0;
}

/*
Rohan Shah
(1A):
a) My hash table stores direct values in the form of Stocks 
   within buckets using chaining.
b) I initialized the hash table to a specified size of 10,000.  
   I allocated a dummy node up-front to the beginning of each bucket.
c) Yes.  
d) The dummy nodes stay dummy nodes throughout the whole program.
e) Yes, the iterator is allowed to step on a dummy node.  The node for
   the end() iterator is a dummy node.
f) I compared the Stock's ticker(via str())with the arguments taken in
   through find().  Our hash table relied on the operator== for the string
   class.  I applied the operator== to the stocks' ticker symbols within the  
   insert() method. 
g) No, I did not add any extra functionality to the inner iterator class within
   the hash table. 
h) Yes, the CLASS INVs helps to make the code more simple. 

Danny Peng
(1B):
a) Proxy objects. 
b) It does not include the hash-table class as it stores data in the 
   form of stock proxies which directly contain the vital information 
   for comparisons in the heap.
c) The heap only acts out the functionality of the heap once the make_heap 
   function is called by the client.  Until then, it is merely a vector where 
   stock proxies are inserted into.
d) The function objects take in arguments of type const Const*.
e) The function objects used public methods of the Stock class in order to 
   access specific data, such as the current value of volume and percent change.
f) The client file calls upon a process_trade function every time a transaction 
   must be processed. This function is provided arguments by the client and then 
   fulfilled by the specified Stock.
g) The Stock class has private fields that are maintained with every transaction(via the
process_trade method) in order to figure out the number of trades in the upward/downward trend.
h) I did not consider creating a hashCode field for each Stock, as the application 
   takes input in from a file, which necessitates the usage of a recomputing of the 
   hash function in order to access the Stock object.  I do not believe that creating 
   a hashCode field is fit for this application. 

Danny Peng
(2):
a) The average running time, over 10 runs, is 2066075 microseconds, equivalent to 0.2066075 second.
b)   


*/
