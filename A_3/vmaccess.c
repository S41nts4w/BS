/**
 * @file vmaccess.c
 * @author Prof. Dr. Wolfgang Fohl, HAW Hamburg
 * @date 2010
 * @brief The access functions to virtual memory.
 */

#include "vmem.h"
#include "debug.h"

/*
 * static variables
 */

static struct vmem_struct *vmem = NULL; //!< Reference to virtual memory
static sem_t *local_sem; //!< OS-X Named semaphores will be stored locally due to pointer

/**
 *****************************************************************************************
 *  @brief      This function setup the connection to virtual memory.
 *              The virtual memory has to be created by mmanage.c module.
 *
 *  @return     void
 ****************************************************************************************/
static void vmem_init(void) {

	int shmid;
	key_t key = ftok(SHMKEY,SHMPROCID);

	shmid = shmget(key, SHMSIZE, 0666);

	if(shmid <0){
		perror("shmget");
		exit(1);
	}

	vmem = shmat(shmid, NULL, 0);

	if(vmem == (char*)-1){
		perror("shmat");
		exit(1);
	}

	local_sem = sem_open(NAMED_SEM, 0);

		if (local_sem < 0){
			perror("local_sem");
			exit(1);
		}

}

/**
 *****************************************************************************************
 *  @brief      This function does aging for aging page replacement algorithm.
 *              It will be called periodic based on g_count.
 *              This function must be used only when aging page replacement algorithm is activ.
 *              Otherwise update_age_reset_ref may interfere with other page replacement 
 *              alogrithms that base on PTF_REF bit.
 *
 *  @return     void
 ****************************************************************************************/
static void update_age_reset_ref(void) {
}

/**
 *****************************************************************************************
 *  @brief      This function puts a page into memory (if required).
 *              It must be called by vmem_read and vmem_write
 *
 *  @param      address The page that stores the contents of this address will be put in (if required).
 * 
 *  @return     void
 ****************************************************************************************/
static void vmem_put_page_into_mem(int address) {
}

int vmem_read(int address) {
}

void vmem_write(int address, int data) {

}

// EOF
