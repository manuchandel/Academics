isMember :: Integer->[Integer]->Bool
isMember _ [] = False
isMember y (x:xs)
		|(y==x) 	=True
		|otherwise =isMember y xs

main=print(isMember 13 [1,2,3,9])
