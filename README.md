# Stock-Client-Ticker
A lookup algorithm in C++ to parse and analyze large amounts of data using heaps and hash tables.  Given an input file that consists of two blocks, the first block consisting transactions to stocks while the second block consisting of stock data, the algorithm will return trends that include volume and momentum changes.  

The algorithm utilizes heap data structures and chained hash tables in order to minimize runtime.  For allstocks100k-30.data, a text file consisting of over 100,000 lines, the algorithm will parse through the file, create Stock objects in memory and manipulate said objects, analyze trends, and return results in less than 0.3 of a second.  

Written in Spring 2013.
