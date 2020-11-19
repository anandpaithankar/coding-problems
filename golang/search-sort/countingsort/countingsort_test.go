package countingsort

import (
	"sort"
	"testing"
)

func TestCountingSort(t *testing.T) {
	arr := []int{5, 6, 2, 0, 8, 6, 1, 2}
	actual := CountingSort(arr)
	sort.Ints(arr)
	if len(actual) != len(arr) {
		t.Errorf("Different lengths of expected vs actual")
	}

	for i, v := range arr {
		if v != actual[i] {
			t.Errorf("Invalid result")
		}
	}
}
