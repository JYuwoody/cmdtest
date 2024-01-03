#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_ID_2100 0x612BB043 // 2100
#define DEVICE_ID_6900 0x612BD043 // 6900
#define DEVICE_ID_4300 0x612BC043 // 4300

typedef unsigned char    UINT8;
 typedef unsigned int   INT32U;

unsigned char *mapimage(char *image, int *fd, unsigned long *sz)
{
	FILE *fp;
	unsigned char *fbuf;

	fp = fopen (image, "r+b");
	if(fp == NULL){
		return MAP_FAILED;
	}

	// obtain file size:
	fseek(fp, 0L, SEEK_END);
	*sz = ftell(fp);
	fclose(fp);

	fbuf = MAP_FAILED;
	if(*sz) {
		*fd = open(image, O_RDWR, 0666);
		if(*fd != -1) {
			fbuf = (UINT8*)mmap(0, *sz, PROT_READ, MAP_PRIVATE, *fd, 0);
		}
	}
	return fbuf;
}

void unmapimage(unsigned char *fbuf, int fd, unsigned long sz)
{
	if(fbuf != MAP_FAILED)
		munmap(fbuf, sz);
	if(fd != -1)
		close(fd);
}

int GetbinaryDeviceId(char *ImageFile)
{
        int found = 0;
        unsigned long sz;
        unsigned char *fbuf;
        int fd;
        unsigned char *p;
        unsigned long size;
        unsigned long temp = 0;
        printf("fp_woody [%s] --- LINE %d ---\n", __func__, __LINE__);//woody

        fbuf = mapimage(ImageFile, &fd, &sz);
        printf("fp_woody [%s] --- LINE %d ---\n", __func__, __LINE__);//woody
        if(fbuf) {
                printf("fp_woody [%s] --- LINE %d ---\n", __func__, __LINE__);//woody
                size = 0;
                p = fbuf;
                while(size < sz)  {
                        if(!memcmp(p, "LCMXO3LF-4300", 13)) {
                                printf("fp_woody [%s] --- LINE %d --- temp= 0x%lx\n", __func__, __LINE__,temp);//woody
                                return DEVICE_ID_4300;			
                        }
                        if(!memcmp(p, "LCMXO3LF-6900", 13)) {
                                printf("fp_woody [%s] --- LINE %d --- temp= 0x%lx\n", __func__, __LINE__,temp);//woody
                                return DEVICE_ID_6900;			
                        }			
                        p++;
                        temp++;
                }
                unmapimage(fbuf, fd, sz);
        }

    return 0;
}

int main ()
{
        INT32U DevicID = 0x00;			//+++Woody cpld device id

        printf("fp_woody [%s] --- LINE %d ---\n", __func__, __LINE__);//woody
        DevicID = GetbinaryDeviceId("signed_4UXG_BPB_24E_G5_R101_V102_4300.jed");

        return(0);
}
