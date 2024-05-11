DOS to Linux Command Converter Manual

1. Overview:
   This program allows users to convert DOS commands to equivalent Linux commands. It reads mappings from a file and executes the corresponding Linux commands.

2. Usage:
   The program accepts the following command-line arguments:
   -h, --h, -help : Display the manual.
   [DOS command]  : Convert and execute the specified DOS command.

3. Instructions:
   - To convert and execute a DOS command, simply run the program and provide the DOS command as an argument.
   - Use the "-h" option to display this manual.

4. File Requirements:
   - The program expects a file named "DosFile" containing mappings of DOS commands to Linux commands.
   - Each line in the "DosFile" should have the format: [DOS command]=[Linux command].

5. Exiting the Program:
   - To exit the program, enter "0" when prompted to enter a DOS command.

6. Example Usage:
   Suppose you have the following mapping in the "DosFile":
   dir=ls
   copy=cp

   To convert the DOS command "dir" to a Linux command, run:
   ./program dir

7. Notes:
   - Ensure that the "DosFile" contains valid mappings for the DOS commands you want to convert.
   - Use caution when executing commands, especially those involving file operations.
   - The program is provided as-is and may not handle all cases of DOS commands.
   - For more details, refer to the program documentation.

8. Contact:
   For questions or assistance, please contact [melgazar061@gmail.com].

9. Disclaimer:
   This program is provided for educational and informational purposes only. Use at your own risk.
