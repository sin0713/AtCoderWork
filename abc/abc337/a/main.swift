import Foundation

let main:  () -> Void = {
  let n = Int(readLine()!)!

  var sumX = 0
  var sumY = 0
  for _ in 0 ..< n {
    let xy = readLine()!.split(separator: " ").map { Int($0)! }
    sumX += xy[0]
    sumY += xy[1]
  }

  if sumX == sumY {
    print("Draw")
  } else if sumX < sumY {
    print("Aoki")
  } else {
    print("Takahashi")
  }
}

main()