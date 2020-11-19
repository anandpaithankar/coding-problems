package lrucache

import (
	"testing"
)

func TestLRUCache(t *testing.T) {
	cache := New(4)
	cache.Put(0, "venus")
	cache.Put(1, "mercury")
	cache.Put(2, "earth")
	cache.Put(3, "mars")

	if m, ok := cache.Get(0); !ok {
		if m != "venus" {
			t.Errorf("Should have been \"venus\"")
		}
	}

	cache.Put(4, "jupiter")
	if m, ok := cache.Get(4); !ok {
		if m != "jupiter" {
			t.Errorf("Should have been \"jupiter\"")
		}
	}

	if m, ok := cache.Get(1); ok {
		t.Errorf("Was not expecting key 1 to be present. %s", m)
	}
}
