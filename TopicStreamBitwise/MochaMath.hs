import Control.Monad
import Data.List
import Data.Bits
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

-- https://codeforces.com/gym/344975/problem/A

main = do
    t <- readLn
    replicateM_ t testcase

testcase :: IO ()
testcase = do
    getLine
    a <- map read . words <$> getLine
    putStrLn $ solve a 


solve :: [Int] -> String
solve  = show . foldl1 (.&.) 