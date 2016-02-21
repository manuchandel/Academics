sumList :: [Integer]-> Integer
sumList []=0
sumList (x:xs) = x+ sum xs

main=print(sumList [1,2,3,9])
