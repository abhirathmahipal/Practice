-- matches to a pattern and that pattern is used
lucky :: (Integral a) => a -> String
lucky 7 = "You are lucky"
lucky x = "Sorry you're out of luck."

-- pattern matching also works on tuples
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors a b = (fst a + fst b, snd a + snd b)

-- _ means we really don't care about it
-- This is a custom first function
first :: (a, b, c) -> a
first (x, _, _) = x -- We don't care about b and c

-- guards are kind of like if else ladders but more readable
-- you can use a where block in the end. variables or expressions in 
-- the where section are in the scope of all the guards
-- Called wherebindings
-- Also you can define a function in where

-- Where bindings can also be used without guards or if you want one function to access
-- some shared name

-- let and in bindings are more local. They don't span across functions. Just for the 
-- in part of the expression
-- let bindings are expression themselves, where bindings are just syntactic constructs


cylinder :: (RealFloat a) => a -> a -> a
cylinder r h =
    let sideArea = 2 * pi * r * h
        topArea = pi * r ^ 2
    in  sideArea + 2 * topArea

{- 4 * (let a = 9 in a + 1) + 2  -}
-- notice how they are just expressions
-- this isn't the case with where

calBmi xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2] -- let bindings in a list comprehension are passed to everything before |
calBmi xs = [bmi | (w, h) <- xs, let bmi = w / h ^ 2, bmi >= 25.0] -- Having a filter to only fill the list with bmi's that are over 25

-- case expressions
head' :: [a] -> a
head' xs = case xs of [] -> error "No head for empty lists"
                      (x:_) -> x
