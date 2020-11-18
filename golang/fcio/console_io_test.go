package fcio

import "testing"

func TestConsoleIO(t *testing.T) {
	input := ConsoleInput()
	if len(input) == 0 {
		t.Errorf("Failed to capture the input")
	}
}

func TestConsoleInputScanner(t *testing.T) {
	input := ConsoleInputScanner()
	if len(input) == 0 {
		t.Errorf("Failed to capture the input")
	}
}
