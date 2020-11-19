package lrucache

import (
	"container/list"
)

type cacheNode struct {
	element *list.Element
	value   string
}

// LRUCache ... LRU cache type
type LRUCache struct {
	maxCapacity int
	queue       *list.List
	cache       map[int]*cacheNode
}

// move recently accessed element to the front of the queue.
func (lc *LRUCache) moveToFront(key int, e *cacheNode) {
	lc.queue.MoveToFront(e.element)
	lc.cache[key] = &cacheNode{lc.queue.Front(), e.value}
}

// New ... Creates a new instance of a LRU Cache.
func New(capacity int) *LRUCache {
	return &LRUCache{maxCapacity: capacity, queue: list.New(), cache: make(map[int]*cacheNode)}
}

// Put ... Inserts a key and value into
// the map.
func (lc *LRUCache) Put(key int, val string) {
	if v, ok := lc.cache[key]; ok {
		lc.moveToFront(key, v)
	} else {
		if len(lc.cache) == lc.maxCapacity {
			delete(lc.cache, lc.queue.Back().Value.(int))
			lc.queue.Remove(lc.queue.Back())
		}

		lc.queue.PushFront(key)
		lc.cache[key] = &cacheNode{lc.queue.Front(), val}
	}
}

// Get ... Looks up for a key and returns
// an associated value
func (lc *LRUCache) Get(key int) (string, bool) {
	if node, ok := lc.cache[key]; ok {
		lc.moveToFront(key, node)
		return node.value, true
	}
	return "", false
}
