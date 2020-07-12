
# Try to do it in a single pass of the list.
def two_sum(arr, k):
    # Fill this in.

    # first idea: subtract k from every elt in and check for set membership
    # O(1) in python?
    s = set()
    for i in range(len(arr)):
        diff = arr[i] - k
        if i != 0:
            if -arr[i] in s:
                return True
        s.add(diff)
    return False

print (two_sum([4,7,1,-3,2], 5))
# True

print (two_sum([8,7,1,-3,2], 5))
# True