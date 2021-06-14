/*
 *Question 1
 * b
 *
 * Question 2
 * b
 *
 * Question 3
 * d
 *
 * Question 4
 * swapped
 *
 * Question 5
 * TCP
 *
 * Question 6
 * Paging means the memory is divided into different equal-size pages. If we want to open note pad, note pad would
 * use a number of paged from different locations, they are not necessarily adjacent pages.
 * The page map table would help us identify where the pages for note pad are locating. This is why each process
 * needs to have a page map table.
 *
 * gowtham answer:
 * Paging is a type of memory partitioning, in which each process is divided into small fixed sized pages
 * and the main memory is divided into equal sized frames. The process's pages are stored in these frames
 * with OS allocating one frame for each page and these frames can be chosen from anywhere in the main memory
 * (non-contagious). Hence each process has a Page Map Table (PMT) in it's Process Control Block (PCB)
 * which is a vector with index as the page number and the values as their corresponding frames.
 * MMU of the CPU uses the PMT to fetch the frames for memory access. A PMT contains the frame number and
 * also other bits like present bit (to check if the page is in main memory), modify bits
 * (to check if the values in the main memory and in the secondary memory are the same), reference bit and cache.
 *
 * Question 7
 * For ULT, we can prioritize different threads based on our preference. In KLT, the preemption by OS would decide.
 * We can utilize ULT and KLT together as a light weight process. Putting several ULT together into the light process
 * container, and it is on the KLT. Then the scheduling of ULT is based on user preference and the entire light
 * weight process is based on the OS preemption.
 *
 * Put a number of ULT inside a lightweight process, choose to run that lightweight process on 1 KLT.
 *
 * We can implement a hybrid version which has both ULT and KLT.
 * This is called Light Weight Process. Here, A kernel level thread is implemented as a light weight
 * container inside which any number of user level threads (user preferred quantity) can be added.
 * In order to prioritise certain operations over others, we can create a single light weight container of KLT
 * for each of these high priority operations and inside that we can create a single ULT
 * which perform this operation. One more light weight container of KLT is created and all other non priority
 * operations can be placed here each in a single ULT.
 *
 * Question 8
 * HTTP non-persistent process means that a new connection has to be established everytime. If we are using
 * cookie for the first time, the website would create a user id for us and after that everytime we put in a request,
 * the cookie id would tag along and this can help the website identify us.
 *
 * In HTTP non-persistent connections, only one request and response can be made from a single connection.
 * Also HTTP are stateless, which means that the server would not remember any details from the previous
 * sessions with the client. HTTP cookies are required for the web server to remember the details from previous
 * sessions. In this case, when client makes the first HTTP request with login credentials to the web server,
 * the server generates a random ID for the user and saves the credentials against this ID in its backend database
 * and sends this ID back to client which it saves along with web server's host address in a file. Since its a
 * non-persistent connection, the connection is closed now. From here on, for future requests (with a new
 * connection every time) from the client, the client will also include this user ID in the request, so that the
 * server uses this ID to fetch the client's login credentials, therefore keeping it in "logged in" state in the
 * website for each connections, without having the client to send username and password credentials with each
 * request. Hence cookies are essential in non persistent connections.
 *
 * Question 9
 *
 * If 64K bytes is the window size of TCP,
 * Lets assume each packet is 1500 bits, then only ~ 43 packets can be transmitted through each window
 * RTT is the round trip value for packets to reach a destination and come back to source.
 * Propagation delay = d / s = 3000000 / 3.8*10^8 = 7.8 ms
 * If the network has transmission rate of 10 Mbps
 * Transmission time = 6.4 ms
 * Then, the TCP connection can send next window of packets only after receiving ACK from destination.
 * 1 Transmission with feedback ACK takes 1 RTT.
 * So a single RTT will take roughly take (7.8 + 6.4) * 2 ~ 30 ms
 * So in 1 RRT only 64Kb of data will be sent in 30ms.
 * So therefore only 2 MB of data is transmitted per second.
 * So every window of transmission will send only 2 MB of data per second even if
 * the transmission rate is 10 MB which results in a slow network connection from New York to El Paso, Texas
 *
 * Question 10
 * 10.1.1.0/26 NY
 * 10.1.1.64/26 LA
 *
 * Question 11
 * 10.10.1.6
 * because the longest prefix
 *
 */