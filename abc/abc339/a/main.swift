let main: () -> Void = {
  let s = readLine()!.split(separator: ".").map {String($0)}
  let ans = s[s.count - 1]
  print(ans)
}

main()