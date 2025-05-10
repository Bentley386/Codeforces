import Control.Monad
import Data.List

-- https://codeforces.com/contest/1497/problem/A

main = do
    t <- getLine
    replicateM (read t) testcase

testcase :: IO ()
testcase = do
    n <- getLine
    a <- fmap words getLine
    putStrLn $ solve a

solve :: [String] -> String
solve a = unwords . map show $ solution
    where
        sorted = group . reverse . sort . map read $ a :: [[Int]]
        pairs = foldl (\(x,y) curr -> (head curr:x, tail curr ++ y)) ([],[]) sorted :: ([Int],[Int]) 
        solution = fst pairs ++ snd pairs :: [Int]