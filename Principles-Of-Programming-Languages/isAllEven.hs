isAllEven :: [Integer]->Bool
isEven :: Integer->Bool

isEven x = (x `mod` 2)==0

isAllEven xs = xs== [x | x<-xs, isEven x]

main=print(isAllEven [6,2,32,98])
