import Control.Monad
import Data.List

-- https://codeforces.com/contest/1491/problem/B

main = do
    t <- getLine
    replicateM_ (read t) testcase

testcase :: IO ()
testcase = do
    [n,u,v] <- fmap (map read . words) getLine
    a <- fmap (map read . words) getLine
    putStrLn $ solve n u v a

solve :: Int -> Int -> Int -> [Int] -> String
solve n u v a
    | distance == 0 = show $ min (u+v) (2*v) 
    | distance == 1 = show $ min u v
    | otherwise = "0"
    where
        distance = snd $ foldl' (\(last,dist) curr -> (curr,max dist . abs $ last-curr)) (head a,0) a :: Int