doubleAll :: [Integer]-> [Integer]
doubleAll []=[]
doubleAll (x:xs) = 2*x : doubleAll xs

main=print(doubleAll [1,2,3,9])
