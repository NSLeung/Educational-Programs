#!/bin/bash
current_date_time="`date +%m-%d-%Y`";

if [ $# -eq 0 ]
then
    mkdir -p ${current_date_time}
    touch ${current_date_time}/problem.py
else # assumes correct format of input
    mkdir -p $1
    touch $1/problem.py
fi