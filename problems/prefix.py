from collections import deque
def evaluate(tokens):
    token=tokens.popleft()
    if token=='+':
            return evaluate(tokens)+evaluate(tokens)
    elif token=='-':
            return evaluate(tokens)-evaluate(tokens)
    elif token=='*':
            return evaluate(tokens)*evaluate(tokens)
    elif token=='/':
            return evaluate(tokens)/evaluate(tokens)
    else:
            return int(token)

ip = "* + 2 3 4"
ip = ip.split(" ")
res = evaluate(deque(ip))
print res
