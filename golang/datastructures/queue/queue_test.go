package queue

import (
	"testing"
)

func TestQueue(t *testing.T) {
	q := New()

	q.Insert(10)
	q.Insert(20)
	if q.Front() != 10 {
		t.Error("Invalid value at the front of queue")
	}

	q.Pop()
	if q.Front() != 20 {
		t.Error("Invalid value at the front of queue")
	}

	q.Insert(30)
	if q.Front() != 20 {
		t.Error("Invalid value at the front of queue")
	}
}

func TestEmptyQueue(t *testing.T) {
	defer func() {
		if r := recover(); r == nil {
			t.Errorf("The code did not panic.")
		}
	}()

	q := New()
	q.Front()
}
