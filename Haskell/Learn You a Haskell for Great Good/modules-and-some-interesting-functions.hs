-- default module is Prelude
-- when in ghci you can do :m + Data.List to put the module in the global namespace
-- to import only a couple of stuff 
import Data.List (nub, sort)
-- to import everything except a few
import Data.List hiding (nub)
-- to deal with name clashes. So anything with clashes with the namespace of other functions (eg filter from Data.Map clases with the global filter). So to use filter from Data.Map we have to Data.Map.filter
import qualified Data.Map 
import qualified Data.Map as M


intersperse '.' "MONKEY"
-- M.O.N.K.E.Y


intercalate " " ["hey", "there", "guys"]
-- takes a list of lists, inserts some element between them
-- and then flattens it
-- hey there guys


transpose [[1,2,3], [4,5,6], [7,8,9]]
-- gives [[1,4,7], [2,5,6], [3,6,9]]

concat ["foo", "bar", "car"]
"foobarcar" -- lists of lists into a list

-- and ttakes a list of boolean values and returns true only if all the values in the list are True
and $ map (>4) [5,6,7,8]
-- true

-- or
or $ map (>4) [5,1,1,1]

-- any and all
any (==4) [2,3,5,6,1,4]
-- True
all (>4) [6,9,10]
-- True

-- iterate  takes a function and a starting value. applies a function to the starting value, then to the result and so on
take 10 $ iterate (*2) 1
[1, 2, 4, 8, 16, 32, 64, 128, 256, 512]

-- splitAt takes a number and a list
splitAt 3 "heyman"
("hey", "man")

-- dropWhile is similar to takeWhile but keeps dropping till the predicate is true

-- and loads of other functions

-- Data.Char
-- isControl (control character)
-- isSpace (tabs, whitespaces etc)
-- isUpper etc
-- generalCategory (returns what kind of character it is)

-- Data.Map
-- Dictionaries or association lists
-- Map.fromList
-- Duplicates are discarded
Map.fromList [(1,2), (3,4), (3,2), (5,5)]
[(1,2), (3,2), (5,5)] -- duplicates gone
Map.fromList :: (Ord k) => [(k, v)] -> Map.Map k v  

-- keys should be orderable as it creates a tree structure under the hood
-- maps also have functions like lookup, map and filter, toList etc

-- Data.Set
-- unique elements only, internally implemented with trees
-- finding for membership, deletion are faster than lists

-- name clashes a lot with Prelude and Data.List
import qualified Data.Set as Set
-- again functions like map, filter, intersection etc

-- Making your own modules
-- Export only the ones you want, qualified imports etc


