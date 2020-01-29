let rec right_justify n s = 
  if n==70
  then let size = String.length(s) in right_justify (n-size) s
  else if n==0
  then print_string s
  else (print_string " "; right_justify (n-1) s;());;

let inp = read_line();;
right_justify 70 inp;;