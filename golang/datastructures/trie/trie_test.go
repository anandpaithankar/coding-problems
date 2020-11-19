package trie

import (
	"fmt"
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

func TestSuggestions(t *testing.T) {
	trie := New()
	dict := []string{"peter", "piper", "picked", "peck", "pickled", "peppers"}
	for _, w := range dict {
		trie.Insert(w)
	}

	suggestions := trie.Suggestions("pi")
	for _, w := range suggestions {
		fmt.Printf(" %s ", w)
	}
}

func TestWordDeletion(t *testing.T) {
	trie := New()
	dict := []string{"peter", "piper", "picked", "peck", "pickled", "peppers"}
	for _, w := range dict {
		trie.Insert(w)
	}

	trie.DeleteWord("peter")
	if trie.Contains("peter") == true {
		t.Errorf("Word deletion failed.")
	}

	if trie.Contains("piper") != true {
		t.Errorf("Word deletion should be false")
	}
}
