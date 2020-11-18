package linkedlist

// node ... Linked List Node
type node struct {
	v    int
	next *node
}

// LinkedList ... LinkedList type
type LinkedList struct {
	head *node
}

func (l *LinkedList) panicOnEmpty() {
	if l.head == nil {
		panic("Empty list")
	}
}

// New ... Creates a new instance of a linked list.
func New() *LinkedList {
	return &LinkedList{}
}

// PushBack ... Push a value to the list
func (l *LinkedList) PushBack(v int) {
	n := node{v, l.head}
	l.head = &n
}

// PushFront ... Push the value to the front of the list
func (l *LinkedList) PushFront(v int) {
	if l.head == nil {
		l.head = &node{v, nil}
		return
	}

	current := &(l.head)
	for ; (*current).next != nil; current = &(*current).next {
	}
	(*current).next = &node{v, nil}
}

// PopBack ... Pops a value from the end.
func (l *LinkedList) PopBack() {
	l.panicOnEmpty()
	l.head = l.head.next
}

// PopFront ... Pops an item from front
func (l *LinkedList) PopFront() {
	l.panicOnEmpty()
	current := &(l.head)
	var prev **node
	for ; (*current).next != nil; prev, current = current, &(*current).next {
	}

	(*prev).next = nil
}

// Front ... Value of a node at front
func (l *LinkedList) Front() int {
	l.panicOnEmpty()
	c := l.head
	for ; c.next != nil; c = c.next {
	}
	return c.v
}

// Back ... Value of a node at back
func (l *LinkedList) Back() int {
	l.panicOnEmpty()
	return l.head.v
}

// Iterate ... Iterates over the list
func (l *LinkedList) Iterate() []int {
	c := l.head
	var values []int
	for ; c != nil; c = c.next {
		values = append(values, c.v)
	}
	return values
}
