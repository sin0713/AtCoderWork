import Foundation

let main: () -> Void = {
  let a = readLine()!.split(separator: " ").map { Int($0)! }
  let b = readLine()!.split(separator: " ").map { Int($0)! }

  var sumA = 0
  a.forEach { sumA += $0 }
  var sumB = 0
  b.forEach { sumB += $0 }

  let res = sumA-sumB
  let ans = res < 0 ? 0 : res+1
  print(ans)
}

main()