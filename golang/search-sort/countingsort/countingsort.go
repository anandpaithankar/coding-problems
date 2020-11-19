package countingsort

const decimals = 10

// CountingSort ... Counting sort
func CountingSort(arr []int) []int {
	count := make([]int, decimals)
	for _, x := range arr {
		count[x]++
	}

	for i := 1; i < decimals; i++ {
		count[i] += count[i-1]
	}

	output := make([]int, len(arr))
	for i := len(arr) - 1; i >= 0; i-- {
		output[count[arr[i]]-1] = arr[i]
		count[arr[i]]--
	}
	return output
}
