hw2:
map_cp does not support file holes, please write a program called mmap_cp2, mmap_cp2 can skip file holes and only copy the part of the file that has real content


hw5:
Write a program, the program name is preBirthday, whoever executes this file can know the sum of the logical size of all regular files in any directory. For example, executing "preBirthday/" will count all the files under the root directory. In addition, preBirthday will list which file types are in this directory.

hw6:
Write a program called myBusybox, and create the following softlinks. These softlinks are connected to myBusybox. MyBusybox will use system() to perform the corresponding function according to the name of the softlink.
cp
ls
cat
chown

hw9：
Write an application name as mylogin. Whenever a user enters a name, mylogin will determine whether the user can enter the server or not. The basis for the judgment is whether the member is in /etc/passwd, then no need to enter password.
If you can enter the server, the login will generate a child process, the child process will set the appropriate variables, and then execute "bash"
When the user leaves the shell, the prompt should be popped out again, allowing the user to log in again

hw13：
Please refer to the writing method of pipe4-3, design the application "fileCount /YYY" so that your application can automatically execute "ls -R /YYY | wc -l" to calculate the approximate number of characters in the /YYY directory
Please make sure that after your main program "fileCount" receives ctr+c, "ls -R /YYY | wc -l" can be stopped immediately
