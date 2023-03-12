import random

print("Generate expr expressions for NEMU EXPR")
print("Example:")
print("p 1 + (2 + (3 + 4) + (5 + 6 + (7 * 8 * 9) + 10) * 11 + 12)")
NEMU_EXPR_TOKEN_MAX_NUMBER = 32

HAVE_PLUS = True
HAVE_MINUS = True
HAVE_MULTIPLY = True
HAVE_DEVIDE = True

HAVE_AND = False
HAVE_OR = False
HAVE_EQ = False
HAVE_NEQ = False