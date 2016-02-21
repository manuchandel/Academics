len :: [a]-> Integer
len []=0
len (x:xs) = 1+ len xs

main=print(len [1,2,3,9])
