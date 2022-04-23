import random

LENGTH = 16

def int_to_binary(x: int) -> str:
	return str.zfill(bin(x)[2:], LENGTH)

def binary_to_int(x: str) -> int:
	output = 0
	
	for i in range(LENGTH):
		if x[i] == '1':
			output += 2 ** (LENGTH - i - 1)
			
	return output

def and_operator(x: str, y: str) -> str:
	"""
	0 | 0 | 0\n
	0 | 1 | 0\n
	1 | 0 | 0\n
	1 | 1 | 1\n
	"""
	
	output = ""
	
	for i in range(LENGTH):
		if int(x[i]) and int(y[i]):
			output += '1'
		else:
			output += '0'
	
	return output

def or_operator(x: str, y: str) -> str:
	"""
	0 | 0 | 0\n
	0 | 1 | 1\n
	1 | 0 | 1\n
	1 | 1 | 1\n
	"""
	
	output = ""
	
	for i in range(LENGTH):
		if int(x[i]) or int(y[i]):
			output += '1'
		else:
			output += '0'
			
	return output

def xor_operator(x: str, y: str) -> str:
	"""
	0 | 0 | 0\n
	0 | 1 | 1\n
	1 | 0 | 1\n
	1 | 1 | 0\n
	"""

	output = ""

	for i in range(LENGTH):
		if (int(x[i]) or int(y[i])) and (not (int(x[i]) and int(y[i]))):
			output += '1'
		else:
			output += '0'
	
	return output

def nand_operator(x: str, y: str) -> str:
	"""
	0 | 0 | 1\n
	0 | 1 | 1\n
	1 | 0 | 1\n
	1 | 1 | 0\n
	"""
	
	output = ""
	
	for i in range(LENGTH):
		if not (int(x[i]) and int(y[i])):
			output += '1'
		else:
			output += '0'
	
	return output

def nor_operator(x: str, y: str) -> str:
	"""
	0 | 0 | 1\n
	0 | 1 | 0\n
	1 | 0 | 0\n
	1 | 1 | 0\n
	"""
	
	output = ""
	
	for i in range(LENGTH):
		if not (int(x[i]) or int(y[i])):
			output += '1'
		else:
			output += '0'
			
	return output

def xnor_operator(x: str, y: str) -> str:
	"""
	0 | 0 | 1\n
	0 | 1 | 0\n
	1 | 0 | 0\n
	1 | 1 | 1\n
	"""
	
	output = ""
	
	for i in range(LENGTH):
		if not ((int(x[i]) or int(y[i])) and (not (int(x[i]) and int(y[i])))):
			output += '1'
		else:
			output += '0'
			
	return output
	

a = int_to_binary(random.randrange(1000, 9999))
b = int_to_binary(random.randrange(1000, 9999))
c = xnor_operator(a, b)


print(a, binary_to_int(a))
print(b, binary_to_int(b))
print("----------------")
print(c, binary_to_int(c))
