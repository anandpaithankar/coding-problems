package tree

import "testing"

func TestTree(t *testing.T) {
	tree := New()
	tree.Insert(20)
	tree.Insert(10)
	tree.Insert(30)
	tree.Insert(40)
	tree.Insert(5)
	tree.PreOrder()
	tree.PostOrder()
	tree.InOrder()
}
