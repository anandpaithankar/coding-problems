package fcio

import (
	"bufio"
	"io/ioutil"
	"os"
)

// ReadFile ... Reads the entire file into
// memory.
func ReadFile() string {
	// hold the data as a byte array.
	data, err := ioutil.ReadFile("hello.txt")
	if err != nil {
		panic(err)
	}

	return string(data)
}

// BufferedReadFile ... Buffered read
// good for a long file or streams
func BufferedReadFile() string {
	f, err := os.Open("hello.txt")
	if err != nil {
		panic("Error opening the file.")
	}
	defer f.Close()

	reader := bufio.NewReader(f)
	info, _ := f.Stat()
	b := make([]byte, info.Size())
	var e error
	b, e = reader.ReadBytes('d')
	if e != nil {
		return ""
	}

	reader.Reset(f)
	b, _, _ = reader.ReadLine()
	return string(b)
}

// WriteFile ... Write the file
func WriteFile() error {
	buffer := []byte("hello, there\n")
	err := ioutil.WriteFile("sample.txt", buffer, 0644)
	if err != nil {
		panic("Error writing the file.")
	}
	return err
}

// DeleteFile ... Deletes the file
func DeleteFile() error {
	return os.Remove("sample.txt")
}
