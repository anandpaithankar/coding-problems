package bitwise

import (
	"fmt"
	"math/bits"
	"unsafe"
)

// SetBit ... Sets a bit at a given position.
func SetBit(num, pos int) int {
	mask := (0x01 << pos)
	num |= mask
	return num
}

// ResetBit ... Sets the set bit to 0.
func ResetBit(num, pos int) int {
	num &= ^(1 << pos) // ^(0101) is a bitwise NOT
	return num
}

// IsBitSet ... Bit set
func IsBitSet(num, pos int) bool {
	x := (num & (1 << pos))
	fmt.Println(x)
	if x != 0 {
		return true
	}
	return false
}

// ToggleBit ... Toggles a bit at a specific position
func ToggleBit(num, pos int) int {
	num ^= 1 << pos // XOR
	return num
}

// CountOnes ... Count number of 1s.
func CountOnes(num int) int {
	ones := 0
	fmt.Println("size ", unsafe.Sizeof(num)*8)
	for i := uintptr(0); i < unsafe.Sizeof(num)*8; i++ {
		if (num & (0x01 << i)) == 1 {
			ones++
		}
	}
	return ones
}

// CountOnesLib ... Count number of 1s.
func CountOnesLib(num uint) int {
	return bits.OnesCount(num)
}
