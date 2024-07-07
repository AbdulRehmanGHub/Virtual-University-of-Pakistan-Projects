/* Abdul Rehman
   BC220424444	*/
#include<stdio.h>

#define PAGE_SIZE 1024
#define PHYSICAL_MEMORY_SIZE 4096

void simulate_memory_access(int page_number){
	static int physical_memory[PHYSICAL_MEMORY_SIZE / PAGE_SIZE] = {0};
	static int page_table[PHYSICAL_MEMORY_SIZE / PAGE_SIZE] = {0};

	if (page_table[page_number] == 0){
		printf("Page %d is not in physical memory. Page fault: \nPage %d loaded into physical memory. \n", page_number, page_number);
		page_table[page_number] = 1;
	}else{
		printf("Page %d is already in physical memory. \n", page_number);
	}
}

int main(){
	simulate_memory_access(0);
	simulate_memory_access(1);
	simulate_memory_access(2);
	simulate_memory_access(0);
	simulate_memory_access(3);
	simulate_memory_access(1);
	simulate_memory_access(2);
	simulate_memory_access(4);
	simulate_memory_access(8);
	simulate_memory_access(3);
	simulate_memory_access(2);
	simulate_memory_access(1);
	simulate_memory_access(4);

	return 0;
}
