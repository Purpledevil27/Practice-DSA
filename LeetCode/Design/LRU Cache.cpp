// https://leetcode.com/problems/lru-cache/

/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
*/

#include <bits/stdc++.h>
using namespace std;

// Using Doubly Linked List and hashmap
class LRUCache
{
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> m;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *tempprev = delNode->prev;
        Node *tempnext = delNode->next;
        tempprev->next = tempnext;
        tempnext->prev = tempprev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *place = m[key];
            int res = place->value;
            m.erase(key);
            deleteNode(place);
            addNode(place);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            Node *place = m[key];
            m.erase(key);
            deleteNode(place);
        }
        if (capacity == m.size())
        {
            Node *rem = tail->prev;
            m.erase(rem->key);
            deleteNode(rem);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Using List and Hashmap
class LRUCache
{
    // max capacity of list
    int capacity;
    list<pair<int, int>> caches; // using list we can do insert and delete operation in O(1) time complexity.
    // Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, the list has slow traversal,
    // but once a position has been found, insertion and deletion are quick. Normally, when we say a List, we talk about a doubly linked list.

    // the key value pair include key as the key and value as the pointer pointing to that key in the list. // This will ease our work, since we wont need any iterator to find the key. and hence erase function can be done in O(1) time complexity.
    unordered_map<int, list<pair<int, int>>::iterator> key_pointer;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        // if the key is present in the list
        if (key_pointer.count(key) != 0)
        {
            // get the pointer pointing to the key in the list and dereference it so we get a pair of integers which is key and value.
            auto updated_cache = *key_pointer[key];
            // erase the old cache from the list
            caches.erase(key_pointer[key]);
            // push the new one into the list
            caches.push_front(updated_cache);
            // map the key to the current position
            key_pointer[key] = caches.begin();
            // return value of the key
            return key_pointer[key]->second;
        }
        // key is not present
        return -1;
    }

    void put(int key, int value)
    {
        // if the key is already present
        if (key_pointer.count(key) != 0)
        {
            // update the value of the key
            key_pointer[key]->second = value;
            // get the pointer pointing to the key in the list and dereference it so we get a pair of integers which is key and value.
            auto updated_cache = *key_pointer[key];
            // erase the old cache from the list
            caches.erase(key_pointer[key]);
            // push the new one into the list
            caches.push_front(updated_cache);
            // map the key to the current position
            key_pointer[key] = caches.begin();
            return;
        }
        // if the size is full
        if (caches.size() == capacity)
        {
            // erase the least recently used key from the map
            key_pointer.erase(caches.back().first);
            // then remove it from the list
            caches.pop_back();
        }
        // push the key-value pair into the queue
        caches.push_front({key, value});
        // assign the pointer to the key in the map
        key_pointer[key] = caches.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */