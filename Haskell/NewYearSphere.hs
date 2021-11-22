import Control.Monad
import Data.List
import qualified Data.Map as Map
import qualified Data.Map.Strict as MapS

main = do
    n <- readLn
    putStrLn . solve $ n

solve :: Integer -> String
solve  n = unwords . map show . reverse . map calc . divisors $ n 
    where
        calc :: Integer -> Integer
        calc k = n `div` k + n * (n `div` k - 1) `div` 2

divisors :: Integer -> [Integer]   --ty rosettacode
divisors n
    | 1 > n = []
    | otherwise = lows ++ fmap (quot n) (part n (reverse lows))
    where
        part n
            | n == square = tail
            | otherwise = id
        (square, lows) =
            (,) . (^ 2) <*> (filter ((0 ==) . rem n) . enumFromTo 1) $
            floor (sqrt $ fromIntegral n)
