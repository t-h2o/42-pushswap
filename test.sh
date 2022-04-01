clear
ARG=`ruby -e "puts (0...500).to_a.shuffle.join(' ')"`
./push_swap $ARG | wc -l
./push_swap `echo $ARG` | ./checker_Mac `echo $ARG`

