remove' :: Ord a => Int -> [(a, Int)] -> [(a, Int)] -> [(a, Int)]
remove' y acc [] = acc
remove' y acc (x:xs)     | y /= snd' x = remove' y (acc ++ [x]) xs
                         | otherwise = remove' y acc xs

posicoes' :: Ord a => Int -> [a] -> [(a, Int)] -> [(a, Int)]
posicoes' y [] acc  = acc
posicoes' y (x:xs) acc = posicoes' (y+1) xs (acc ++ [(x,y)])

maior :: Ord t => t -> [t] -> t
maior m [] = m
maior m (x:xs) | m > x = maior m xs
               | otherwise = maior x xs

menor :: Ord t => t -> [t] -> t
menor m [] = m
menor m (x:xs) | m < x = menor m xs
               | otherwise = menor x xs

menorl :: (Ord a) => [a] -> a 
menorl [x] = x
menorl (x:xs) = menor (x) (xs)

maiorl :: (Ord a) => [a] -> a
maiorl [x] = x
maiorl (x:xs) = maior (x) (xs)

snd' :: (a, b) -> b
snd' (a,b) = b

fst' :: (a, b) -> a
fst' (a,b) = a

length' :: Eq a => [a] -> Int -> Int
length' [] c = c
length' (x:xs) c = length' xs (1+ c)

convert :: [(t, Int)] -> [t] -> [t]
convert [] acc = acc 
convert (x:xs) acc = convert xs (acc ++ [fst' x])

abs' :: Int -> Int
abs' a | a < 0 = -a
       | otherwise = a 


nmenor' :: Ord a => Int -> [(a, Int)] -> (a,Int)
nmenor' _ [] = error "please"
nmenor' 1 x = (menorl x)
nmenor' y x | y <= (length' x 0) =  (nmenor' (y-1) (remove'(snd' (menorl x)) [] x))
            | mod y (length' x 0) == 1 = (menorl x) 
            | otherwise = (nmenor' (y-(length' x 0)-1) (remove' (snd' (menorl x))[] x))

nmaior' :: Ord a => Int -> [(a, Int)] -> (a,Int)
nmaior' _ [] = error "please"
nmaior' 1 x = (maiorl x)
nmaior' y x | y <= (length' x 0) =  (nmaior' (y-1) (remove'(snd' (maiorl x)) [] x))
            | mod y (length' x 0) == 1 = (maiorl x) 
            | otherwise = (nmaior' (y-(length' x 0)-1) (remove' (snd' (maiorl x))[] x))


removeN :: Ord a => Int -> [a] -> [a]
removeN _ [] = []
removeN 0 x = x 
removeN x y | x > 0 = convert(removet(nmaior' x (posicoes' 0 y []))[] (posicoes' 0 y [])) [] 
           |  otherwise = convert(removet(nmenor' (abs' x) (posicoes' 0 y [])) [] (posicoes' 0 y [])) []

removet :: Ord a => (a,Int) -> [(a,Int)] -> [(a,Int)] -> [(a,Int)]
removet y acc [] = acc
removet y acc (x:xs) | y /= x = removet y (acc ++ [x]) xs
                     | otherwise = removet y acc xs  