package binarysearch

import (
	"sort"
	"testing"
)

func TestBinarySearch(t *testing.T) {
	arr := []int{1, 2, 3, 4, 5}
	index := BinarySearch(arr, 5)
	if index != sort.SearchInts(arr, 5) {
		t.Errorf("Should have found the valid value")
	}

	index = BinarySearch(arr, 8)
	if index != len(arr) {
		t.Errorf("Should have not found the valid value")
	}
}
