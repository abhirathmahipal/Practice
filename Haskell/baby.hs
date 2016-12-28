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
