#!/usr/bin/perl -w
#use strict;
#use locale;
#Author: Sifei Han
#E-mail: sehan2@g.uky.edu
#Date: Nov 16,2009
#For the program has for function, the first one is when user input the patient number and the program return the the patient's information. The second function is when user input the patient name then the program return that patient information. For the third function is when user input the event ID, the program return the information about that ID. And the Last function is when the user input a value the program ignore the data before that value and output the next 5 data.
 
my $infile1 = "patient.data"; #open the patient data
my $infile2 = "event.data"; # open the event data
# check the patient.data if it open correct
if(!open(SINPUTF, "<$infile1")){
		print "Fail to open $infile1\n";
		exit;
}

$num = 0;
$num1 = 0;
$flagerror = "false";
@patient = ();
@event = ();
my @Month=("January","February","March","April","May","June","July","August","September","October","November","December"); #used to change the date format
# open the patient.data and save the data in the patient array;
while (defined($sinput = readline SINPUTF)){
		$num++;
		@Temp = split(' ', $sinput);
		for($j = 0; $j <= $#Temp; $j++){
				$patient[$num - 1][$j] = $Temp[$j];
			}
	}
close(SINPUTF);
#check if there exist bad data in the file
for($i = 0; $i <$num; $i++){
	$j = $i+1;
	if(length($patient[$i][0]) != 6){
		$flagerror = "true";
		print "In the line$j of the patient.data the patient number $patient[$i][0] doesn't contain 6 digits.\n";
	}
	if($patient[$i][0] =~ /[^0-9]/)
	{
		$flagerror = "true";
		print "In the line$j of the patient.data the patient number $patient[$i][0] contain alphabetic characters\n";
	}
	if(length($patient[$i][1]) > 20){
		$flagerror = "true";
		print "In the line$j of the patient.data the patient last name $patient[$i][1] too long\n";
	}else{
		if(!($patient[$i][1] =~ /[A-Z]|[a-z]/)){
			$flagerror = "true";
			print "In the line$j of the patient.data the patient last name $patient[$i][1] are not all of them made by alphabetic characters\n";
		}
	}
	if(length($patient[$i][2]) > 20){
		$flagerror = "true";
		print "In the line$j of the patient.data the patient first name $patient[$i][2] too long\n";
	}
	else{
		if(!($patient[$i][2] =~ /[A-Z]|[a-z]/)){
			$flagerror = "true";
			print "In the line$j of the patient.data the patient first name $patient[$i][1] are not all of them made by alphabetic characters\n";
		}
	}
	if((length($patient[$i][3]) != 9)and(length($patient[$i][3])!= 10)){
		$flagerror = "true";
		print "In the line$j of the patient.data the patient birth date $patient[$i][3] is invalid\n";
	}
	if(length($patient[$i][3]) == 9){
		if(!($patient[$i][3] =~ /[0-9]{1}\/[0-9]{2}\/[0-9]{4}/)){
			$flagerror = "true";
			print "In the line$j of the patient.data the patient birth date $patient[$i][3] is invalid\n";
		}
	}
	if(length($patient[$i][3]) == 10){
		if(!($patient[$i][3] =~ /[0-9]{2}\/[0-9]{2}\/[0-9]{4}/)){
		  $flagerror = "true";
			print "In the line$j of the patient.data the patient birth date $patient[$i][3] is invalid\n";
		}
	}
	if(length($patient[$i][4]) != 2){
		$flagerror = "true";
		print "In the line$j of the patient.data the patient floor number $patient[$i][4] is invalid\n";
		if(!($patient[$i][4] =~ /^[0-9]+[A-Z]/)){
			$flagerror = "true";
			print "In the line$j of  the patient.data the patient floor number $patient[$i][4] is invalid\n";
		}
	}
	if(length($patient[$i][5]) < 9){
		if(!((length($patient[$i][5])== 4)and($patient[$i][5] eq "NONE"))){
			$flagerror = "true";
			print "In the line$j of the patient.data the patient DNA patient[$i][5] is invalid\n";
		}
	}elsif(length($patient[$i][5]) > 11){
		$flagerror = "true";
		print "In the line$j of the patient.data the patient DNA patient[$i][5] is invalid\n";
	}else{
		if(!($patient[$i][5] =~ /^DNA+[0-9]+\.+data$/)){
			$flagerror = "true";
			print "In the line$j of the patient.data the patient DNA patient[$i][5] is invalid\n";
		}
	}	
}

