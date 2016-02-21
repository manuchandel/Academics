revList :: [a]-> [a]
revList []=[]
revList (x:xs) = revList xs ++ [x]

main=print(revList [1,2,3,9])
