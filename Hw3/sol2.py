import numpy as np
class Solution():
    def randomized_partition(self,A,l,r):
        '''
        Find random pivot, and swap with it with A[l]. A[l] stores the pivot location during the subroutine
        '''
        random_ind=np.random.randint(l, high=r+1, size=1)[0]
        A[random_ind],A[l]=A[l],A[random_ind]
        p = A[l]
        i = l
        for j in range(l+1,r+1):
            if A[j]<=p:
                i=i+1
                A[i],A[j]=A[j],A[i]
        A[i],A[l]=A[l],A[i]
        return i
    def Rand_Select(self,A,l,r,i): # to find ith order statistic
        if l==r:
            return A[l]
        q=self.randomized_partition(A,l,r)
        k=q-l+1
        if k==i:
            return A[q]
        elif i<k:
            return self.Rand_Select(A,l,q-1,i)
        else:
            return self.Rand_Select(A,q+1,r,i-k)
    def partition(self,A,l,r,x):
        for m in range(l,r+1):
            if A[m]==x:
                break
        A[m],A[l]=A[l],A[m]
        p=A[l]
        i=l
        for j in range(l+1,r+1):
            if A[j]<=p:
                i=i+1
                A[i],A[j]=A[j],A[i]
        A[i],A[l]=A[l],A[i]
        return i

sol_obj = Solution()
A=[1,2,3,4,5,6,7,8,9,10]
i=7
print (sol_obj.Rand_Select(A,0,len(A)-1,i))
