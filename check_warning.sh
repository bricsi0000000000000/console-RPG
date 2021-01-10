#!/bin/bash
if grep -q "warning" "cppcheck_results.txt"
then
	exit 1
fi
