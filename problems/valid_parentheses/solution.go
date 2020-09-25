
type stack struct {
	st *list.List
}

func (s *stack) Push(v interface{}) {
	s.st.PushBack(v)
}

func (s *stack) Pop() {
	s.st.Remove(s.st.Back())

}

func (s *stack) Peek() interface{} {
	return s.st.Back().Value
}

func (s *stack) Len() int {
    return s.st.Len()
}


func isValid(s string) bool {
    k := map[byte]byte{
		'{': '}',
		'[': ']',
		'(': ')',
	}

	st := stack{list.New()}

	for i := 0; i < len(s); i++ {
		c := s[i]
		j, ok := k[c]
		if ok {
			st.Push(j)
			continue
		}

		if st.Len() != 0 && st.Peek().(byte) == c {
			st.Pop()
		} else {
			return false
		}
	}
	return st.Len() == 0
}