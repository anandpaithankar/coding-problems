package binarysearch

// BinarySearch ... Perform binary search on
// sorted array.
func BinarySearch(arr []int, v int) int {
	length := len(arr)
	start, end := 0, length-1
	for start <= end {
		mid := (start + end) / 2
		if v < arr[mid] {
			end = mid - 1
		} else if v > arr[mid] {
			start = mid + 1
		} else {
			return mid
		}
	}
	return len(arr) // similar to Go's SearchInts()
}
