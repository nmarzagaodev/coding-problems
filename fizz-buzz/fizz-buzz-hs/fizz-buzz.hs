isMultipleOf3 :: Integer -> Bool
isMultipleOf3 n = n `mod` 3 == 0

isMultipleOf5 :: Integer -> Bool
isMultipleOf5 n = n `mod` 5 == 0

fizzBuzzLoop :: Integer -> IO()
fizzBuzzLoop 101 = putStrLn "End"
fizzBuzzLoop n = do
    if isMultipleOf5 n && isMultipleOf3 n then putStrLn "FizzBuzz"
    else if isMultipleOf3 n then putStrLn "Fizz"
    else if isMultipleOf5 n then putStrLn "Buzz"
    else putStrLn (show n)
    
    fizzBuzzLoop (n + 1)

main :: IO ()
main =  do
    fizzBuzzLoop 1