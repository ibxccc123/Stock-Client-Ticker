#include <vector>

using std::vector;

template<typename T>
class Heap{
public:
   vector<T> item;
   Heap() : item(vector<T>(1)) {}
  
   int size() const{
      return item.size() - 1;
   }
 
//ENS: Items inserted are sorted after the make_heap method is called. 
   void fix_down(int index){ //The fix_down method makes an item "sink" down to where it belongs.
      T temp = item[index];
      while(2*index <= size()){
         int child = 2*index;
         if(child < size() && item[child+1] > item[child])
            child++;     
        if(temp >= item[child])
            break; 
        item[index] = item[child];
        index = child;
        }
        item[index] = temp;
     }
  
   void make_heap(){
      for(int index = size()/2; index >= 1; index--){
         fix_down(index);
       }
    }

    T pop(){
        T temp = item[1];
         item[1] = item[size()];
         item.pop_back();
         if(size() > 0){
             fix_down(1);
          }
         return temp;
     }

    void push(T new_item){
        item.push_back(new_item);
   //This method does not apply fix_up, given the max-only heaps of this project.
     }
};
