quicksort :: [Integer]->[Integer]

quicksort []=[]
quicksort (x:xs) = quicksort [y | y<-xs, y<x]++	[x]++ quicksort [y |y<-xs,y>=x]

main=print(quicksort [16,2,32,15])
