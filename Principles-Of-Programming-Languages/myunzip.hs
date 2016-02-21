myzip :: (a,b)->([a],[b])->([a],[b])
myzip (x,y) (xs,ys)=(x:xs,y:ys)

myunzip :: [(a,b)]-> ([a],[b])
myunzip []=([],[])
myunzip (x:xs)= myzip x (myunzip xs)
main=print(unzip (zip [2..10] [3..10]))
