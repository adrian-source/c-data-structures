import random

random_items = [random.randint(-50,100) for c in range (10)]
print random_items

def bubble(items):
	for i in range(len(items)):
		for j in range(len(items)-1-i):
			print "comparing %d and %d" % (items[j], items[j+1])
			if items[j] > items[j+1]:
				items[j], items[j+1] = items[j+1], items[j]
				print(items)
#bubble(random_items)

def insertion(items):
	for i in range(len(items)):
		j = i
		print i, items
		while j > 0 and items[j] < items[j-1]:
			items[j], items[j-1] = items[j-1], items[j]
			print "> ", items
			j -= 1	
#insertion(random_items)

def merge(items):

	if len(items) > 1:

		mid = len(items)/2;
		left = items[0:mid]
		right = items[mid:]

		merge(left)
		merge(right)

		l, r = 0, 0
		for i in range(len(items)):
			lval = left[l] if l < len(left) else None
			rval = right[r] if r < len(right) else None

			if (lval and rval and lval < rval) or rval is None:
				items[i] = lval
				l += 1
			elif (lval and rval and lval >= rval) or lval is None:
				items[i] = rval
				r += 1
			else:
				raise Exception('Could not merge...')		

#merge(random_items)

def quick(items):

	if len(items) > 1:	
		pivot_index = len(items)/2
		smaller_items = []
		larger_items = []

		for i, val in enumerate(items):
			if i != pivot_index:
				if val < items[pivot_index]:
					smaller_items.append(val)
				else:
					larger_items.append(val)

		quick(smaller_items)
		quick(larger_items)
		items[:] = smaller_items + [items[pivot_index]] + larger_items
		
#quick(random_items)

print random_items
