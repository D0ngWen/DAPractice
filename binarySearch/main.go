package main

import (
	"fmt"
	"time"
)

func main() {
	n := 1000000
	arr := make([]int, n)

	i := 0
	for ; i < n; i++ {
		arr[i] = i
	}

	i = 0
	start := time.Now()
	for ; i < n; i++ {
		if BinarySearch(arr, i) != i {
			fmt.Printf("BinarySearch(%d) error\n", i)
			break
		}
	}

	if i == n {
		fmt.Printf("BinarySearch succeed, test %d times, use %v\n", 
					n, time.Since(start))
	}
}
