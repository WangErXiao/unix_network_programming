#!bin/bash
count=1200
while [ $count -gt  0 ]
do
	 { sleep 1 
	   echo hello $count
	   sleep 60
	   echo hello1 $count
	   echo exit 
	 } | telnet 127.0.0.1 9999  & 

         (( count--))	
done

sleep 120
