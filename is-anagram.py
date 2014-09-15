
def isAnagram(str1):

	if not str1:
		return False

	str1 = str1.lower()
	str2 = ""
	for i, c in enumerate(str1):
		if c.isalpha():
			str2 += c

	l, r = 0, len(str2)-1
	while r >= 0:
		if not str2[l] == str2[r]:
			return False
		else:
			l += 1
			r -= 1

	return True

print isAnagram("asd a sd")
print isAnagram("Madam, I'm Adam!!")
print isAnagram("Ma'am")
print isAnagram("allllllllll")
