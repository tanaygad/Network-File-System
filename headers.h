#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h> 
#include <sys/stat.h> // For stat
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>



#include "common.h"
#include "commstruct.h"
#include "hashtable.h"
#include "storage_server.h"
#include "naming_server.h"

StorageServerNode* add_storage_server(char* ip, int nm_port, int client_port, char* path) ;

#endif