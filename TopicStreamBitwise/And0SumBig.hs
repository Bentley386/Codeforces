import Control.Monad
import Data.List
import Data.Bits
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

-- https://codeforces.com/gym/344975/problem/B

main = do
    t <- readLn
    replicateM_ t testcase

testcase :: IO ()
testcase = do
    [n,k] <- map read . words <$> getLine
    putStrLn $ solve n k 


solve :: Integer -> Integer -> String
solve 1 _ = "1"
solve x y =  show . foldr1 (\x y -> x*y `mod` modulo ) $ replicate (fromIntegral y) x 
    where modulo = 1000000007