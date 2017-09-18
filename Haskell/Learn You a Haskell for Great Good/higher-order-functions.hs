-- Putting a space between two things is simply function application
-- The space is kind of like an operator which takes the highest preference

-- The following are equivalent
max 4 5
(max 4 ) 5


multThree :: (Num a) => a -> a -> a -> a
multThree x y z = x * y * z

-- by calling function with few parameters than they normally would expect
-- you are creating custom functions on the fly

compareWithHundred :: (Num a, Ord a) => a -> Ordering
compareWithHundred = compare 100

-- infix functions can also be partially applied (i.e currying) by using sections
-- It creates a function that takes one parameter and applies it
-- to the side that's missing an operand
divideByTen :: (Floating a) => a -> a
divideByTen = (/10)

isUpperAlpha :: Char -> Bool
isUpperAlpha = (`elem` ['A'..'Z'])

-- Be careful about subtraction of negative integers (doube - signs probably). You can use (subtract 4) 


-- Functions can take functions as parameters and also return functions

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f (f x)

-- This can be read as
-- applyTwice takes in a function which takes in a type 'a' and returns the same type.
-- It also takes in a parameter of type a. All of them should be of the same type

applyTwice (+3) 10 -- 16
applyTwice (3:) [1] -- [3, 3, 1]


-- std library zipWith
zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]

-- type definition says that the first parameter is a function which takes in two parameters and returns one things
-- The second parameters 
-- should be a list of type 'a'
-- The third parameter should be a list of type 'b'
-- The return type is a list of type 'c'

zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys
-- The first two conditions takes care of uneven lengths
-- So say xs is longer than ys, a time will come when ys will be _, at that point, it'll return an empty list


-- map


-- filter
filter :: (a -> Bool) -> [a] -> [a]
filter _ [] = []
filter p (x:xs)
    | p x = x : filter p xs
    | otherwise = filter p xs


-- quick sort by filtering
quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) = 
    let smallerSorted = quicksort (filter (<=x) xs)
        biggerSorted = quicksort (filter (>x) xs)
    in smallerSorted ++ [x] ++ biggerSorted

-- finding the largest number under 10,000 divisible by 3829
largestDivisible :: (Integral a) => a

largestDivisible = head (filter p [100000, 99999..])
    where p x = x `mod` 3829 == 0

-- Here we want the head, i.e the first element of the list
-- remember that Haskell is lazy. Since we are going in reverse order
-- and head only wants one, execution will stop as soon as a number that 
-- is perfectly divisible by 3829 is found


-- takeWhile function
-- keeps taking from the list unless a certain condition is broken

-- lambdas
numLongChains :: Int
numLongChains = length (filter (\xs -> length xs > 15) (map chain [1..100]))

-- lambdas too can take in any number of parameters
zipWith (\a b -> (a * 30 + 3) / b) [5,4,3,2,1] [1,2,3,4,5]

-- pattern matching is possible as well like regular functions. Only difference being that you can't match several patterns with fall throughs.
-- lambdas are surrounded by () unless they are extended all the way to the right.
-- Even lambdas can be curried
addThree :: (Num a) => a -> a -> a -> a
addThree = \x -> \y -> \z -> x + y + z

-- yet to fill foldr, foldl and scanr, scanl

-- Function Application with $
-- $ has the lowest precedence. It can be used to reduce the number of curly braces and will also save some keystrokes
-- When a $ is encountered, the expression on the right is applied as the parameter to the function on its left

-- function composition
-- . is used for function composition
-- f (g (z x)) is equivalent to (f . g. z) x
-- another use case is point free style or pointless style

-- not in point free style
fn x = ceiling (negate (tan (cos (max 50 x))))
-- in point free style
fn x = ceiling . negate . tan . cos . max 50 -- a function which compares max with 50 and does the same thing

-- long composition chains are discouraged. People prefer using let bindings as they are more readable





