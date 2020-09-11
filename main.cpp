#include "LRUCache.h"

int main(){
    LRUCache lru = LRUCache<std::string, int>(3);
    lru.insertKeyValuePair("b", 2);
    lru.insertKeyValuePair("a", 1);
    lru.insertKeyValuePair("c", 3);
    lru.getMostRecentKey();
    lru.getValueFromKey("a");
    lru.getMostRecentKey();
    lru.insertKeyValuePair("d", 4);
    lru.getValueFromKey("b");
    lru.insertKeyValuePair("a", 5);
    lru.getValueFromKey("a");
}