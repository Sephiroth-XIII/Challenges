Classifier (A Linux Hack)
---------------------------------------------------------------------------------------------------------------------------
Classifier is a Linux based service that will constantly monitor a user defined directory for incoming files ( Mostly extensionless and belonging to either of the four types : JPG, MP3, PNG, PDF), Classify the files correctly 
and append them with an appropriate extension and file them into individual directories defined by the user for each specific type.  


Steps to run Classifier
---------------------------------------------------------------------------------------------------------------------------
STEP 1: 

Set paths of Staging Area and All destination areas in file 'INPUT'

	Line 1: Path of STAGING DIRECTORY  						eg.		/home/chintan/Stage
	Line 2: Path of DESTINATION DIRECTORY for JPEG files  	eg.		/home/chintan/JPEG
	Line 3: Path of DESTINATION DIRECTORY for MP3 files  	eg.		/home/chintan/MP3
	Line 4: Path of DESTINATION DIRECTORY for PDF files  	eg.		/home/chintan/PDF
	Line 5: Path of DESTINATION DIRECTORY for PNG files  	eg. 	/home/chintan/PNG

STEP 2:

	$ make

STEP 3:

Make sure inotify-tools package is installed on your machine.
In UBUNTU/DEBIAN use command 'sudo apt-get install inotify-tools' to install inotify-tools.
Test it in console using 'inotifywait dir_name'.

STEP 4:

	$ ./Caller
Every file copied in the staging area from now on will be filed in the appropriate location with appropriate extension. 
