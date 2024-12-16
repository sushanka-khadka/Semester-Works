// Program to implement Clock page replacement algorithm
#include <stdio.h> 
 
int main() { 
    int frameCount, referenceCount, faults = 0, i, j, k = 0; 
    printf("*****Clock Page Replacement*****\n");
	printf("Enter number of frames: "); 
    scanf("%d", &frameCount); 
    int frame[frameCount]; 
    for (i = 0; i < frameCount; i++) { 
        frame[i] = -1; 
    } 
    printf("Enter number of pages: "); 
    scanf("%d", &referenceCount); 
    int reference[referenceCount], usebit[frameCount]; 
    printf("Enter reference string: "); 
    for (i = 0; i < referenceCount; i++) { 
        scanf("%d", &reference[i]); 
    } 
    printf("\n"); 
    
    printf("==========================================\n"); 
    printf("Page\t\tFrames\t\tPage Fault\n"); 
    printf("-----\t\t--------\t----------\n"); 
    for (i = 0; i < referenceCount; i++) { 
        int found = 0; 
        for (j = 0; j < frameCount; j++) { 
            if (frame[j] == reference[i]) { 
                found = 1; 
                usebit[j] = 1; 
                break;  
            } 
        } 
        if (!found) { 
            while (usebit[k] == 1) { 
                usebit[k] = 0; 
                k = (k + 1) % frameCount; 
            } 
            frame[k] = reference[i]; 
//            usebit[k] = 1; 
            k = (k + 1) % frameCount; 
            faults++; 
        } 
        printf("%d\t", i+1); 
        for (j = 0; j < frameCount; j++) { 
            if (frame[j] == -1) { 
                printf(" \t"); 
            } else { 
                printf("%d\t", frame[j]); 
            } 
        } 
        if (!found) { 
            printf("\tF"); 
        } 
        printf("\n"); 
    } 
    printf("==========================================\n"); 
    printf("\nTotal Page Faults: %d\n", faults); 
    return 0; 
} 
