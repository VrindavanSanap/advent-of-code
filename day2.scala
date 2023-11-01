// https://www.youtube.com/watch?v=-NleKOVsl28
// George hotz solution
import scala.io.Source 

var fix = Map('A' -> 'X', 'B' -> 'Y', 'C' -> 'Z' )
def score(x: String):Int = {
  var score: Int = 0 
  // draw
  if(fix.get(x(0)).get == x(2))  score += 3
  //win 
  if (x(0) == 'A' && x(2) == 'Y') score += 6
  if (x(0) == 'B' && x(2) == 'Z') score += 6
  if (x(0) == 'C' && x(2) == 'X') score += 6
  // base
  score += Map('X' -> 1, 'Y' -> 2, 'Z' -> 3).get(x(2)).get
  score 
}

@main def main() = {
  val lines: List[String] = Source.fromFile("day2.txt").getLines.toList
  println(lines.map(score));
  println(lines.map(score).sum);
}
