#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache
{
    typedef std::unordered_map<int, std::pair<std::list<int>::iterator, int>> Cache;

    Cache _cache;          // <keys, {iterator, values}>
    std::list<int> _queue; // store keys
    size_t _maxCapacity;

    void moveToFront(int key, Cache::iterator &it)
    {
        _queue.erase(it->second.first);
        _queue.push_front(key);
        it->second.first = _queue.begin();
    }

  public:
    LRUCache(int capacity) : _maxCapacity((size_t)capacity)
    {
    }

    int get(int key)
    {
        auto it = _cache.find(key);
        if (it == _cache.end())
        {
            return -1;
        }

        moveToFront(key, it);
        return it->second.second;
    }

    void put(int key, int value)
    {
        auto it = _cache.find(key);
        if (it != _cache.end())
        {
            moveToFront(key, it);
        }
        else
        {
            if (_cache.size() == _maxCapacity)
            {
                _cache.erase(_queue.back());
                _queue.pop_back();
            }

            _queue.push_front(key); // move newer entry to the front.
            _cache[key] = {_queue.begin(), value};
        }
    }
};
int main()
{
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(2, 2);
    std::cout << "\n " << cache.get(2);
    cache.put(1, 1);
    //std::cout << "\n " << cache.get(2);
    cache.put(4, 1);
    std::cout << "\n " << cache.get(2);
}