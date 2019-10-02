main = do
    putStrLn "hello, what's your name?"
    name <- getLine
    putStrLn("Hello " ++ name ++ ". How are you?")
