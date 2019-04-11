# How to approach a coding problem in an interview?

## Total allowed time: 20 minutes

## Understanding the problem (Time: < 5 minutes)

* Throughly understand the problem like what is it asking you to do.
* Draw pictures, schematics or doodle if that helps you to vizualize.
  * Sometimes representing inputs in different manner helps formulate the pattern. (e.g. input = "a1b2c3" --> "abbccc")
* Know the input and its type (e.g. string, int, array etc.).
* Know the expected output and its type (e.g. bool, int, array etc).
* Write given inputs and outputs on board in the form of pseudo-method. This will avoid solving wrong problem.
	e.g.
	```cpp
	/*output*/                    /*input*/
	std::string  doStuff(const std::vector<std::string> &arr) {

	}
	```

* **Come up with your own version of different inputs and outputs.** This will help validate and strengthen the understanding of the problem.

## Formulating a Solution (Time: < 4 minutes)

### Edge cases
* Create a section titled *Edge Cases* on whiteboard/coding editor.
* List down all the possible edge cases that you could think of.
* Ask questions on handling certain edge cases and what should be the output of the function.
	
	Example -

	* Invalid inputs or unsatisfied inputs. e.g. Empty string, null pointers, out of bound values or `len(s) < len(t)`.
	* Smaller input sizes (e.g. array with one element, string with two chars etc.) and larger size inputs.
	* Write these input and outputs on whiteboard to test your final solution against.
	* Check data type bounds and overflows.
	* If there are more than possible output (e.g. if string contains more than one matching pattern.)
	* If output cannot be derived using given input. (Ask what should be the output?)
	* Loop counters bound-value check. How the end values affect the input when used?

### Test cases
* In another section on whiteboard, write test inputs and expected outputs.
* Also write the input and outputs from the corner cases where code might fail.
* Eventually, during the online coding session, write these values as various test cases.

```cpp
std::string doStuff(std::string &text, std::string &pattern){

}

int main() {
	// test case 1
	std::string text = "text1";
	std::string pattern = "pattern1";

	std::string output = doStuff(text, pattern);
	assert(output, "pat");

	// test case 2
	text = "text2";
	pattern = "pattern2";
	output = doStuff(text, pattern);
	assert(output, "pat2");
}

```
## Coming up with solution (Time: < 6 minutes)

* When possible breakdown the problem using smaller sized inputs.
* Breakdown the problem in steps like processing the input. Some interviewers like to see such.
* Apply various problem solving patterns e.g. two-pointers pattern on strings.
* Quickly come up with a brute-force solution and its time and space complexities.
* Reason about these complexities if required. Reason how these will change or how you did you compute these.
* Keep another section on whiteboard and note down the points about the brute-force solution. This would be useful, if you cannot come up with the efficient solution, atleast you can code brute-force.
* Think hard and come up with an efficient solution based on what aspects of time and space complexity interviewer likes to improve upon (or trade-off).
* Reason about the final space and time complexities.
* Get interviewer in aggreement before moving ahead.
* Run example inputs, corner cases inputs.
* Write some skeleton program for reference.

## Coding (Time: < 5 minutes)

* During the solution designing, start putting out the variable names aligning to your thoughts process e.g. startIndex, currentLength, minLength etc. This will help you keep in sync with the flow of thoughts and algorithm. **Avoid disrupting train of throughts at any cost.**
* if possible, maintain the steps to code in english using above variables and also use loop names like `for, while` etc.

### Write code using following steps
* Write `main` or caller function. This will help validate the input and output.
* Write main functionality to yield without worrying about the edge cases.
* Introduce a code to handle edge cases.
* White writing the code, keep valid and simple (small sized and workable) input infront of you.
* As you are writing, keep testing your code in mind, by being a debugger for a given input. You can step through it by say it out loud.
* Once finished writing code, before submitting, say I'm going to test it quickly. 
	* Run through edge case and a simple case (golden input) to validate.

* Say its done now!


