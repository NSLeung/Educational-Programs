def scoreOfParentheses(str):
    # base case
    if(len(str) == 2 and str[0]== '(' and str[1]==')'):
        return 1
    # second recursive 
    elif(str[0]== '(' and str[1]==')'):
        return 1 + scoreOfParentheses(str[2:])
    # look at outer
    if str[0] == '(' and str[len(str)-1] == ')':
        return 2*scoreOfParentheses(str[1:len(str)-2])

print(scoreOfParentheses("(()(()))"))
