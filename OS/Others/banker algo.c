#include <stdio.h> 
#include <stdlib.h> 
int main() { 
	int r, n, k, sum = 0, c = 0, x = 0, y = 0; 
	printf("*****Banker's Algorithm*****\n");
	printf("Enter the total no of processes: "); 
	scanf("%d", &n); 
	printf("Enter the total no of resources: "); 
	scanf("%d", &r); 
	
	int *total = malloc(r * sizeof(int *)); 
	int *w = malloc(r * sizeof(int *)); 
	int *s = malloc(n * sizeof(int *)); 
	int *flag = malloc(n * sizeof(int *)); 
	int all[n][r]; 
	int max[n][r]; 
	int rneed[n][r]; 
	int work[n][r];
	 
	for (int i = 0; i < n; i++) { 
		printf("\nEnter the details for process P%d\n", i); 
		printf("Enter the allocation: "); 
		for (int j = 0; j < r; j++) 
			scanf("%d", &all[i][j]); 	
		printf("Enter Max: "); 
		for (int j = 0; j < r; j++) 
			scanf("%d", &max[i][j]); 	 
		flag[i] = 0; 
	} 
	printf("\nEnter the total resources: "); 
	for (int i = 0; i < r; i++)  
		scanf("%d", &total[i]); 
	
	for (int i = 0; i < r; i++) { 
		for (int j = 0; j < n; j++) 
			sum += all[j][i]; 	
		w[i] = total[i] - sum; 
		sum = 0; 
	}  
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < r; j++) 
		rneed[i][j] = max[i][j] - all[i][j]; 		 
	} 
	for (int g = 0; g < n; g++) { 
		while (flag[g] != 1) { 
			for (int i = 0; i < n; i++) { 
				for (int j = 0; j < r; j++) { 
					if (flag[i] != 1) { 
						if (rneed[i][j] <= w[j])
							c++;
					} 
				} 
				if (c == r) { 
					s[x] = i; 
					x++; 
					k = 0; 
					while (k != r) { 
					w[k] += all[i][k]; 
					work[y][k] = w[k]; 
					k++; 
					} 
					y++; 
					flag[i] = 1; 
					c = 0; 
				} else { 
					c = 0; 
				} 
			}
		} 
	} 
	printf("\n\nThe Safe Sequence is --> "); 
	for (int i = 0; i < n; i++)
		printf("P%d ", s[i]); 	
	
	printf("\n\nProcess\t\tAllocation\tMax\t\tNeed\t\tWork\n"); 
	for (int i = 0; i < n; i++) { 
		printf("P%d\t\t", i); 
		for (int j = 0; j < r; j++) 
			printf("%d ", all[i][j]);
		printf("\t\t"); 
		for (int j = 0; j < r; j++) 
			printf("%d ", max[i][j]); 
		printf("\t\t"); 
		for(int j=0;j<r;j++)
			printf("%d ", rneed[i][j]);
		printf("\t\t"); 
		for(int j=0; j<r;j++)
			printf("%d ", work[i][j]);
		printf("\n"); 
	} 
	return 0;
}