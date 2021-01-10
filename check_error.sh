#!/bin/bash
if [grep -q "error" "cppcheck_results.txt"]
then
	exit 1
fi
