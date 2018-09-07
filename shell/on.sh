#!/bin/bash
user="$1"
if  who | grep "^$user " > /dev/null
then
    echo "$user is logged on"
fi
