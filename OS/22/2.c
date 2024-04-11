#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *bitVector;
int totalBlocks;
void initializeBitVector() {
 bitVector = (int*) malloc(totalBlocks * sizeof(int));
 for(int i = 0; i < totalBlocks; i++) {
 bitVector[i] = rand() % 2;
 }
}
void showBitVector() {
 printf("Bit Vector:\n");
 for(int i = 0; i < totalBlocks; i++) {
 printf("%d ", bitVector[i]);
 }
 printf("\n");
}
void deleteFile() {
 int startBlock, fileSize;
 printf("Enter starting block of file to be deleted: ");
 scanf("%d", &startBlock);
 printf("Enter file size: ");
 scanf("%d", &fileSize);
 if(startBlock < 0 || startBlock >= totalBlocks || startBlock + fileSize > totalBlocks) {
 printf("Invalid input\n");
 return;
 }
 for(int i = startBlock; i < startBlock + fileSize; i++) {
 if(bitVector[i] == 0) {
 printf("Error: Block %d is not allocated\n", i);
 return;
 }
 }
 for(int i = startBlock; i < startBlock + fileSize; i++) {
 bitVector[i] = 0;
 }
 printf("File deleted successfully\n");
}
int main() {
 printf("Enter total number of blocks in disk: ");
 scanf("%d", &totalBlocks);
 initializeBitVector();
 while(true) {
 printf("\nMenu:\n1. Show Bit Vector\n2. Delete File\n3. Exit\n");
 int choice;
 scanf("%d", &choice);
 switch(choice) {
 case 1:
 showBitVector();
 break;
 case 2:
 deleteFile();
 break;
 case 3:
 printf("Exiting...\n");
 return 0;
 default:
 printf("Invalid choice\n");
 }
 }
} 