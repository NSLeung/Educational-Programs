# 1.1
*isUnique*
Input: string
output: boolean if all unique chars
Extra req's: no extra data structure
BCR: O(n) go through all the chars
Bad algorithm: make another helper function take in a char that exists in the string and compare

isUniqueHelper(str, char):
    if str.contains(char):
        return False
isUnique(str):
    idx = 1
    bool flag = false
    while str!=null:

        str = str.substr(idx)
        flag &= isUniqueHelper(str, idx-1)
    return flag

Hint #117 - bit vector is kind of a cheese data structure

# 1.4
*Palindrome Permutation*
Input: string
output: boolean if it has permutations 