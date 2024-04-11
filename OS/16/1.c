#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BLOCKS 1000
int bit_vector[MAX_BLOCKS];
void initialize(int n) {
 srand(time(NULL)); // Seed the random number generator with the current time
 for (int i = 0; i < n; i++) {
 if (rand() % 2 == 0) {
 bit_vector[i] = 1; // Mark block as allocated
 } else {
 bit_vector[i] = 0; // Mark block as free
 }
 }
}
void show_bit_vector(int n) {
 printf("Block Number\tStatus\n");
 for (int i = 0; i < n; i++) {
 printf("%d\t\t", i);
 if (bit_vector[i] == 1) {
 printf("Allocated\n");
 } else {
 printf("Free\n");
 }
 }
}
void create_new_file(int n) {
 int start_block, num_blocks;
 printf("Enter the starting block number: ");
 scanf("%d", &start_block);
 printf("Enter the number of blocks needed: ");
 scanf("%d", &num_blocks);
 int i;
 for (i = start_block; i < start_block + num_blocks; i++) {
 if (i >= n || bit_vector[i] == 1) {
 printf("Error: Cannot allocate file in the specified blocks.\n");
 break;
 }
 }
 if (i == start_block + num_blocks) {
 printf("File created successfully.\n");
 for (i = start_block; i < start_block + num_blocks; i++) {
 bit_vector[i] = 1; // Mark blocks as allocated
 }
 }
}
void show_directory(int n) {
 printf("File Name\tStarting Block\tNumber of Blocks\n");
 // TODO: Implement directory functionality here
}
int main() {
 int n, choice;
 printf("Enter the number of blocks in the disk: ");
 scanf("%d", &n);
 initialize(n);
 do {
 printf("\nMenu:\n");
 printf("1. Show Bit Vector\n");
 printf("2. Create New File\n");
 printf("3. Show Directory\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 show_bit_vector(n);
 break;
 case 2:
 create_new_file(n);
 break;
 case 3:
 show_directory(n);
 break;
 case 4:
 printf("Exiting...\n");
 break;
 default:
 printf("Error: Invalid choice.\n");
 break;
 }
 } while (choice != 4);
 return 0;
}