myzip ::[a]->[b]->[(a,b)]
myzip [] _=[]
myzip _ []=[]
myzip (x:xs) (y:ys)= (x,y) : myzip xs ys
main=print(myzip [2..] [3..])
