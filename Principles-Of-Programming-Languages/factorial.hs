factorial :: Integer -> Integer
factorial n
	| n==0 =1
	| n>0 =n* factorial (n-1)
	| otherwise =error " undefined negative error "

main=print(factorial 200)
