let tr'' a b c = 
  if a+b <= c || b+c <= a || c+a <= b then 0 else 1;;

print_int (tr'' 2 1 1);;
print_string("\n");;