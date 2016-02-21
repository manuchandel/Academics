fibo :: Integer-> Integer
fibo n
	|n==0 =0
	|n==1 =1
	|n>0 =fibo (n-1)+fibo (n-2)
	|otherwise =error " undefined negative error "

main=print(fibo 10)
