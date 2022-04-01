clear

message () {
	echo 
	echo "\t------------------------"
	echo "\t\t$1"
	echo "\t------------------------"
	echo 
}

message "100 numbers"

ARG=`ruby -e "puts (0...100).to_a.shuffle.join(' ')"`
./push_swap $ARG | wc -l
./push_swap `echo $ARG` | ./checker_Mac `echo $ARG`

message "500 numbers"

ARG=`ruby -e "puts (0...500).to_a.shuffle.join(' ')"`
./push_swap $ARG | wc -l
./push_swap `echo $ARG` | ./checker_Mac `echo $ARG`

message "3 numbers"

./push_swap 1 5 3
