
    #include <stdio.h>
    int main()
    {
       printf("Would you like to kill yourself.\n");
       printf("\v 1. Yes\n");
       printf("\v 2. No\n");
       int response;
       scanf("%d", &response);
       if (response == 1) {
          printf("GAME OVER\n");
       }     
       return 0;
    }
