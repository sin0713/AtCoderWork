
import Foundation

struct Pos {
  let i: Int
  let j: Int

  init(_ i: Int, _ j: Int) {
    self.i = i
    self.j = j
  }
}

let main: () -> Void = {
  let ints =  readLine()!.split(separator: " ").map { Int($0)! }
  let h: Int = ints[0]
  let w: Int = ints[1]
  var s: [String] = []
  for _ in 0 ..< h {
    s.append(readLine()!)
  }

  var res: [Pos] = []
  for i in 0 ..< h {
    for j in 0 ..< w {
      let index = s[i].index(s[i].startIndex, offsetBy: j)
      if s[i][index] == "o" {
        res.append(Pos(i, j))
      } 
    }
  }

  let ans = abs(res[0].i - res[1].i) + abs(res[0].j - res[1].j)
  print(ans)
}

main()
