(* OCaml (Functional Approach) *)
let mean lst =
  let sum = List.fold_left (+.) 0.0 (List.map float_of_int lst) in
  sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    float_of_int (List.nth sorted (len / 2 - 1) + List.nth sorted (len / 2)) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let freq = List.fold_left (fun acc x ->
    let count = try List.assoc x acc with Not_found -> 0 in
    (x, count + 1) :: List.remove_assoc x acc
  ) [] lst in
  let max_freq = List.fold_left (fun acc (_, v) -> max acc v) 0 freq in
  List.fold_left (fun acc (k, v) -> if v = max_freq then k :: acc else acc) [] freq

(* Sample usage *)
let () =
  let numbers = [1; 2; 2; 3; 4; 5; 5; 5] in
  Printf.printf "Mean: %.2f\n" (mean numbers);
  Printf.printf "Median: %.2f\n" (median numbers);
  Printf.printf "Mode: %s\n"
    (String.concat ", " (List.map string_of_int (mode numbers)))