#check if the event.data open correctly
if(!open(SINPUTF, "<$infile2")){
		print "Fail to open $infile2\n";
		exit;
}
#pass the data to an array @event
while (defined($sinput1 = readline SINPUTF)){
		$num1++;
		@Temp = split(' ', $sinput1);
		for($j = 0; $j<= $#Temp; $j++){
				$event[$num1 - 1][$j] = $Temp[$j];
		}
	}
close(SINPUTF);

#check if there has bad data exit
for($i = 0; $i <$num1; $i++){
	$j = $i+1;
	if(length($event[$i][0]) != 5){
		$flagerror = "true";
		print "On the line$j in the event.data the event ID $event[$i][0] is invaild.\n";
	}else{
		if(!($event[$i][0] =~ /^[A-Z]+[0-9]{4}/)){
			$flagerror = "true";
			print "On the line$j in the event.data the event ID $event[$i][0] is invaild.\n";
		}
	}
	if(length($event[$i][1]) != 6){
		$flagerror = "true";
		print "On the line$j in the event.data the patient number $event[$i][1] is not contain 6 digits.\n";
	}else{
		if($event[$i][1] =~ /[^0-9]/)
		{
			$flagerror = "true";
			print "On the line$j in the event.data the patient number $event[$i][1] contain alphabetic characters\n";
		}
	}
	if(length($event[$i][2]) != 3){
		$flagerror = "true";
		print "On the line$j in the event.data the code ID $event[$i][2] is invalid\n";
	}else{
		if($event[$i][2] =~ /[^A-Z]/){
			$flagerror = "true";
			print "On the line$j in the event.data the code ID $event[$i][2] is invalid\n";	
		}	
	}
	if((length($event[$i][3]) != 9)and(length($event[$i][3])!= 10)){
		$flagerror = "true";
		print "On the line$j in the event.data the event date $event[$i][3] is invalid\n";
	}
	if(length($event[$i][3]) == 9){
		if(!($event[$i][3] =~ /[0-9]{1}\/[0-9]{2}\/[0-9]{4}/)){
			$flagerror = "true";
			print "On the line$j in the event.data the event date $event[$i][3] is invalid\n";
		}
	}
	if(length($event[$i][3]) == 10){
		if(!($event[$i][3] =~ /[0-9]{2}\/[0-9]{2}\/[0-9]{4}/)){
			$flagerror = "true";
			print "On the line$j in the event.data the event date $event[$i][3] is invalid\n";
		}
	}
}

#for the format output
@Output=("Patient number", "Last name", "First name", "Birth date", "Floor	", "DNA file name", "Event ID(s)");
if($flagerror eq "true"){
		die;
	}
my $option; # save the option the user choose
print "1 patient data by patient number \n";
print "2 patient data by patient last name \n";
print "3 event data by event ID \n";
print "4 event data IDs \n";
print "5 end the program \n"; 
	chomp($option = <STDIN>);
$optionflag = "false";

