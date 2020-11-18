package bitwise

import (
	"testing"
)

func TestBitSet(t *testing.T) {
	num := 1
	x := SetBit(num, 2)
	if x != 5 {
		t.Error("Value is not equal to 5 ")
	}

	num = 0
	x = SetBit(num, 1)
	if x != 2 {
		t.Error("Mismatched value found ", x)
	}
}

func TestResetBit(t *testing.T) {
	num := 0x01
	x := ResetBit(num, 0)
	if x != 0 {
		t.Error("Mismatched value found ", x)
	}
}

func TestToggleBit(t *testing.T) {
	num := 0x01
	x := ToggleBit(num, 0)
	if x != 0 {
		t.Error("Invalid result received ", x)
	}

	num = 3
	x = ToggleBit(num, 1)
	if x != 1 {
		t.Error("Invalid result received ", x)
	}
}
func TestIsBitSet(t *testing.T) {
	num := 2
	x := IsBitSet(num, 1)
	if x != true {
		t.Error("Invalid result")
	}
}

func TestCountOnes(t *testing.T) {
	num := 0xff
	x := CountOnes(num)
	if x != 8 {
		t.Error("Invalid number of 1s. ", x)
	}
}
