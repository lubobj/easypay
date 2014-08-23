#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#include "shmctl.h"

void* pShmAddr = NULL;

void* shm_attach()
{	
	int size = 0;
	int shmid = -1;

	if( pShmAddr == NULL )
	{
	
		size = sizeof(IMSIITEM);
		shmid =	shmget(	KNOWN_SHM_KEY, size, IPC_CREAT|IPC_EXCL|0x666 );
		if( shmid == -1 )
		{
			if( errno == EEXIST )
			{	
				shmid =	shmget( KNOWN_SHM_KEY, 0, 0 );
				if( shmid == -1 )
				{
					perror( "shmget error " );
					return NULL;
				}
			}
			else
			{
				perror( "shmget error " );
				return NULL;	
			}
		}
	
		pShmAddr = shmat( shmid, NULL, 0 );
		if( pShmAddr == (void*)-1 )
		{
			pShmAddr = NULL;
			perror( "shmat error ");
		}
	}
	return pShmAddr;
}

void shm_detach()
{
	if( pShmAddr != NULL )
	{
		//return 0 if success, otherwise return -1
		if( shmdt( pShmAddr ) )
		{
			perror( "shmdt error " );
		}
		pShmAddr = NULL;
	}
	return;
}

//before remove shm, must detach
void shm_remove()
{
	int size = 0;
	int shmid = -1;
	
	size = sizeof(IMSIITEM);
	shmid =	shmget(	KNOWN_SHM_KEY, size, IPC_CREAT|IPC_EXCL|0x666 );
	if( shmid == -1 )
	{
		if( errno == EEXIST )
		{	
			shmid =	shmget( KNOWN_SHM_KEY, 0, 0 );
			if( shmid == -1 )
			{
				perror( "shmget error " );
				return;
			}
		}
		else
		{
			perror( "shmget error " );
			return;	
		}
	}

	//return 0 if success, otherwise return -1
	if( shmctl( shmid, IPC_RMID, NULL ) )
	{
		perror( "shmctl(IPC_RMID) error " );
	}
	return ;
}
