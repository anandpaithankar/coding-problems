package fcio

import (
	"testing"
)

func TestReadFile(t *testing.T) {
	data := ReadFile()
	if len(data) == 0 {
		t.Errorf("Error reading the file.")
	}

	if "Hello, World" != data {
		t.Errorf("Corrupted file or read.")
	}
}

func TestBufferedReadFile(t *testing.T) {
	data := BufferedReadFile()
	if len(data) == 0 {
		t.Errorf("Error reading the file.")
	}

	if "Hello, World" != data {
		t.Errorf("Corrupted file or read.")
	}
}

func TestWriteFile(t *testing.T) {
	if WriteFile() != nil {
		t.Errorf("Unable to open and write file.")
	}
	DeleteFile()
}
