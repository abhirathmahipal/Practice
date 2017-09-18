doubleMe x = x + x
doubleSmallNumber x = if x > 100
                        then x
                        else x * 2
doubleUs x y = doubleMe x + doubleMe y


-- ' is valid in a function name.
-- ' at the end of the same signifies that it isn't lazy.

conanO'Brien = "It's a-me, Conan O'Brien!"

-- defines a list
-- let lostNumber = [4,8,12]

-- [1,2,3] ++ [4,5,6] -- ++ goes through every item and concatenates

-- "hello" ++ "uworld" -- ++ not suitable for large strings and lists. Not efficient


-- 'a':"small cat" -- : instantly adds a before small cat
-- 5:[1,2,34,5]
-- !! to get the elements by index
-- Strings are also lists in haskell
-- > and == compares things element wise
-- head returns the first element
-- tail chops the head and returns everything
-- last returns only the last element
-- init returns the everything except the last element
-- null checks if a list is empty
-- length returns the length
-- reverse [5,4,3,2,1] -> [1,blah, blah]
-- take 3 [5,4,3,2,1] -> [5,4,3]
-- take 1 [3,9,3] -> [3]
-- drop 3 [8,4,2,1,5,6] -> drops 3 elements and returns [1,5,6]
-- drop 100 [1,2,3,4] -> []
-- sum [4,3,2] -> sum of all
-- product
-- `elem` -> infix notation. Tells if that particular element is a part or not
-- [1,2,3] is just syntastic sugar for 1:2:3:[].
-- [1..20], ['a'..'z'] are all ranges
-- You can also give a step like this [2,4..20]
-- take 24 [13,26..] -> first 24 multiples of 13
-- cycle takes a list and cyles into an infinite list
-- repeat takes a single element and produces an infinite list of just that element
-- replicate if you want some number of the same element in a list
-- [x*2 | x <- [1..10]] simple list comprehension
-- [x*2 | x <- [1..10], x*2 >= 12] list comprehension with some condition (also called filtering since before it's passed in to process, filtered. Wedding out lists by predicates is also called Filtering.
-- [if x < 10 then "BOOM" else "BANG" | x <- xs, odd x] Filtering by odd predicate and also additional condition in the function at the start
-- Drawing from multiple lists is also possible. [x*y | x <- [10..20], y <- [10..20]]
-- removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]
-- lists don't have to be of the same length, 1 or infinite doesn't matter but you can place some restrictions with tuples. They can be modeled into strict types
-- zip takes two lists and zips them together. If they aren't of the same length, the longer one just gets cut off
-- ==, +, * etc are all operators. they follow infix notation by default. If finding it's type or passing to another function, surround it with parentheses
