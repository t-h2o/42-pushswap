clear

message () {
	echo 
	echo "\t------------------------"
	echo "\t\t$1"
	echo "\t------------------------"
	echo 
}

check_tree() {
	echo 
	echo "test $1\t`./push_swap $1 | wc -l` operation(s)"
	./push_swap `echo $1` | ./checker_Mac `echo $1`
}

check_five() {
	echo
	ARG=`ruby -e "puts (0...5).to_a.shuffle.join(' ')"`
	echo TEST : $ARG
	echo "test $ARG\t`./push_swap $ARG | wc -l` operation(s)"
	./push_swap $ARG | wc -l
	./push_swap `echo $ARG` | ./checker_Mac `echo $ARG`
}

message "100 numbers"

ARG=`ruby -e "puts (0...100).to_a.shuffle.join(' ')"`
./push_swap $ARG | wc -l
./push_swap `echo $ARG` | ./checker_Mac `echo $ARG`



message "500 numbers"

ARG=`ruby -e "puts (0...500).to_a.shuffle.join(' ')"`
./push_swap $ARG | wc -l
./push_swap `echo $ARG` | ./checker_Mac `echo $ARG`



message "good order"

./push_swap 1 2 3
./push_swap 1 2 3 45 46 49 



message "3 numbers"

check_tree "1 5 3"
check_tree "2 1 3"  
check_tree "2 3 1"
check_tree "3 2 1"
check_tree "3 1 2"


message "5 numbers"

check_five
