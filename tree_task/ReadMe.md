### Description:

Given a binary tree, find the lowest node whose descendants contain a set of values called 'key_set'. The node values in the tree may be repeated. It is known that a solution always exists.
P. S. this task is similar to https://lnkd.in/dMngXPqs but more difficult

#### Example 1:
```
// code for visualization example 1
echo 'digraph BinaryTree{ " A " -> {" B " " C "}; " B " -> "A "}' | dot -Tpng -Glabel=”example 1" > first_example_task.png
```

**Input**: root = [A, B, C, A], key_set = [A, B]

**Output**: B

**Explanation**: There are two possible solutions: the root node A, and the other one B, but only B is the lowest.

#### Example 2:
```
//code for visualization the example 2
//echo 'digraph BinaryTree{ " A " -> {" B " " C "}; " B " -> {"E " " E "}; " E " -> {" K " " E"}; " C " -> {"C " "K "} }' | dot -Tpng -Glabel="example 2" > second_example_task.png
```

**Input**: root = [A, B, C, E, E, C, K, null, null, K, E], key_set = [A, B]

**Output**: E (with two descendants K and E)

**Explanation**: There are two possible solutions: the root node A, and the other E, but only E is the lowest.