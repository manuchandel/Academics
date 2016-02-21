-- Implement recursive map while using map function
-- Signature should be mapWhile :: (a->Bool)->(a->a)->[a]->[a]
-- It should return a list until where condition is satisfied

mapWhile :: (a->Bool)->(a->a)->[a]->[a]
mapWhile _ _ []=[]

mapWhile p q (x:xs)
					| p x == True = q x:mapWhile p q xs
					| otherwise =[]

main=print(mapWhile (<4) (*100) [2,3,4,2,1,8])

-- output [200,300]
