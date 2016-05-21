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

