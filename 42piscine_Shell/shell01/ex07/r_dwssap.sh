#!/bin/sh

cat -e /etc/passwd | grep -v '^#' | awk 'NR % 2 == 0' | cut -d ':' -f1  | rev | sort -r | awk -v start=$FT_LINE1 -v end=$FT_LINE2 'NR >= start && NR <= end' | tr '\n' ',' | sed 's/,/, /g' | sed 's/.\{2\}$/./' | tr -d '\n'
