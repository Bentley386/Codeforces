import Control.Monad
import Data.List
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

main = do
    t <- readLn
    replicateM_ t testcase

testcase :: IO ()
testcase = do
    n <- fmap read getLine
    putStrLn $ solve n 


solve :: Int -> String
solve n = show $ n `div` 2
