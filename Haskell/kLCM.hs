import Control.Monad
import Data.List
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

main = do
    t <- readLn
    replicateM_ t testcase

testcase :: IO ()
testcase = do
    firstLine <- getLine
    let [n,k] = map read . words $ firstLine
    putStrLn $ solve n k


solve :: Int -> Int -> String
solve n k = unwords . map show $ sol 
    where
        sol = solve3 (n-k+3) ++ replicate (k-3) 1

solve3 :: Int -> [Int]
solve3 n
    | odd n =  [1, (n-1) `div` 2, (n-1) `div` 2]
    | n `mod` 4 == 0 =  [n `div` 2 , n `div` 4, n `div` 4]
    | otherwise = [2, (n-2) `div` 2, (n-2) `div` 2]