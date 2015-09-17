#include <stdio.h>

#define FD_SETSIZE 256
#define	NBBY	8
typedef long	fd_mask;
#define NFDBITS	(sizeof(fd_mask) * NBBY)

#ifndef howmany
#define	howmany(x, y)	(((x)+((y)-1))/(y))
#endif

typedef	struct fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} fd_set;

#define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS)))
#define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS)))
#define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))
#define	FD_ZERO(p)	bzero((char *)(p), sizeof(*(p)))

int main(){
	fd_set p;
	printf("how many:%d\n", howmany(FD_SETSIZE, NFDBITS));
	FD_ZERO(&p);
	FD_SET( 1 ,&p);
	printf(" result: %d\n",p.fds_bits[0]);
	
	FD_SET( 2 ,&p);
	printf(" result: %d\n",p.fds_bits[0]);

	FD_SET( 3,&p);
	printf(" result: %d\n",p.fds_bits[0]);

	FD_SET( 4 ,&p);
	printf(" result: %d\n",p.fds_bits[0]);
	return 0;
}


