# Problem 2

This problem comprises of checking your attendance status. This is an extension of Problem 1. Once you have sent data successfully to the server (Including your roll number and name) you must be able to retrieve data from server.
(Assume here that roll numbers are unique and no packets can be sent to the server with the roll number you have sent already! Implementing checks for duplicate data and showing user an appropriate message would be a great thing on your side.)


Following are the requirements for this part.
1. Create a UDP client and server.
2. Client sends packet of information to server (part a)
3. Server must respond with the message “LXX-XXXX Welcome Aboard!”
4. Client must again send the packet “CHECK: LXX-XXXX”
5. Server must respond “[LXX-XXXX] you have checked in already!” or “You haven’t checked in yet!” depending on the roll number.