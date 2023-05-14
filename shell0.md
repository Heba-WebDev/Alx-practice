
/**

This code is a simple implementation of an interactive shell program. The program displays a prompt and waits for the user to enter a command. Once a command is entered, the program will attempt to execute it using the execvp function.

The main function starts by declaring several variables: command, args, token, command_len, and status. The command variable is used to store the command entered by the user, while the args array is used to store the arguments that will be passed to execvp. The token variable is used to temporarily store the result of tokenizing the command string. The command_len variable is used to store the length of the command string, and the status variable is used to store the exit status of the child process.

The program then enters an infinite loop that displays a prompt and waits for the user to enter a command. The getline function is used to read the command from standard input. If getline returns -1, indicating an error or end-of-file condition, the loop is exited.

Next, the program checks if the command entered by the user is an empty string (i.e., just a newline character). If it is, the loop continues and the prompt is displayed again.

If the command is not empty, it is tokenized using the strtok function. The first token (i.e., the command) is stored in the first element of the args array, and the second element of the array is set to NULL to indicate the end of the arguments.

The program then creates a child process using the fork function. If fork returns -1, indicating an error, an error message is printed and the program exits with a failure status. If fork returns 0, indicating that we are in the child process, execvp is called to execute the command. If execvp returns (which it should not if it was successful), an error message is printed and the child process exits with a failure status.

If we are in the parent process (i.e., fork returned a positive value), we wait for the child process to terminate using the waitpid function. Once it has terminated, we loop back to display the prompt again.

Finally, once we have exited from the loop (either because an error occurred or because end-of-file was reached), we free any memory that was allocated for storing the command string and return 0 to indicate success.

**/