package main

func BinarySearch(arr []int, t int) int {
	l := 0
	r := len(arr)

	for l < r {
		mid := (l + r) / 2
		if arr[mid] == t {
			return mid
		} else if arr[mid] > t {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return -1
}
