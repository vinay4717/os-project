#include<stdio.h> 
int main() 
{ 
	int Pr=5,Re=3;
	printf("Enter number of process and resources:	");
	scanf("%d%d",&Pr,&Re);
	const int P=Pr,R=Re;
    int avail[15];
    printf("Enter number of available resources:	");
	for(int i=0;i<R;i++)
	{
		scanf("%d",&avail[i]);
	} 
    int maxm[10][10];
    for(int i=0;i<P;i++)
	{
		printf("Enter maximum number of required resources for P%d:	",i+1);
		for(int j=0;j<R;j++)
		{
			scanf("%d",&maxm[i][j]);
		}
	}
    int allot[10][10];   
    for(int i=0;i<P;i++)
	{
		printf("Enter all the  resources allocated by P%d:	",i+1);
		for(int j=0;j<R;j++)
		{
			scanf("%d",&allot[i][j]);
		}
	}

   int need[P][R]; 
    for (int i = 0 ; i < P ; i++) 
        for (int j = 0 ; j < R ; j++) 
            need[i][j] = maxm[i][j] - allot[i][j]; 
    bool finish[P] = {0}; 
    int safeSeq[P]; 
    int work[R]; 
    for (int i = 0; i < R ; i++) 
        work[i] = avail[i]; 
    int count = 0; 
	while (count < P) 
    { 
        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            if (finish[p] == 0) 
            { 
                int j; 
                for (j = 0; j < R; j++) 
                    if (need[p][j] > work[j]) 
                        break; 
   				if (j == R) 
                { 
                
                    for (int k = 0 ; k < R ; k++) 
                        work[k] += allot[p][k]; 
                     safeSeq[count++] = p; 
                    finish[p] = 1; 
  
                    found = true; 
                } 
            } 
        } 
        if (found == false) 
        { 
            printf("System is not safe");  
        } 
    } 
    printf("System is safe \n");
    printf("Sequence is: "); 
    for (int i = 0; i < P ; i++) 
        printf("P%d___",safeSeq[i]+1);

}
