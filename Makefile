# Define the compiler and flags
CC = g++                  # Specify the compiler to be used (g++)
CFLAGS = -Wall -Iinclude -fPIC  # Compilation flags:
                               # -Wall: Enable all warnings
                               # -Iinclude: Include header files from the "include" directory
                               # -fPIC: Generate position-independent code (often used for shared libraries)
LDFLAGS = -lcurl           # Linking flags:
                           # -lcurl: Link the program with the libcurl library for HTTP requests and other network functions

# Specify source and object files
SRCS = src/main.cpp        # Define the source file(s) (main.cpp in the src directory)
OBJS = $(SRCS:.cpp=.o)     # Define the corresponding object file (.o) by replacing .cpp with .o

# Define the target executable
TARGET = main              # Name of the executable that will be created

# Default target
all: $(TARGET)             # The default target is "all," which builds the executable by depending on $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)         # $(TARGET) depends on the object files $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Command to create the executable from the object files.
                                        # It uses the compiler $(CC), the link flags $(LDFLAGS),
                                        # and links the object files to create the executable.

# Rule for compiling source files into object files
%.o: %.cpp                 # This is a generic rule to convert any .cpp file into a .o (object) file
	$(CC) $(CFLAGS) -c $< -o $@  
# Command to compile:
                            # $<: The source file (.cpp)
                            # $@: The target file (.o)
                            # $(CC): The compiler (g++)
                            # $(CFLAGS): Compilation flags (e.g., warnings, includes)
                            # -c: Compile without linking, only create the object file

# Clean up generated files
clean:                      # "clean" is a special target to remove the generated files
	rm -f $(OBJS) $(TARGET)  
# Remove the object files and the executable