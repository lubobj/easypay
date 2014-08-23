#include "shmctl.h"

int getImsi()
{
	void *pShm;
	pShm = (void*)shm_attach();
	IMSIITEM *pItem = (IMSIITEM*) pShm;
	return pItem->is_getimsi;
}

void setImsi(int value)
{
	void *pShm;
	pShm = (void*)shm_attach();
	IMSIITEM *pItem = (IMSIITEM*) pShm;
	pItem->is_getimsi = value;
}

void setImsiValue(char* buf, int length)
{
	void *pShm;
	pShm = (void*)shm_attach();
	IMSIITEM *pItem = (IMSIITEM*) pShm;
	memcpy(pItem->imsi_number,buf,length);
	printf("copy imsi success\n");
}

void getImsiValue(char* dest)
{
	void *pShm;
	pShm = (void*)shm_attach();
	IMSIITEM *pItem = (IMSIITEM*) pShm;
	memcpy(dest, pItem->imsi_number, sizeof(pItem->imsi_number));
	printf("getImsiValue\n");
}




