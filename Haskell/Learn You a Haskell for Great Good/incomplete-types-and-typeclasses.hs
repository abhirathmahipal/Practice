-- Bool is a True or False
data Bool = False | True 


-- shapes
-- a shape is either a circle or a rectangle
-- Circle and Rectagle are value constructors (functions) that take in params and return a Shape (constructor basically)
--
data Shape = Circle Float Float Float | Rectangle Float Float Float
-- now type signature of :t Circle
-- Circle :: Float -> Float -> Float -> Shape
-- Rectangle :: Float -> Float -> Float -> Shape

-- surface :: Shape -> Float
-- Right now we have to construct a shape because circle and rectangle
-- aren't types yet. Shape is a type as of now but we are yet to define something for Circle and Rectangle
surface (Circle _ _ r) = pi * r ^ 2
surface (Rectange x1 y1 x2 y2) = (abs $ x2 - x1) * (abs $ y2 - y1)

-- Circle 10 20 5 will give an error (haskell doesn't know how to display)


-- Show will aid in printing
-- value constructor has the same name as the type
data Point = Point Float Float deriving (Show)
data Shape = Circle Point Float | Rectangle Point Point deriving (Show) -- now circle and rectangle take points

-- To export all value constructors of Shape
module Shapes
( Point(..)
, Shape(..)


) where

-- Record syntax
 data Person = Person String String Int Float String String deriving (Show)  

-- Creating accessors for each attribute becomes very tedious, Haskell can do this automatically for us
firstName :: Person -> String  
firstName (Person firstname _ _ _ _ _) = firstname  
  
data Person = Person { firstName :: String  
                     , lastName :: String  
                     , age :: Int  
                     , height :: Float  
                     , phoneNumber :: String  
                     , flavor :: String  
                     } deriving (Show)   
-- so each value can be accessed via functions
-- :t firstName
-- firstName :: Person -> String

-- New types can be also be made in such a fashion
Car {company="Ford", model="Mustang", year=1967}  
