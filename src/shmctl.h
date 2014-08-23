#ifndef SHM_CTL_H
#define SHM_CTL_H

#define KNOWN_SHM_KEY 121121
typedef struct
{
	    char imsi_number[16];
		int gsmd_status;
		int is_getimsi;
}IMSIITEM, *PIMSIITEM;
#endif
