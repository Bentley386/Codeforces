import Control.Monad
import Data.List
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

-- https://codeforces.com/gym/348180/problem/B

main = do
    t <- readLn
    replicateM_ t testcase

testcase :: IO ()
testcase = do
    x <- fmap read getLine
    putStrLn $ solve x 


solve :: Int -> String
solve x = "1 " ++ show (x-1)
