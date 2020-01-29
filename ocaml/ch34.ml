let addSpace s1 s2 = s1^" "^s2;;

let addMinus s1 = addSpace s1 "-\n";;

let addPlus s1 = addSpace s1 "+\n";;

(* Aditya's Function *)
let rec append s1 s2 x = 
  if x==0
  then(s1^"\n")
  else(
    append (addSpace s1 s2) s2 (x-1) 
  );;


(* Pulkits Function *)
let rec concat s c n = 
  if n==0 then s else concat s c (n-1)^c;;

let m = addSpace "Check" "mate";;
print_string(addMinus m);;
print_string(addPlus m);;
print_string(append m "*" 4);;
print_string(concat m "*" 4);;
print_string("\n");;