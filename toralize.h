/*toralize.h*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>
#include <ws2tcpip.h>
/*
9050

10101100 10101100
*/

#define PROXY "127.0.0.1"
#define PROXYPORT 8000

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

// NOTE Protocol rfc (request for command)
// Socks4 rfc :: google search
// NOTE if response is 90: "request granted" else: "ERROR"

/*

NOTE:
    +----+----+----+----+----+----+----+----+----+----+....+----+
        | VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
        +----+----+----+----+----+----+----+----+----+----+....+----+
 # :	   1    1      2              4           variable       1

*/

struct proxy_request
{
    int8 vn;
    int8 cd;
    int16 dstport;
    int32 dstip;
    unsigned char userid[8];
};

/*

NOTE:
+----+----+----+----+----+----+----+----+
        | VN | CD | DSTPORT |      DSTIP        |
        +----+----+----+----+----+----+----+----+
 # :	   1    1      2              4

*/

typedef struct proxy_request req;

struct proxy_response
{
    int8 vn;
    int8 cd;
    int16 _;
    int32 ___;
};

typedef struct proxy_response res;