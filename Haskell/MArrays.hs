import Control.Monad
import Data.List
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

main = do
    t <- readLn
    replicateM t testcase

testcase :: IO ()
testcase = do
    firstLine <- getLine
    let [_,m] = map read . words $ firstLine
    a <- fmap (map read . words) getLine
    putStrLn $ solve a m

solve :: [Int] -> Int -> String
solve a m = 
    if MapS.member 0 counts then
        show $ solution + 1
    else show solution
    where
        modded = map (`mod` m) a
        counts = foldl' (\acc curr -> MapS.insertWith (+) curr 1 acc) MapS.empty modded :: Map.Map Int Int
        mapFoldF :: Int -> Int -> Int -> Int
        mapFoldF k a b 
            | k == 0 = b
            | MapS.member (m-k) counts && k < m-k = b
            | otherwise = (b+) . (1+) . max 0 . (subtract 1) . abs . (a-) $ MapS.findWithDefault 0 (m-k `mod` m) counts
        solution = MapS.foldrWithKey mapFoldF 0 counts :: Int