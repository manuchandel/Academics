sieve :: [Integer]->[Integer]
sieve []=[]
sieve (x:xs) = x:sieve [y | y<-xs, y `mod` x >0] 

main=print(sieve [2..])
