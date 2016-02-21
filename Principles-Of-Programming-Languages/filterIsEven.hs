isEven :: Integer->Bool
isEven x= (x `mod` 2 == 0)

main=print(filter isEven [2,3,4,8])

-- output [2,4,8]
