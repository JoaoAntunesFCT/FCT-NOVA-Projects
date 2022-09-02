##########################################################
#########   AED 2021-2022 Generic Makefile   #############
##########################################################

##########################################################

## This section defines the necessary variables.

# Name of the GCC executable
CC=gcc

# Add C math.h library
LDFLAGS = -lm 

# The first argument ("-I.") will tell the compiler to look for include files in the current directory.
# The second tells the compiler to show all warnings.
CFLAGS=-I. -Wall

# Collect all .c files in the current directory
SOURCES = $(wildcard *.c)

# Create the list of object files (.o) to be generated. 
# This is accomplished by replacing .c by .o in the names of the files found in the previous step
OBJECTS = $(SOURCES:.c=.o)

##########################################################

## This section defines the compiling rules.

# Main program compiling rule.
main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Rule to clean all the generated files.
.PHONY: clean
clean:
	rm -f $(OBJECTS) main

##########################################################