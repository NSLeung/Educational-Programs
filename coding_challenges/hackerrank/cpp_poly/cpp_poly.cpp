#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
/* code goes here */
class LRUCache : public Cache {
    private:
    map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer (keeps track of usage)
   Node* head; // double linked list head pointer
   public:
   LRUCache(int c){
       cp = c;
       
       /* initialize memory properly in heap */
       head = new Node(-1, -1);
    //    tail = new Node(-1, -1);
       Node* curr;
       curr = head;
       if(cp == 1){
           tail = head;
           head->next = head;
           head->prev = head;
       }
       else{
           for(int i = 0; i < cp-1; i++){
            //    cout << "making node i " << i << endl;
                curr->next = new Node(curr, NULL, -1, -1);
                curr = curr->next;
            }
        /* last node */
        tail = curr;
       } 
    //    print_list();
       
   }
   void print_list(){
       Node* curr = head;
       while(curr->next!=NULL){
           cout << "[key: " << curr->key << ", val: " << curr->value << "] -> " << endl;
           curr = curr->next;
       }
        cout << "[key: " << curr->key << ", val: " << curr->value << "] -> " << endl;

   }
   void set(int key, int val) {
       std::map<int,Node*>::iterator it;
       /* search map cache to see if it exists */
       it = mp.find(key);
       Node* oldHead;
       Node* tailPrev;
       Node* newNode;
        // cout << "beginning of set [key: " << key << ", val: " << val << "]" << endl;
        // print_list();
       /* if not found */
       if(it == mp.end()){
           /* update evicted key */
        //    cout << "erasing key: " << tail->key << endl;
           mp.erase(tail->key);
           /* update LRU doubly linked list */            
            oldHead = head;
            tailPrev = tail->prev;
            newNode = new Node(NULL, oldHead, key, val);
            delete tail;
            oldHead->prev = newNode;
            tailPrev->next = NULL;
            head = newNode;
            tail = tailPrev;
            // cout << "tail now at [key: " << tail->key << ", val: " << tail->value << "] -> " << endl;

            /* update map */
            mp[key] = head;
            

       }
       else{
           /* if we can find it, then we have to move the found elt in the list to the head */
           Node* elt = it->second;
           oldHead = head;
           tailPrev = tail->prev;
           head = elt;
           tailPrev->next = NULL;
           elt->prev = NULL;
           elt->next = oldHead;
           oldHead->prev = elt;
           tail = tailPrev;

       }
    //    cout << "end of set " << endl;
    //    print_list();
   }
   int get(int key){
       std::map<int,Node*>::iterator it;
       /* search map cache to see if it exists */
       it = mp.find(key);
       /* if found */
       if(it != mp.end()){
           Node* elt = it->second;
           return elt->value;
       }
       else{
           return -1;
       }
   }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


/* alternative soln using STL 
class LRUCache {
    int cp;
    map<int, list<pair<int, int> >::iterator> mp;
    list<pair<int, int> > lru;
public:
    LRUCache(int capacity) : cp(capacity){}
    void set(int key, int val) {
        if(mp.find(key) != mp.end()) {
            mp[key]->key = key;
            mp[key]->val = val;
        }
        else {
            lru.push_front({key, val});
            mp[key] = lru.begin();
            if(lru.size() > cp) {
                mp.erase(lru.back().key);
                lru.pop_back();
            }
        }
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            lru.push_front(*mp[key]);
            lru.erase(mp[key]);
            mp[key] = lru.begin();
            return mp[key]->val;
        }
        else
            return -1;
    }
};
*/