
#include <unordered_map>
#include <list>
using namespace std;


class LRUCache {
private:
    int capacity;
    list<pair<int, int>> usageOrder;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;
        usageOrder.splice(
            usageOrder.begin(),
            usageOrder,
            it->second
        );

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->second = value;

            usageOrder.splice(
                usageOrder.begin(),
                usageOrder,
                it->second
            );

            return;
        }
        if (cache.size() == capacity) {
            int lruKey = usageOrder.back().first;

            cache.erase(lruKey);
            usageOrder.pop_back();
        }
        usageOrder.push_front({key, value});

        cache[key] = usageOrder.begin();
    }
};
