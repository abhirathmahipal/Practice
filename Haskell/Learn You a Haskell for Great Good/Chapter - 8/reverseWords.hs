main = do
    line <- getLine
    if null line
        then return ()
        else do
            putStrLn $ reverseWords line
            main

reverseWords :: String -> String
-- function composition and hence no need to write it like
-- reversewords line = unwords (map reverse (words st))
reverseWords = unwords . map reverse . words
