#!/bin/bash

# OS SETTING ####################################################################

UNAME=`uname -s`

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


# CHECKER ######################################################################

check_tree() {

	echo 
	echo -e "test $1\t`./push_swap $1 | wc -l` operation(s)"
	RES=`./push_swap $1 | ./$TESTER $1`
	echo -e "\t\t$RES"
}

check_five() {

	echo
	ARG=`ruby -e "puts (0...5).to_a.shuffle.join(' ')"`
	echo TEST : $ARG
	echo "test $ARG\t`./push_swap $ARG | wc -l` operation(s)"
	./push_swap $ARG | wc -l
	RES=`./push_swap $ARG | ./$TESTER $ARG`
	echo -e "\t\t$RES"
}

check_hundred() {

	message "100 numbers"
	ARG=`ruby -e "puts (0...100).to_a.shuffle.join(' ')"`
	echo -e "\t\t`./push_swap $ARG | wc -l` operations"
	RES=`./push_swap $ARG | ./$TESTER $ARG`
	echo -e "\t\t$RES"
}


check_fhundred() {
	
	message "500 numbers"
	ARG=`ruby -e "puts (0...500).to_a.shuffle.join(' ')"`
	echo -e "\t\t`./push_swap $ARG | wc -l` operations"
	RES=`./push_swap $ARG | ./$TESTER $ARG`
	echo -e "\t\t$RES"
}


check_order () {

	message "good order"
	./push_swap 1 2 3
	./push_swap 1 2 3 45 46 49 
}


# MAIN #########################################################################

#	check 3
message "3 numbers"
check_tree "1 5 3"
check_tree "2 1 3"  
check_tree "2 3 1"
check_tree "3 2 1"
check_tree "3 1 2"

#	check 4
message "4 numbers"
check_tree "1 5 3 0"
check_tree "9 0 3 2"  
check_tree "2 5 3 1"  

#	check order
check_order

#	five hundred
check_fhundred

#	check hundred
check_hundred
