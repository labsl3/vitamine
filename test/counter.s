push 0

loop:
  push 1
  add

  dpl
  print

  dpl
  push 1000000
  cmp
  jne loop

