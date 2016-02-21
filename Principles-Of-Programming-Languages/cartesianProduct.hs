cartesianProduct :: [a]->[b]->[(a,b)]
cartesianProduct xs ys= [(x,y) | x<-xs, y<-ys]

main=print(cartesianProduct [1,2,3] ['m','a','n','u'])
