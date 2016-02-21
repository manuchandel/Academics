sumList:: [Integer]->Integer
sumList xs = foldr (+) 0 xs

main=print(sumList [2,3,4,2,1,8])
