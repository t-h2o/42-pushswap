#!/bin/bash

# OS SETTING ####################################################################

UNAME=`uname -s`
COL_RED="\033[31;1m"
COL_GRE="\033[32;1m"
COL_RES="\033[0m\n"

if [ $UNAME == "Linux" ]
then
	TESTER=checker_linux
fi

if [ $UNAME == "Darwin" ]
then
	TESTER=checker_Mac
fi


# MESSAGE ######################################################################

message () {

	echo 
	echo -e "\t------------------------"
	echo -e "\t\t$1"
	echo -e "\t------------------------"
	echo 
}

result () {

	printf "Try %s\n" $2

	#	False
	if [ $1 == "KO" ]
	then
		printf "%b\trip, it's KO%b" $COL_RED $COL_RES
	fi

	#	Correct
	if [ $1 == "OK" ]
	then
		printf "%b\tGreat, it's OK ! %s operation(s)%b" $COL_GRE $2 $COL_RES
	fi
}



# CHECKER ######################################################################

check_tree() {

	echo 
	OPS=`./push_swap $ARG | wc -l`
	RES=`./push_swap $1 | ./$TESTER $1`
	echo $1
	result $RES $OPS $1
}

check_five() {

	echo
	ARG=`ruby -e "puts (0...5).to_a.shuffle.join(' ')"`
	OPS=`./push_swap $ARG | wc -l`
	RES=`./push_swap $ARG | ./$TESTER $ARG`
	result $RES $OPS $ARG
}

check_hundred() {

	message "100 numbers"
	ARG=`ruby -e "puts (0...100).to_a.shuffle.join(' ')"`
	OPS=`./push_swap $ARG | wc -l`
	RES=`./push_swap $ARG | ./$TESTER $ARG`
	result $RES $OPS $ARG
}


check_fhundred() {
	
	message "500 numbers"
	ARG=`ruby -e "puts (0...500).to_a.shuffle.join(' ')"`
	OPS=`./push_swap $ARG | wc -l`
	RES=`./push_swap $ARG | ./$TESTER $ARG`
	result $RES $OPS $ARG
}


check_order () {

	./push_swap 1 2 3
	./push_swap 1 2 3 45 46 49 
}


# OVER-RANGE NUMBER ############################################################

min_max () {

	message "over-range numbers"
	
	message "max int + 1"
	./push_swap "1 2147483648 3"
	
	message "min int - 1"
	./push_swap "1 -2147483649 3"
}


# MAIN #########################################################################

result "1" "1 2 3 4" "5"

# #	check 3
# message "3 numbers"
# check_tree "1 5 3"
# check_tree "2 1 3"  
# check_tree "2 3 1"
# check_tree "3 2 1"
# check_tree "3 1 2"
# 
# #	check 4
# message "4 numbers"
# check_tree "1 5 3 0"
# check_tree "9 0 3 2"  
# check_tree "2 5 3 1"  
# 
# #	check 5
# message "5 numbers"
# check_tree "1 5 2 4 3"
# check_five
# 
# #	check order
# message "good order"
# check_order
# 
# #	five hundred
# check_fhundred
# 
# #	check hundred
# check_hundred
# 
# #	over range
# min_max
# 
# message "END TEST"
