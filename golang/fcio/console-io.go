package fcio

import (
	"bufio"
	"fmt"
	"os"
)

// ConsoleInput ... Read console input
func ConsoleInput() string {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("--> ")
	text, _ := reader.ReadString('\n')
	fmt.Println("You have entered ", text)
	return text
}

// ConsoleInputScanner ... Scans the input
func ConsoleInputScanner() string {
	scanner := bufio.NewScanner(os.Stdin)
	var text string
	for scanner.Scan() {
		text = scanner.Text()
		fmt.Println(text)
		break
	}
	return text
}
