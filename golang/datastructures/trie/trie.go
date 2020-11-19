package trie

import "container/list"

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

// Suggestions ... Suggest auto-completing words
func (t *Trie) Suggestions(partial string) []string {
	var suggestions []string
	current := t.root
	for _, c := range partial {
		if _, ok := current.children[c]; ok {
			if current.word == partial {
				suggestions = append(suggestions, current.word)
				return suggestions
			}
			current = current.children[c]
		}
	}

	// we have searched for every word in a partial string.
	// Now perform BFS to compute all the suggestions.

	q := list.New() // as a queue
	q.PushBack(current)
	for q.Len() != 0 {
		e := q.Front()
		q.Remove(e)

		t := e.Value.(*node)
		if len(t.word) != 0 {
			suggestions = append(suggestions, t.word)
		}

		for _, v := range t.children {
			q.PushBack(v)
		}
	}
	return suggestions
}

// DeleteWord ... Delete a word from the trie
func (t *Trie) DeleteWord(word string) {
	if len(word) == 0 {
		return
	}

	current, prev := t.root, &(t.root)
	for _, c := range word {
		if _, ok := current.children[c]; ok {
			prev = &current
			current = current.children[c]
		}
	}

	if current != nil {
		current.word = ""
		if len(current.children) == 0 {
			prev, current = nil, nil
		}
	}
	_ = prev
}
