module Template -- DayN
  ( solve
  ) where

import           Control.Arrow
import           Data.List
import qualified Data.Map.Strict as M
import qualified Data.Set as S
import           Data.Maybe
import           Text.ParserCombinators.ReadP

parse = id

--solve1 :: [String] -> String
solve1 = unlines

--solve2 :: [String] -> String
solve2 = solve1

solve :: [String] -> (String, String)
solve = parse ^>> solve1 &&& solve2
