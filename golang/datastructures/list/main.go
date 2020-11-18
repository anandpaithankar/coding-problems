package main

import (
	"container/list"
	"fmt"
)

func main() {
	l := list.New() // Doubly linked list

	l.PushBack(10)
	l.PushBack(20)
	l.PushBack(30)

	fmt.Println("Length: ", l.Len())
	fmt.Printf("Front: %d, Back: %d\n", l.Front().Value, l.Back().Value)

	// l = l.Init() // clears the list
	// fmt.Printf("Length after init: %d\n", l.Len())

	l2 := list.New()
	l2.PushBack(40)
	l2.PushBack(50)
	l2.PushBack(60)
	l.PushFrontList(l2)

	fmt.Printf("Front: %d, Back: %d\n", l.Front().Value, l.Back().Value)

	e := l.Front()
	l.Remove(e)
	fmt.Printf("After delete, front : %d\n", l.Front().Value)

	// Iterate through the list
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Println(e.Value)
	}
}
