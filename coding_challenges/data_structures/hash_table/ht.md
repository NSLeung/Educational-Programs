# Hash Table
Simple Implementation:
1. Hash function: hashes key into an index into array of linked list of (k,v)

- Hash Tables are generally fast assuming few collisions
- worst case: O(N)
- alternative implementation: balanced binary search tree for less space

# Dynamically resizable arrays
- Amortized run time O(1) ? -> because we assume the O(N) doubling doesn't happen all that often