package main

import "fmt"

func main() {

	var a [4]int
	fmt.Println(a)

	a[3] = 100
	fmt.Println(a)

	// declare
	b := []int{1, 2, 3, 4}
	fmt.Println(b)

	// 2-d array
	var twoD [2][3]int
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			twoD[i][j] = i + j
		}
	}
	fmt.Println(twoD)
}
