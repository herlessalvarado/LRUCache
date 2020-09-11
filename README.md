# LRUCache

Implemented a LRUCache class for a Least Recently Used (LRU) cache with the following functions:
  - insertKeyValuePair
  - getValueFromKey
  - getMostRecentKey
  
 These three functions have a complexity time of O(1) for the following reasons:
  - Implemented a double linked list that has O(1) complexity time in all of their methods.
  - Used an unordered_map that has an average of O(1) complexity time in all of their methods.
