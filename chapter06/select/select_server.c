#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 9999
#define MAXMSG 1024

int read_from_client(int filedes){
	char buffer[MAXMSG];
	int nbytes;
	nbytes=read(filedes,buffer,MAXMSG);
	
	if(nbytes<0){
		perror("read");
		exit(1);
	}else if(nbytes==0){
		return -1;
	}else {
		fprintf(stderr,"Server:got message: %s \n",buffer);
		return 0;		
	}	
}

int main(){
	
	extern int make_socket(uint16_t port);
	int sock;
	fd_set active_fd_set,read_fd_set;
	int i;
	struct sockaddr_in clientname;
	size_t size;
	sock=make_socket(PORT);
		
	if(listen(sock,1 ) < 0){
		perror("listen");
		exit(1);
	}	
	FD_ZERO(&active_fd_set);
	FD_SET(sock,&active_fd_set);

	printf("socke fd descriptor is %d\n",sock);
	printf("fd range max is  %d\n",FD_SETSIZE);

	while(1){
		read_fd_set=active_fd_set;
		if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0){
          		perror ("select");
          		exit (EXIT_FAILURE);
        	}
		for (i = 0; i < FD_SETSIZE; ++i)
		if (FD_ISSET (i, &read_fd_set)){
		    if (i == sock){
			/* Connection request on original socket. */
			int new;
			size = sizeof(clientname);
			new = accept(sock,(struct sockaddr *)NULL,NULL);
			/*
			if (new < 0)
			  {
			    perror ("accept");
			    exit (EXIT_FAILURE);
			  }
			fprintf (stderr,
				 "Server: connect from host %s, port %hd.\n",
				 inet_ntoa (clientname.sin_addr),
				 ntohs (clientname.sin_port));
			*/
			FD_SET (new, &active_fd_set);
		      }
		    else
		      {
			/* Data arriving on an already-connected socket. */
			if (read_from_client (i) < 0)
			  {
			    close (i);
			    FD_CLR (i, &active_fd_set);
			  }
		      }
		  }
	
	}


	
	return 0;
}










