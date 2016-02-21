data Tree = Nil | Node Integer (Tree) (Tree)
myTree= Node 1  
        (Node 2  
            (Node 3 
                (Node 4 Nil Nil)  
                (Node 5 Nil Nil)  
            )  
            (Node 6  
                (Node 7 Nil Nil)  
                (Node 8 Nil Nil)  
            )  
        )  
        (Node 9  
            (Node 10 
                (Node 11 Nil Nil)  
                (Node 12 Nil Nil)  
            )  
            (Node 13  
                (Node 14 Nil Nil)  
                (Node 15 Nil Nil)  
            )  
        )  

preorder :: Tree -> [Integer]
preorder Nil =[]
preorder (Node i l r)= i : (preorder l ++ preorder r)

postorder :: Tree -> [Integer]
postorder Nil =[]
postorder (Node i l r)= postorder l ++ postorder r++[i]

inorder :: Tree -> [Integer]
inorder Nil =[]
inorder (Node i l r)= inorder l ++[i]++inorder r

main =print(inorder myTree)
