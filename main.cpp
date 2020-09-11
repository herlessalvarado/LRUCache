#include "LRUCache.h"

int main(){
    LRUCache lru = LRUCache<std::string, int>(3);
    lru.insertKeyValuePair("b", 2);
    lru.insertKeyValuePair("a", 1);
    lru.insertKeyValuePair("c", 3);
    std::cout << lru.getMostRecentKey() << std::endl;
    std::cout << *lru.getValueFromKey("a") << std::endl;
    std::cout << lru.getMostRecentKey() << std::endl;
    lru.insertKeyValuePair("d", 4);
    std::cout << *lru.getValueFromKey("b") << std::endl;
    lru.insertKeyValuePair("a", 5);
    std::cout << *lru.getValueFromKey("a") << std::endl;
}