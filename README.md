# DSA-Mini-Project
Family Tree Explorer – DSA Mini Project

Project Title

Family Tree Explorer using Binary Tree (C++)

Team Members

* Yashika Saraf
* Gaurav Patel
* Harshit Dhir

Project Overview

Family Tree Explorer is a mini project based on Data Structures and Algorithms (DSA) using Binary Tree in C++.

This project helps manage and explore family relationships in a tree structure.
Each family member is stored as a node with:

* Member ID
* Name
* Birth Year

The tree allows adding family members and performing different operations like traversal, searching, finding height, counting members, and finding common ancestors.

Data Structure Used

1. Binary Tree

A Binary Tree is used to represent the family hierarchy.

Each node stores:

* ID
* Name
* Birth Year
* Left child
* Right child

Example:

          Grandparent
         /          \
      Parent1      Parent2
      /               \
 Child1                Child4

2. Stack

Used for:

* Inorder Iterative
* Preorder Iterative
* Postorder Iterative

3. Queue

Used for:

* Level Order Traversal

4. Vector

Used for:

* Finding path of family members
* Common ancestor

Features

Add Family Member

* Add new member
* First member becomes root
* Add as left or right child

Display Family Tree

Shows family members level by level.

Example:

Grandparent
Parent1 Parent2
Child1 Child2

Tree Traversals

Inorder Traversal

Left → Root → Right

Preorder Traversal

Root → Left → Right

Postorder Traversal

Left → Right → Root

Both available in:

* Recursive
* Iterative

Search Member

Search any family member using Member ID.

Count Total Members

Displays total number of family members.

Height of Tree

Displays maximum depth of tree.

Example:

Root
 |
Child
 |
Grandchild

Height = 3

Common Ancestor

Finds nearest common ancestor between two members.

Example:

Grandparent
   /     \
 Parent1 Parent2

Common ancestor of Parent1 and Parent2 = Grandparent

Concepts Used

* Binary Tree
* Tree Traversals
* Recursion
* Stack
* Queue
* Searching
* Vectors
* DSA Problem Solving

Programming Language

C++

Libraries used:

<iostream>
<stack>
<queue>
<vector>
<algorithm>

Learning Outcome

From this project we learned:

* Working of Binary Trees
* Recursive and Iterative traversal
* Use of stack and queue
* Tree searching
* Height calculation
* Common ancestor logic
* Real life use of tree structure

Conclusion

Family Tree Explorer is a simple DSA mini project that demonstrates how Binary Trees can be used in a real-life family hierarchy system.
