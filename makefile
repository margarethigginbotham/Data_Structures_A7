#
# PROGRAM:    assignment7.cc
# PROGRAMMER: Margaret Higginbotham
# LOGON ID:   Z1793581
# DATE DUE:   April 4, 2018
#

# Complier Variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment7.exe: assignment7.cc
	g++ $(CCFLAGS) assignment7.cc -o assignment7.exe

# Pseudo-target to remove object code and executable files
clean:
	-rm assignment7.exe
