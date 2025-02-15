// #ifndef SS_H
// #define SS_H

// #include "headers.h"


// #define NM_PORT 10000
// #define NM_IP "127.0.0.1"
// #define SS_IP "192.168.0.1"
// #define CLIENT_PORT 54321 // Different for each SS
// #define BUFFER_SIZE 1024

// // void register_with_naming_server(int sock, const char* ip, int client_port, const char* paths);
// // void handle_nm_commands(int nm_sock);
// // void handle_client_requests(int client_sock);

// // Function definitions
// void findRelativePaths(const char *rootDir, const char *dirPath, char paths[BUFFER_SIZE][PATH_LENGTH], int *pathCount) {
//     DIR *dir;
//     struct dirent *entry;

//     if (!(dir = opendir(dirPath))) {
//         perror("opendir error");
//         return;
//     }

//     size_t rootLen = strlen(rootDir);

//     while ((entry = readdir(dir)) != NULL) {

//           if (entry->d_name[0] == '.') {
//             // Skip hidden files/directories
//             continue;
//         }
        
//         if (entry->d_type == DT_DIR) {
//             if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
//                 continue;

//             char newPath[PATH_LENGTH];
//             snprintf(newPath, sizeof(newPath), "%s/%s", dirPath, entry->d_name);
//             findRelativePaths(rootDir, newPath, paths, pathCount);
//         } else if (entry->d_type == DT_REG) {
//             if (entry->d_name[0] != '.' && *pathCount < BUFFER_SIZE) {
//                 char fullPath[PATH_LENGTH];
//                 snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
//                 if (strncmp(fullPath, rootDir, rootLen) == 0) {
//                     printf("$ %s\n",fullPath + rootLen);
//                     strncpy(paths[*pathCount], fullPath + rootLen, PATH_LENGTH);
//                     (*pathCount)++;
//                 } else {
//                     fprintf(stderr, "Error: Path does not match root directory.\n");
//                 }
//             } else if (*pathCount >= BUFFER_SIZE) {
//                 fprintf(stderr, "Buffer size exceeded. Unable to add more paths.\n");
//                 break;
//             }
//         }
//     }
//     closedir(dir);
// }


// void handle_nm_commands(int nm_sock) {
//     char buffer[BUFFER_SIZE];
//     ssize_t bytes_read = recv(nm_sock, buffer, sizeof(buffer) - 1, 0);
//     if (bytes_read > 0) {
//         buffer[bytes_read] = '\0'; // Null-terminate the string
//         // Example command format: "COMMAND,parameter1,parameter2,..."
//         char* command = strtok(buffer, ",");
        
//         if (strcmp(command, "CREATE") == 0) {
//             char* path = strtok(NULL, ",");
//             char* type = strtok(NULL, ",");
//             if (strcmp(type, "FILE") == 0) {
//                 create_file(path);
//             } else if (strcmp(type, "DIR") == 0) {
//                 create_directory(path);
//             }
//         } else if (strcmp(command, "DELETE") == 0) {
//             char* path = strtok(NULL, ",");
//             delete_path(path); // This function will handle both files and directories
//         } else if (strcmp(command, "COPY") == 0) {
//             char* source_ip = strtok(NULL, ",");
//             char* source_path = strtok(NULL, ",");
//             char* destination_path = strtok(NULL, ",");
//             copy_file_or_directory(source_ip, source_path, destination_path);
//         }
//         // Other commands can be added here
//     }
// }

// void handle_client_requests(int client_sock) {
//     // Implementation to handle client requests
//     char buffer[1024];
//     ssize_t bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
//     if (bytes_read > 0) {
//         buffer[bytes_read] = '\0'; // Null-terminate the string
//         // parse the buffer for requests like READ, WRITE, GET_INFO
//         // For example, if the request is READ, call a read_file function
//         char* command = strtok(buffer, ",");
//         if (strcmp(command, "READ") == 0) {
//             char* filename = strtok(NULL, ",");
//             read_file(client_sock, filename);
//         } else if (strcmp(command, "WRITE") == 0) {
//             char* filename = strtok(NULL, ",");
//             char* content = strtok(NULL, ""); // Read the rest of the buffer as content
//             write_to_file(filename, content);
//         } else if (strcmp(command, "INFO") == 0) {
//             char* filename = strtok(NULL, ",");
//             get_file_info(client_sock, filename);
//         }
//     }
// }



// #endif
// void perform_NM_Command(const char *path, const char *command)
// {
//     if (strcmp(command, "create_file") == 0)
//     {
//         // printf("path->> %s\n",path);
//         FILE *file = fopen(path, "w");
//         if (file != NULL)
//         {
//             fclose(file);
//             printf("Created file: %s\n", path);
//             // Respond back to the Naming Server indicating success or failure
//         }
//         else
//         {
//             printf("Failed to create file: %s\n", path);
//             // Respond back with failure to Naming Server
//         }
//     }
//     else if (strcmp(command, "create_directory") == 0)
//     {
//         if (mkdir(path, 0777) == 0)
//         {
//             printf("Created directory: %s\n", path);
//             // Respond back to the Naming Server indicating success or failure
//         }
//         else
//         {
//             printf("Failed to create directory: %s\n", path);
//             // Respond back with failure to Naming Server
//         }
//     }
//     else if (strcmp(command, "delete") == 0)
//     {
//         if (remove(path) == 0)
//         {
//             printf("Deleted: %s\n", path);
//             // Respond back to the Naming Server indicating success or failure
//         }
//         else
//         {
//             printf("Failed to delete: %s\n", path);
//             // Respond back with failure to Naming Server
//         }
//     }
//     // Handle other command types as needed
// }



// #endif
