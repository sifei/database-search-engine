#!/usr/local/bin/perl
# cs216program5.cgi
# program to search with (Perl or C++)
# search method (patient by number, patient by name or event ID)
# search key

# print resulting from search program as html data tables
#
# Author: Sifei Han
# Due Date: Dec 3, 2009
#
# Introudction:
# For this program, users will use browser to execute the script cs216program5.cgi via the post method through html. Data sent as name-value pairs. Then the program will found the data and output for the user.

use strict;

# This is a header line required by HTTP. It tells the 
# browser what type of data is in the file: 
# text containing HTML tags
print "Content-type: text/html\n";  
# The HTTP protocol requires a blank line before 
# anything that will be displayed
print "\n"; 
# Start the displayed lines <html> tag is always first
print "<style>";
print "body{";
print "background: url('kentucky.jpg');";
print "background-repeat: repeat;";
print "}";
print "</style>";

print "<html>";
print "<head><title>Query Results</title>";
print "<font color = /#000000><h1><center>Query Results</center></h1></head><body><center>";

#method for formating name-value pairs for cgi script.

my $form = <STDIN>; #via post pmethod received in STDIN
$form =~ s/%(..)/sprintf("%c",hex $1)/eg;
my @pairs = split(/&/,$form);

#store values into @pairs array

my @returned;
$pairs[0] =~ s/program=//;
$pairs[1] =~ s/option=//;
$pairs[2] =~ s/searchkey=//;

print "pairs[0] $pairs[0]";
print "pairs[1] $pairs[1]";
print "pairs[2] $pairs[2]";





# if selected program is perl, execute perl program
# if selected program is c++, execute c++ program

my $newreturned;
#message informing user perl program executed to search either patient data or evnet data.

if($pairs[0] eq "perl")
{
	#print message to user telling what has been exexuted
	if($pairs[1] eq "option1" || $pairs[1] eq "option2")
	{
		print "<br><b>Patient data using Perl</b><br>";
	}else
	{
		print "<br><b>Event data using Perl</b><br>";
	}
	$newreturned = `./cs216program5.pl $pairs[1] $pairs[2]`;
}

#message informing user C++ program executed to serach either patient data or event data.
if($pairs[0] eq "cpp")
{
	#print message to user telling what has been executed
	if($pairs[1] eq "1" || $pairs[1] eq "2")
	{
		print "<br><b>Patient data using C\+\+</b><br>";
	}else
	{
		print "<br><b>Event data using C\+\+</b><br>";
	}
	$newreturned = `./cs216program5 $pairs[1] $pairs[2]`;
	
}

#return data deliminated by \n
@returned = split('\n', $newreturned);


#for the error check
if($pairs[1] eq "1"){
	my $count = 0;	
	print "<table border = 5 width = 33% bgcolor = teal style =\"color: \#000000\">"; 	
	print '<tr><td>Patient Number</td>';
	print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
		
		print '<tr><td>Last Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
	
		print '<tr><td>First Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Birth Date</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Floor</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>DNA File Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
	print "</table><br><br>";
	print "<input type=submit value=\"Display event data\">";
		
	
	print "<form name=return action=cs216program5.html>";
	print "<input type=sumbit value=\"Return to main menu\">";
	print "</form>";
}
elsif($pairs[1] eq "2"){
	my $count = 0;
	print "<table border = 5 width = 33% bgcolor = teal style =\"color: \#000000\">"; 	
	print '<tr><td>Patient Number</td>';
	print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
		print '<tr><td>Last Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
	
		print '<tr><td>First Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Birth Date</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Floor</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>DNA File Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
		while (!$returned[$count]){
		print "<table border = 5 width = 33% bgcolor = teal style =\"color: \#000000\">"; 	
	print '<tr><td>Patient Number</td>';
	print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
		
		print '<tr><td>Last Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
	
		print '<tr><td>First Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Birth Date</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Floor</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>DNA File Name</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
	print "</table><br><br>";
	print "<input type=submit value=\"Display event data\">";
	
	}
	print "</table><br><br>";
	print "<form name=return action=cs216program5.html>";
	print "<input type=sumbit value=\"Return to main menu\">";
	print "</form>";
}
else{
	my $count = 0;
	print "<table border = 5 width = 33% bgcolor = teal style =\"color: \#000000\">"; 	
	print '<tr><td>Event ID</td>';
	print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
		print '<tr><td>Patient Number</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;
	
		print '<tr><td>Code ID</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

		print '<tr><td>Event Date</td>';
		print '<td>';
		print "$returned[$count]";
		print '</td></tr>';
		$count++;

	print "</table><br><br>";
	print "<form name=return action=cs216program5.html>";
	print "<input type=sumbit value=\"Return to main menu\">";
	print "</form>";
}
#end html formatting
print '<br></font></center></body></html>';




