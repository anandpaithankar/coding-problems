package tree

import (
	"container/list"
	"fmt"
)

type node struct {
	v     int
	left  *node
	right *node
}

// BinaryTree ... Instance of a tree
type BinaryTree struct {
	root *node
}

// New ... Creates a new instance of Binary tree
func New() *BinaryTree {
	return &BinaryTree{}
}

func (n *node) insert(v int) {
	if n == nil {
		return
	} else if v <= n.v {
		if n.left == nil {
			n.left = &node{v, nil, nil}
		} else {
			n.left.insert(v)
		}
	} else {
		if n.right == nil {
			n.right = &node{v, nil, nil}
		} else {
			n.right.insert(v)
		}
	}
}

// Insert ... Insert a value into the tree
func (t *BinaryTree) Insert(v int) {
	if t.root == nil {
		t.root = &node{v, nil, nil}
		return
	}
	t.root.insert(v)
}

// PreOrder ... Print a tree in Pre-Order
func (t *BinaryTree) PreOrder() {
	if t.root == nil {
		fmt.Println("Tree is empty")
		return
	}
	fmt.Printf("Pre order: ")
	preOrder(t.root)
	fmt.Println()
}

// PostOrder ... Post order traversal
func (t *BinaryTree) PostOrder() {
	if t.root == nil {
		fmt.Println("Tree is empty")
		return
	}
	fmt.Printf("Post order: ")
	postOrder(t.root)
	fmt.Println()
}

// InOrder ... In-order traversal
func (t *BinaryTree) InOrder() {
	if t.root == nil {
		fmt.Println("Tree is empty")
		return
	}
	fmt.Printf("In order: ")
	inOrder(t.root)
	fmt.Println()
}

// LevelOrder ... BFS traversal
func (t *BinaryTree) LevelOrder() {
	fmt.Printf("Level Order: ")
	current := t.root
	q := list.New()
	q.PushBack(current)

	for q.Len() != 0 {
		e := q.Front()
		q.Remove(e)
		n := e.Value.(*node)
		fmt.Printf(" %d ", n.v)
		if n.left != nil {
			q.PushBack(n.left)
		}

		if n.right != nil {
			q.PushBack(n.right)
		}
	}
}

func preOrder(n *node) {
	if n == nil {
		return
	}
	fmt.Printf(" %d ", n.v)
	preOrder(n.left)
	preOrder(n.right)
}

func postOrder(n *node) {
	if n == nil {
		return
	}

	postOrder(n.left)
	postOrder(n.right)
	fmt.Printf(" %d ", n.v)
}

func inOrder(n *node) {
	if n == nil {
		return
	}
	inOrder(n.left)
	fmt.Printf(" %d ", n.v)
	inOrder(n.right)
}
