let check_fermat a b c n = 
  if (a**n +. b**n <> c**n) then 0 else 1;;

Printf.printf ("Enter a,b,c and n: ");;
let a = read_float();;
let b = read_float();;
let c = read_float();;
let n = read_float();;

let a = float_of_int(int_of_float a);;
let b = float_of_int(int_of_float b);;
let c = float_of_int(int_of_float c);;
let n = float_of_int(int_of_float n);;

print_int (check_fermat a b c n);;
print_string("\n");;