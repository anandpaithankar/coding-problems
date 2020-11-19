package main

import "fmt"

func main() {

	// make will allocate memory
	distance := make(map[string]float32)
	distance["mars"] = 50.01
	distance["earth"] = 0
	distance["venus"] = 125
	fmt.Println(distance)

	// delete a key
	delete(distance, "venus")
	fmt.Println(distance)
	if _, ok := distance["venus"]; !ok {
		fmt.Println("Venus is not present")
	}

	planets := map[string]int{"venus": 1, "mercury": 2, "earth": 3, "mars": 4}
	fmt.Println(planets)
	fmt.Println("Size: ", len(planets))

	// iterating over a map
	for k, v := range planets {
		fmt.Printf("%s -> %d \n", k, v)
	}

	for k := range planets {
		fmt.Println("key : ", k)
	}

	// range over a string in an array style
	// with an index and value at the given
	// index.
	for i, c := range "planets" {
		fmt.Printf("%d -> %c \n", i, c)
	}

}
