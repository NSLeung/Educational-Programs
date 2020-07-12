
def recur(matrix, word):
    pass

def word_search(matrix, word):
    # Fill this in.
    # O(n^2) brute force solution
    # found = False
    word_idx=0
    print(word_idx)
    print(word[word_idx])
    i=0
    while(i < len(matrix)):
        j=0
        while(j < len(matrix[0])):
            print(matrix[i][j])
            if(word[word_idx]==matrix[i][j]):
                print("asdf")
                # check both directions
                # left to right
                k=j
                while(k < len(matrix[0])and word_idx < len(word)):
                    if(word[word_idx]==matrix[i][k]):
                        print("matched " + matrix[i][k])
                        word_idx+=1
                        k+=1
                    else:
                        break
                if word_idx == len(word):
                    return True
                k=i 
                word_idx=0
                while(k < len(matrix) and word_idx < len(word)):
                    if(word[word_idx]==matrix[k][j]):
                        print("matched " + matrix[k][j])
                        word_idx+=1
                        k+=1
                    else:                        
                        break
                print(word_idx)
                if word_idx == len(word):
                    return True
            word_idx=0
            # print("What's up")
            j+=1
        i+=1
    return False

    # maybe do recursive
def exist(board, word):
    if not board:
        return False
    for i in range(len(board)):
        for j in range(len(board[0])):
            if dfs(board, i, j, word):
                return True
    return False

# check whether can find word, start at (i,j) position    
def dfs(board, i, j, word):
    if len(word) == 0: # all the characters are checked
        return True
    if i<0 or i>=len(board) or j<0 or j>=len(board[0]) or word[0]!=board[i][j]:
        return False
    tmp = board[i][j]  # first character is found, check the remaining part
    board[i][j] = "#"  # avoid visit agian 
    # check whether can find "word" along one direction
    res = dfs(board, i+1, j, word[1:]) or dfs(board, i-1, j, word[1:]) \
    or dfs(board, i, j+1, word[1:]) or dfs(board, i, j-1, word[1:])
    board[i][j] = tmp
    return res
  
matrix = [
  ['F', 'A', 'C', 'I'],
  ['O', 'B', 'Q', 'P'],
  ['A', 'N', 'O', 'B'],
  ['M', 'A', 'S', 'S']]
# print (word_search(matrix, 'QS'))
print (exist(matrix, 'BS'))
# True