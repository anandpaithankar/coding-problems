package queue

import "container/list"

// Queue ... Queue type
type Queue struct {
	q *list.List
}

// New ... Create a new queue
func New() *Queue {
	q := &Queue{list.New()}
	return q
}

// Insert ... Inserts an element
// in a queue
func (q *Queue) Insert(v int) {
	q.q.PushBack(v)
}

// Pop ... Pops the item off the queue
func (q *Queue) Pop() {
	q.q.Remove(q.q.Front())
}

// Front ... Front element of a queue
func (q *Queue) Front() int {
	if q.q.Len() == 0 {
		panic("Empty queue.")
	}
	return q.q.Front().Value.(int)
}
