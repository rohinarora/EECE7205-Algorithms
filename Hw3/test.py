def kthSmallest(A, l, r, k):
    n=r - l + 1
    if (k > 0 and k <= n):
        print (l,r,k)
        n = r - l + 1
        median = []
        i = 0
        while (i < n // 5):
            compute=findMedian(A, l + i * 5, l + i * 5+5)
            print (compute)
            median.append(compute)
            i += 1
        print (i,n)
        if (i * 5 < n):
            compute=findMedian(A, l + i * 5,l + i * 5+n % 5)
            print (compute)
            median.append(compute)
            i += 1
        print (median)
        if i == 1:
            medOfMed = median[i - 1]
        else:
            medOfMed = kthSmallest(median, 0,
								i - 1, i // 2)
        pos = partition(A, l, r, medOfMed)
        if (pos - l == k - 1):
            return A[pos]
        if (pos - l > k - 1):
            return kthSmallest(A, l, pos - 1, k)
        return kthSmallest(A, pos + 1, r,
						k - pos + l - 1)
    else:
        print ("Index larger than size of array")





def swap(A, a, b):
	temp = A[a]
	A[a] = A[b]
	A[b] = temp

# It searches for x in A[l..r],
# and partitions the array around x.
def partition(A, l, r, x):
	for i in range(l, r):
		if A[i] == x:
			swap(A, r, i)
			break

	x = A[r]
	i = l
	for j in range(l, r):
		if (A[j] <= x):
			swap(A, i, j)
			i += 1
	swap(A, i, r)
	return i


def findMedian(A, l, r):
    lis = []
    for i in range(l, r):
        lis.append(A[i])
    lis.sort()
    num=len(lis)
    return [(lis[num//2-1]+lis[num// 2])/2,lis[num // 2]][num%2]


A = [12, 3, 5, 7, 4, 19, 26]
k = 7
print("K'th smallest element is",kthSmallest(A, 0, len(A) - 1, k))

# This code is contributed by Ashutosh450
