#ifndef LRUCACHE_H
#define LRUCACHE_H

#include "iostream" 
#include "iterator" 
#include "unordered_map"
#include "string"
#include "doubleLinkedList.h"

template<class T, class S>
class LRUCache{
private:
    std::unordered_map<T, std::pair<S, Node<T>*>> cache;
    DoubleLinkedList<T> lru;
    int size;
public:
    LRUCache(int size); //complexity O(1)
    void insertKeyValuePair(T key, S value); //complexity O(1)
    std::optional<S> getValueFromKey(T key); //complexity O(1)
    T getMostRecentKey(); //complexity O(1)
};

template<class T, class S>
LRUCache<T,S>::LRUCache(int size) {
    this->size = size;
}

template<class T, class S>
void LRUCache<T,S>::insertKeyValuePair(T key, S value) {
    if(cache.find(key)!=cache.end()){
        lru.erase(cache[key].second);
    } else {
        if(cache.size() == size){
            T last = lru.back();
            lru.pop_back();
            cache.erase(last);
        }
    }
    lru.push_front(key);
    cache[key] = std::make_pair(value, lru.begin());
}

template<class T, class S>
std::optional<S> LRUCache<T,S>::getValueFromKey(T key) {
    if(cache.find(key) == cache.end()){
        return std::nullopt;
    }
    lru.erase(cache[key].second);
    lru.push_front(key);
    cache[key].second = lru.begin();
    return cache[key].first;
}

template<class T, class S>
T LRUCache<T,S>::getMostRecentKey() {
    return lru.front();
}

#endif