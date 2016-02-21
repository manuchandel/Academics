-- Implement map using folds
mymap :: (a->a)->[a]->[a]
mymap f xs = foldr (\x y-> f x:y) [] xs

main=print(mymap (+1) [2,3,4,2,1,8])
