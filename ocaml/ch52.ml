let rec s n = 
if n=0 || n=1 then 1
else(
  let len = (String.length(fruit)-1) in 
  if s.[0]=s.[len-1] then 
    (rec (String.sub s 1 (len-1)) (n-1))
  else 0;;
);;

print_string (rec radar 5);;