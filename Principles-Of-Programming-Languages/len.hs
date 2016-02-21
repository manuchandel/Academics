Length :: [a]-> Integer
Length []=0
Length x:xs= 1+ Length xs

main=print([1,2,3,9])
