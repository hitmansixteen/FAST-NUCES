/*
        TCP_Server. This Program will will create the Server side for TCP_Socket Programming.
        It will receive the data from the client and then send the same data back to client.
*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> //socket
#include <arpa/inet.h> //inet_addr
#include <pthread.h>


struct thread_struct
{
        int tid;        
};

struct candidates{
	char *name;
	char *flag;
};

struct voters{
	char *name;
	char *cnic;
};

struct candidates candidate[5];
struct voters voter[15];
void parseCandidates(){
	FILE *fp = fopen("Candidates_List.txt","r");
	char buffer[2000];
	char buff[2000];
	while(fgets(buffer,2000,fp)){
		strcat(buff,buffer);
	}
	char *token = strtok(buff,",\n");
	int i=0;	
	while(token!=NULL){
		candidate[i].name=token;
		token = strtok(NULL,",\n");
		candidate[i].flag=token;
		token = strtok(NULL,",\n");
		i++;
	}

	for(i=0;i<5;i++){
		printf("%s %s\n",candidate[i].name,candidate[i].flag);
	}
	
	fclose(fp);
	
}
void parseVoters(){
	FILE *fp = fopen("Voters_List.txt","r");
	char buffer[2000];
	char buff[2000];
	while(fgets(buffer,2000,fp)){
		strcat(buff,buffer);
	}
	char *token = strtok(buff,"/\n");
	int i=0;	
	while(token!=NULL){
		voter[i].name=token;
		token = strtok(NULL,"/\n");
		voter[i].cnic=token;
		token = strtok(NULL,"/\n");
		i++;
	}
	for(i=0;i<5;i++){
		printf("%s %s\n",voter[i].name,voter[i].cnic);
	}
	fclose(fp);
}

void *print_thread_id (void *arg)
{
		char server_message[2000], client_message[2000];
		struct thread_struct *t = (struct thread_struct*)arg;
		int client_sock = t->tid; 
		memset(server_message,'\0',2000);
		memset(client_message,'\0',2000);
		
		    
		    //Receive the message from the client
		    
		    if (recv(client_sock, client_message, sizeof(client_message),0) < 0)
		    {
		            printf("Receive Failed. Error!!!!!\n");
		            return;
		    }
		    
		    printf("Client Message: %s\n",client_message);
		    
		    //Send the message back to client
		    
		    
		    strcpy(server_message, "Here are a list of candidates with their sign\n");
		    int i;
		    for(i=0;i<5;i++){
		printf("%s %s\n",candidate[i].name,candidate[i].flag);
	}
		    for(i=0;i<5;i++){
		    	strcat(server_message, candidate[i].name);
		    	strcat(server_message, " ");
		    	strcat(server_message, candidate[i].flag);
		    	strcat(server_message, "\n");
		    }
		    strcat(server_message,"Enter your client\n");
		    
		    if (send(client_sock, server_message, strlen(server_message),0)<0)
		    {
		            printf("Send Failed. Error!!!!!\n");
		            return;
		    }
		    
		    memset(server_message,'\0',2000);
		    memset(client_message,'\0',2000);
        
        pthread_exit(NULL);       
}

int main(void)
{
        int socket_desc, client_sock, client_size; 
        struct sockaddr_in server_addr, client_addr;         //SERVER ADDR will have all the server address
        char server_message[2000], client_message[2000];                 // Sending values from the server and receive from the server we need this
        
        parseCandidates();
        parseVoters();

        //Cleaning the Buffers
        
        memset(server_message,'\0',sizeof(server_message));
        memset(client_message,'\0',sizeof(client_message));     // Set all bits of the padding field//
        
        //Creating Socket
        
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        
        if(socket_desc < 0)
        {
                printf("Could Not Create Socket. Error!!!!!\n");
                return -1;
        }
        
        printf("Socket Created\n");
        
        //Binding IP and Port to socket
        
        server_addr.sin_family = AF_INET;               /* Address family = Internet */
        server_addr.sin_port = htons(2000);               // Set port number, using htons function to use proper byte order */
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");    /* Set IP address to localhost */
		
		
		
		// BINDING FUNCTION
        
        if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0)    // Bind the address struct to the socket.  /
	                            	//bind() passes file descriptor, the address structure,and the length of the address structure
        {
                printf("Bind Failed. Error!!!!!\n");
                return -1;
        }        
        
        printf("Bind Done\n");
        
        //Put the socket into Listening State
        
        if(listen(socket_desc, 1) < 0)                               //This listen() call tells the socket to listen to the incoming connections.
     // The listen() function places all incoming connection into a "backlog queue" until accept() call accepts the connection.
        {
                printf("Listening Failed. Error!!!!!\n");
                return -1;
        }
        
        printf("Listening for Incoming Connections.....\n");
        
        //Accept the incoming Connections
        while(1){
        struct thread_struct thread_st;
		    client_size = sizeof(client_addr);
		
		
		
		    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);          // heree particular client k liye new socket create kr rhaa ha
		    
		    if (client_sock < 0)
		    {
		            printf("Accept Failed. Error!!!!!!\n");
		            return -1;
		    }
		    
		    pthread_t thread1;
		    thread_st.tid = client_sock;
		    pthread_create(&thread1, NULL, print_thread_id, (void*)&thread_st);
		    
		    int i;
		    for(i=0;i<5;i++){
				printf("%s %s\n",voter[i].name,voter[i].cnic);
			}
		    
             
        //Closing the Socket
        
        }
        close(client_sock);
        close(socket_desc);
        return 0;       
}
