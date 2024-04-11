#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// function to display the bit vector
void showBitVector(int* bitVector, int n) {
 printf("Bit Vector: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", bitVector[i]);
 }
 printf("\n");
}
// function to create a new file
void createNewFile(int* bitVector, int n, int* directory) {
 int fileSize, numBlocks;
 printf("Enter the file size: ");
 scanf("%d", &fileSize);
 numBlocks = (fileSize + 511) / 512; // 512 bytes per block
 int freeBlocks[numBlocks];
 int freeBlockCount = 0;
 for (int i = 0; i < n; i++) {
 if (bitVector[i] == 0) {
 freeBlocks[freeBlockCount++] = i;
 if (freeBlockCount == numBlocks) {
 break;
 }
 }
 }
 if (freeBlockCount != numBlocks) {
 printf("Not enough free space!\n");
 return;
 }
 int fileId;
 for (fileId = 0; directory[fileId] != -1; fileId++);
 directory[fileId] = freeBlocks[0];
 for (int i = 0; i < numBlocks; i++) {
 bitVector[freeBlocks[i]] = 1;
 if (i < numBlocks - 1) {
 bitVector[freeBlocks[i]] = freeBlocks[i + 1];
 } else {
 bitVector[freeBlocks[i]] = -1;
 }
 }
 printf("File created with ID %d\n", fileId);
}
// function to display the directory
void showDirectory(int* directory) {
 printf("Directory:\n");
 for (int i = 0; directory[i] != -1; i++) {
 printf("%d: block %d\n", i, directory[i]);
 }
}
// function to delete a file
void deleteFile(int* bitVector, int* directory) {
 int fileId;
 printf("Enter the ID of the file to delete: ");
 scanf("%d", &fileId);
 if (directory[fileId] == -1) {
 printf("File not found!\n");
 return;
 }
 int blockId = directory[fileId];
 while (blockId != -1) {
 bitVector[blockId] = 0;
 blockId = bitVector[blockId + 1];
 }
 directory[fileId] = -1;
 printf("File deleted\n");
}
// main function
int main() {
 srand(time(NULL));
 int n;
 printf("Enter the number of blocks on the disk: ");
 scanf("%d", &n);
 int bitVector[n];
 for (int i = 0; i < n; i++) {
 bitVector[i] = rand() % 2; // randomly mark some blocks as allocated
 }
 int directory[n];
 for (int i = 0; i < n; i++) {
 directory[i] = -1; // initialize directory with -1 (empty)
 }
 int choice;
 do {
 printf("\n1. Show Bit Vector\n2. Create New File\n3. Show Directory\n4. Delete File\n5.Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 showBitVector(bitVector, n);
 break;
 case 2:
 createNewFile(bitVector, n, directory);
 break;
 case 3:
 showDirectory(directory);
 break;
 case 4:
 deleteFile(bitVector, directory);
 break;
 case 5:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice!\n");
 }
 } while (choice != 5);
 return 0;
}