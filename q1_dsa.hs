data Inhabitant = Hobbits String | Dwarves String | Humans String | Elves String deriving (Eq, Ord, Show)

moreImportant :: Inhabitant -> Inhabitant -> Bool
moreImportant (Dwarves x) (Dwarves y) = x > y
moreImportant (Hobbits x) (Hobbits y) = x > y
moreImportant (Humans x) (Humans y) = x > y
moreImportant (Elves x) (Elves y) = x > y
moreImportant a b = a > b

data Tree t = Nil | Node t (Tree t) (Tree t) deriving (Show, Eq)

auxFilter :: (a-> Bool) -> [a] -> [a] -> [a]
auxFilter f a [] = a
auxFilter f a (x:xs) | f x = auxFilter f (a ++ [x]) xs
                     | otherwise = auxFilter f a xs

createImportanceTree :: [Inhabitant] -> Tree Inhabitant
createImportanceTree [] = Nil 
createImportanceTree (x:[]) = Node x Nil Nil
createImportanceTree (x:xs) = Node x (createImportanceTree (menores)) (createImportanceTree (maiores))
        where
                maiores = auxFilter (\c -> c `moreImportant` x) [] xs
                menores = auxFilter (\c -> x `moreImportant` c) [] xs

insert :: Inhabitant -> Tree Inhabitant -> Tree Inhabitant 
insert x Nil = Node x Nil Nil
insert x (Node n l r) | x == n = Node n l r
                      | moreImportant x n = Node n (insert x l) r
                      | otherwise = Node n (insert x r) l

treetolist :: Ord a => Tree a -> [a]
treetolist Nil = [] 
treetolist (Node n l r) = n : treetolist (l) ++ treetolist (r)

isi :: Inhabitant -> Tree Inhabitant -> Bool
isi _ Nil = False
isi x (Node n l r) | x == n = True
                   | moreImportant x n = isi x r
                   | otherwise = isi x l 

children :: Tree Inhabitant -> Inhabitant -> [Inhabitant]
children Nil _ = []
children (Node n l r) x | isi x (Node n l r) = auxFilter (\c -> c `moreImportant` x) [] (treetolist (Node n l r))
                        | otherwise = []