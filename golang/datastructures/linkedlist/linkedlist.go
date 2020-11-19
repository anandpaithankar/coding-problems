package linkedlist

import "fmt"

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

// PrintList ... Prints the list
func PrintList(l *LinkedList) {
	l.panicOnEmpty()
	c := l.head
	for ; c != nil; c = c.next {
		fmt.Printf(" %d -> ", c.v)
	}
}

// Search ... Searches for a given value
// in the list.
func (l *LinkedList) Search(v int) bool {
	if l.head == nil {
		return false
	}

	for current := l.head; current.next != nil; current = current.next {
		if current.v == v {
			return true
		}
	}
	return false
}

// Reverse ... Returns a reversed linked list.
func (l *LinkedList) Reverse() *LinkedList {
	prev, current := (*node)(nil), l.head
	for current != nil {
		next := current.next
		current.next = prev
		prev = current
		current = next
	}
	return &LinkedList{head: prev}
}

// Mid .. Returns a middle element of a list
func (l *LinkedList) Mid() int {
	l.panicOnEmpty()
	if l.head.next == nil {
		return l.head.v
	}

	current, jump := l.head, l.head.next
	for jump != nil && jump.next != nil {
		jump = jump.next.next
		current = current.next
	}
	return current.v
}
