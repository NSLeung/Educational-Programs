#!/bin/bash
while read -r LINE || [[ -n $LINE ]]; do
    echo $LINE | cut -f 1-3
done
