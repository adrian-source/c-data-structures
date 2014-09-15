
def addBinary(num1, num2):
	
	if not num1 or not num2:
		return;

	print num1, "+", num2, "="
	num1 = num1[::-1]
	num2 = num2[::-1]

	longer_length = max(len(num1), len(num2))

	solution = ""
	carry = 0

	for i in range(longer_length):
	
		val1 = num1[i] if i < len(num1) else 0 
		val2 = num2[i] if i < len(num2) else 0
		#print "> ", val1, val2, carry

		if val1 == "1" and val2 == "1":
			add = 0 + carry
			carry = 1
		elif val1 == "1" or val2 == "1":
			add = 1  if carry == 0 else 0
		else:
			add = 0 + carry
			carry = 0

		solution = str(add) + solution
		
	if carry == 1:
		return str(carry)+solution
	else:
		return solution

print addBinary("1", "101")
print addBinary("101", "1")
print addBinary("0", "0")
print addBinary("1", "0")
print addBinary("1", "1")
print addBinary("11111", "001")
