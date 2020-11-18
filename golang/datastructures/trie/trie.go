package trie

type node struct {
	word     string
	children map[rune]*node
}

// Trie ... Trie type
type Trie struct {
	root *node
}

func newNode() *node {
	return &node{word: string(""), children: make(map[rune]*node)}
}

// New ... Creates a new instance of a Trie
func New() *Trie {
	n := newNode()
	return &Trie{n}
}

// Insert ... Insert a word in a trie
func (t *Trie) Insert(word string) {
	current := t.root
	for _, c := range word {
		if _, ok := current.children[c]; ok {
			current = current.children[c]
		} else {
			current.children[c] = newNode()
			current = current.children[c]
		}
	}

	if len(word) != 0 {
		current.word = word
	}
}

// Contains ... Contains a specific word
func (t *Trie) Contains(word string) bool {
	current := t.root
	for _, w := range word {
		if _, ok := current.children[w]; ok {
			current = current.children[w]
		}
	}

	if len(word) != 0 && current.word == word {
		return true
	}

	return false
}
