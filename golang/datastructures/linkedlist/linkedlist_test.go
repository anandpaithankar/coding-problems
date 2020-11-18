package linkedlist

import "testing"

func TestLinkedList(t *testing.T) {
	l := New()
	l.PushBack(1)
	l.PushBack(2)
	l.PushBack(3)
	l.PushBack(4)
	l.PushFront(6)

	if l.Front() != 6 {
		t.Errorf("Invalid value received for Front()")
	}

	if l.Back() != 4 {
		t.Errorf("Invalid value received for Back()")
	}

	values := l.Iterate()
	expected := []int{4, 3, 2, 1, 6}
	if len(values) != len(expected) {
		t.Errorf("Invalid values received")
	}

	for i := 0; i < len(values); i++ {
		if values[i] != expected[i] {
			t.Errorf("Unexpected value received.")
		}
	}
}

func TestPushFront(t *testing.T) {
	l := New()
	l.PushBack(3)
	l.PushFront(2)

	if l.Front() != 2 {
		t.Errorf("Invalid value received for Front()")
	}

	if l.Back() != 3 {
		t.Errorf("Invalid value received for Back()")
	}

	l.PushFront(4)
	l.PopBack()

	if l.Front() != 4 {
		t.Errorf("Invalid value received for Front()")
	}

	if l.Back() != 2 {
		t.Errorf("Invalid value received for Back()")
	}

	l.PopFront()
	if l.Front() != 2 {
		t.Errorf("Invalid value received for Front()")
	}
}

func TestEmptyListOperations(t *testing.T) {
	defer func() {
		if r := recover(); r == nil {
			t.Errorf("Method did not panic")
		}
	}()

	l := New()
	l.Back()
	l.Front()
	l.PopBack()
	l.PopFront()
}
