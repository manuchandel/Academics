prepend :: [a]->a->[a]
prepend	xs a = a:xs

revList xs = foldl prepend [] xs

main=print(revList [2,3,4,2,1,8])
