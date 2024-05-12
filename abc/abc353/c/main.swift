import Foundation

let main: () -> Void = {
  let m = 100000000
  let n: Int = Int(exactly: Int(readLine()!)!)!
  let a: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }

  let sortedA: [Int] = a.sorted()
  var ans: Int = 0
  for ai in sortedA {
    ans += (ai * (n-1))
  }

  var r = n-1
  for i in 0 ..< n {
    while r >= 0 && sortedA[i]+sortedA[r] >= m {
      r -= 1
    }
    ans -= ((n - max(r, i) - 1) * m)
  }

  print(ans)
}


main()
