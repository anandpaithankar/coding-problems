package trie

import (
	"testing"
)

func TestTrie(t *testing.T) {
	trie := New()
	dict := []string{"peter", "piper", "picked", "peck", "pickled", "peppers"}
	for _, w := range dict {
		trie.Insert(w)
	}

	if trie.Contains("peter") != true {
		t.Errorf("Invalid lookup result, word should be available.")
	}

	if trie.Contains("pe") != false {
		t.Errorf("Invalid lookup result")
	}
}
