package main

import "fmt"

type NumArray struct {
	Sum []int
}

func Constructor(nums []int) NumArray {

	n := len(nums)
	numArray := NumArray{Sum: make([]int, n)}
	sum := 0
	for i, v := range nums {
		sum += v
		numArray.Sum[i] = sum
	}

	return numArray
}

func (this *NumArray) SumRange(left int, right int) int {

	if left == 0 {
		return this.Sum[right]
	}
	return this.Sum[right] - this.Sum[left-1]
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */

func main() {

	nums := []int{-2, 0, 3, -5, 2, -1}
	obj := Constructor(nums)
	fmt.Println(obj.SumRange(0, 2))
	fmt.Println(obj.SumRange(2, 5))
	fmt.Println(obj.SumRange(0, 5))
}
