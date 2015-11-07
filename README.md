## Academic Assignments

#### bitstuffing.c
* This program implements `bit stuffing` algorithm described in `Computer Networks - A top down approach` by `Behrouz Forouzan`.
* $ gcc -o bitstuffing bitstuffing.c
* ./bitstuffing [string]

#### crc.c
* This program implements `cyclic redundancy check` algorithm described in `Computer Networks - A top down approach` by `Behrouz Forouzan`
* $ gcc -o crc crc.c
* ./crc

#### createProcessTree.c
* This program creates `process tree` i.e a `binary tree of processes` by using `fork()` system call on UNIX.
* $ gcc -o processTree createProcessTree.c
* ./processTree


#### hostFromIp.c
* This program makes use of `gethostbyaddr()` function and `struct hostent` to find host address from given ip address.
* $ gcc -o hostFromIp hostFromIp.c
* ./hostFromIp [ip address]

#### listfiles.c
* This program `lists all files` in a directory and Each of its properties on UNIX os.
* It makes use of `stat` and `Dirent` structs.
* $ gcc -o listfiles listfiles.c
* $ ./listfiles [directory path]

#### mac.c
* This program finds `mac address` of a pc by using `struct ifreq` and `socket`.
* $ gcc -o mac mac.c
* $ ./mac [network interface like "eth0" or "wlan0"]


#### parity.c
* This program implements `parity encode` and `parity check` algorithm.
* $ gcc -o parity parity.c
* $ ./parity [string to encode] [options]
* options 
      * 1 odd parity
      * 0 even parity

#### pipe.c
* This program demonstrates `client server model` using `pipes` in linux.
* `Client` sends numbers to `server` , server sorts them and sends them back to client using `pipes`.
* $ gcc -o pipe pipe.c
* $ ./pipe [string to encode] [options]


### LICENSE

##### [MIT LICENSE](https://github.com/manuchandel/Academics/blob/master/LICENSE.md)
