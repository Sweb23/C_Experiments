#!/bin/bash

# Restore the source file from the backup
cp self_deleting_backup.c self_deleting.c

# Compile the source file
gcc -o self_deleting self_deleting.c

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the executable
./self_deleting

# Check if the executable ran successfully
if [ $? -eq 0 ]; then
    echo "self_deleting ran successfully and deleted itself."
else
    echo "self_deleting encountered an error."
    exit 1
fi


# Check if the restoration was successful
if [ $? -eq 0 ]; then
    echo "Source file restored successfully."
else
    echo "Error restoring the source file."
    exit 1
fi

# Print a success message
echo "Operation completed successfully."