while(1)
{
#after the user choose option then do the following thing 
#option 1 user input the patient number then the program return this ID's information
	if($option eq "1"){
#			$fPnum save the patient number which the user wanna to find the data	
		while($optionflag eq "false"){
			print "Enter patient number(0 to return to menu): ";
			chomp($fPnum = <STDIN>);
			$flag = "false"; #check if the patient number found
			if($fPnum == "0"){
					$optionflag = "true";
			}else{
					for($i = 0; $i < $num; $i++){
						if( $patient[ $i ][ 0 ] eq "$fPnum"){
						@Temp1 = split('/', $patient[$i][3]);
						$Date = "$Month[$Temp1[0]] $Temp1[1],$Temp1[2]";

               			        	for( $j = 0; $j < 3; $j ++ ){
      				                          print "$Output[$j]	$patient[ $i ][ $j ]\n";
                       				}
						print "$Output[3]	$Date\n";
						for($y = 4; $y < 6; $y++){
							print "$Output[$y]	$patient[$i][$y]\n";
						}	
					
						for ($x = 0; $x < $num1; $x++){
							if($event[$x][1] eq "$fPnum"){
								print "$Output[6]	$event[$x][0]\n";
							}
						}	
						$flag = "true";
							}
						}
				
				if($flag eq "false"){
						print "Patient number $fPnum not found \n";
					}
			}
		}	
	}
	elsif($option eq "2"){
#option2 when user input the patient name and the program return that patient's information
#			$fPname find patient name
		while($optionflag eq "false"){
			print  "Enter patient last name (0 to return to menu): ";
			chomp($fPname = <STDIN>);
			
			$fPname = lc($fPname);
			
			$fPname = ucfirst($fPname); 
			if($fPname eq "0"){
					$optionflag = "true";
				}else{
						$flag = "false"; #check if the patient number found
						for($i = 0; $i < $num; $i++){
							if( $patient[ $i ][ 1 ] eq "$fPname"){
								@Temp1 = split('/', $patient[$i][3]);
								$Date = "$Month[$Temp1[0]] $Temp1[1],$Temp1[2]";
                	
                        for( $j = 0; $j < 3; $j ++ ){
                                print "$Output[$j]	$patient[ $i ][ $j ]\n";
            	            }
							print "$Output[3]	$Date\n";
							for($y = 4; $y < 6; $y++){
								print "$Output[$y]	$patient[$i][$y]\n";
							}	
								for ($x = 0; $x < $num1; $x++){
										if($event[$x][1] eq "$fPname"){
												print "$Output[6]	$event[$x][1]\n";
										}
								}	
								print "\n";
								$flag = "true";
							}
						}
					}
				if($flag eq "false"){
					print "\nNo such patient in the data \n";
				}						
			}
	}	
	elsif($option eq "3"){
#option 3 when user input the event ID and the program return that ID's information	
		@Data1=("Event ID", "Patient number", "Code ID", "Event date");
#$fEid find patient name
		while($optionflag eq "false"){
			print "Enter event ID (0 to return to menu): ";
			chomp($fEid = <STDIN>);
			$fEid = uc($fEid);
			$flag = "false";
			if($fEid eq "0"){
					$optionflag = "true";
			}else{
					for($i = 0; $i < $num1; $i++){
						
							if($event[$i][0] eq "$fEid"){
								for ($j = 0; $j < 3; $j++){
									print "$Data1[$j]	$event[$i][$j]\n";	
								}	
								@Temp1 = split('/', $event[$i][3]);
								$Date = "$Month[$Temp1[0]] $Temp1[1],$Temp1[2]";
								print "$Data1[3]	$Date\n";
								$flag = "true";
							}
						}
					}
				if($flag eq "false"){
					print "The event ID: $fEid didn't find in the data \n";
				}						
			}
	}	
	elsif($option eq "4"){
#option 4 when user input some letters then the program will output the following 5 IDs by sorted
#			$fEid find patient name
		while($optionflag eq "false"){
			@Tempdata = ();
			my $fE = "";
			print "Enter event ID (0 to return to menu): ";
			chomp($fE = <STDIN>);
			$fE = uc($fE);
			@TempD = ();
			for($w = 0; $w < $num1; $w++){
				$TempD[$w] =uc($event[$w][0]);
			}
			@sorted = sort {($da = uc $a)=~ s/[\W_]+//g;
					($db = uc $b)=~ s/[\W_]+//g;
					$da cmp $db;
					}@TempD;
			
					
			$index = -1;		
			if($fE eq "0"){
					$optionflag = "true";
			}else{
					$y = 0;
					$flag = "false";
					for($i = 0; $i < $num1; $i++){
						
							if($sorted[$i] gt $fE){
								$index = $i;
								$flag = "true";
								
								last;
							}
					}
					if($index >= 0){
						$lines = $index + 5;
						if($lines > 9){
							$lines = 9;
						}
					
				
						for($i = $index; $i < $lines; $i++){
							
							print "$sorted[$i]\n";
						}
					}
												
					
			}
			if($flag eq "false"){
				print "\nThe event ID: $fE didn't find in the data \n";
			}						
		}	
	}
	elsif($option eq "5"){
#option 5  exit the program
			exit;
	}
		else{
				print "Invalid option enterd. Please enter a valid option. \n";
				$optionflag = "true";
			}
		if($optionflag eq "true")
		{
			$optionflag = "false";
			print "1 patient data by patient number\n";
			print "2 patient data by patient last name\n";
			print "3 event data by event ID \n";
			print "4 event data IDs \n";
			print "5 end the program \n" ;
		}
		chomp($option = <STDIN>);
}
