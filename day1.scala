import scala.io.Source 

@main def main = {
  val lines: List[String] = Source.fromFile("intput.txt").getLines.toList
  val tl = lines.partition(_ = "")
  println(tl)
}
