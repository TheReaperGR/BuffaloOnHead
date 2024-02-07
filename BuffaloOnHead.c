#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MemoryOfBoards(int n,int m);

void ArrayFill(int n, int m, int buff);

void HastagShowArray(int n, int m);

int NunOpen(int i, int j);

int PlayerMoveCheck(char move[6]);

void Helper(int flag1);

int AndromikiCounter(int i, int j);

int **array,**ShowArray;
int n,m;


int main(void)
{
        srand((int) time(NULL));

        char c=1,level,move[7]={0};
        int i,j,d,x,flag1,buff;

	//char answer;
	//do
	//{
	//}while(1);

        printf("-------------------------\n");
        printf(" WELCOME TO BUFFALO GAME \n");
        printf("-------------------------\n\n");

	//do
	//{

	//printf("To start a new game press n/N \n");
	//printf("To quit game press q\Q\n");
	//scanf("%c",&answer);

	//}while((answer != 'n')||(answer != 'N')||(answer != 'q')||(answer != 'Q'));

	//if((answer != 'n')||(anser != 'N'))
	  //break;


        do
        {
          if(c==1)
          {
            printf("Please give me the size of the table nXm seperated by space \n(MINn= 5 & MAXn= 20 and MINm= 5 & MAXm = 10): ");
          }
          scanf("%d%d",&n,&m);
          c++;

          if(((n<5)||(n>20)) || ((m<5)||(m>10)))
            printf("Unvalid size!\nPlease try again: ");

	}while(((n<5)||(n>20)) || ((m<5)||(m>10)));


	do
	{
	  printf("\nChoose difficulty of game:\n 1-easy 2-medium 3-hard 4-impossible: ");
  	  scanf("%d",&d);
	}while((d!=1)&&(d!=2)&&(d!=3)&&(d!=4));
	printf("\n");

	getchar();

//	do
//	{

  	  switch (d)
	  {
            case 1:
              buff=n*m/8;
	    break;
            case 2:
              buff=n*m/7;
	    break;
            case 3:
              buff=n*m/6;
  	    break;
            default:
              buff=n*m/5;
	    break;
	  }

	  MemoryOfBoards(n,m);

	  for(i=0; i<n; i++)
            for(j=0; j<m; j++)
		ShowArray[i][j]='#';

	  ArrayFill(n,m,buff);

	  HastagShowArray(n,m);


//emfanish periexomenwn pinaka
	  for(i=0; i<n; i++)
          {
                for(j=0; j<m; j++)
                {
                  if((array[i][j]=='.')||(array[i][j]=='@'))
                        printf("%2c",array[i][j]);
		  else
			printf("%2d",array[i][j]);
                }
		printf("\n");
          }

	  level=1;

	  do
	  {
		printf("\nLevel: %d\n",level);  //level

		if(d==1)
		  printf("Difficulty: Easy\n");   //difficultys
		else if(d==2)
		  printf("Difficulty: Medium\n");
		else if(d==3)
		  printf("Difficulty: Hard\n");
		else
		  printf("Difficulty: Impossible\n");

		printf("Uncovered buffaloes: %d\n",buff); //buffaloes remaining

		for(i=0; i<6; i++)
                   move[i]=0;

		//getchar();

		do
		{
		  printf("Make your move: ");
		  fgets(move, sizeof(move), stdin);

		  printf("\n\n");

		  if((move[0]=='s')||(move[0]=='S'))
		  {
			if(move[1]==' ')
			{
				if((move[2]>=1)&&(move[2]<=n))
					if(move[3]==',')
						if((move[4]>=1)&&(move[2]<=m))
							if(move[5]=='\n')
							{
						//  	  getchar();
						  	  move[5]='\0';
						  	  break;
						        }
			}
		  }
		  else if((move[0]=='b')||(move[0]=='B')&&(move[1]==' ')&&(move[2]>=1)&&(move[2]<=n)&&(move[3]==',')&&(move[4]>=1)&&(move[2]<=m)&&(move[5]=='\n'))
		  {
			if(move[1]==' ')
				if((move[2]>=1)&&(move[2]<=n))
					if(move[3]==',')
						if((move[4]>=1)&&(move[2]<=m))
							if(move[5]=='\n')
							{
							  move[5]='\0';
							  break;
							}
		  }
		  else if((move[0]=='h')||(move[0]=='H')||(move[0]=='w')||(move[0]=='W')||(move[0]=='x')||(move[0]=='X'))
		  {
			if((move[1]=='\n')&&(move[2]==0)&&(move[3]==0)&&(move[4]==0)&&(move[5]==0)&&(move[6]==0))
			{
				move[1]='\0';
				break;
			}
		  }
		  else
		  {
			printf("Unvalid move!\n");
			for(i=0; i<6; i++)
			  move[i]=0;

			continue;
		  }
			printf("\n%s",move);
			break;
		}while(1);

		i=move[2]-49;
		j=move[4]-49;

		flag1=PlayerMoveCheck(move);

		if(flag1==6)
		{
         	   //goto end;
         	   printf("Game Over!");
         	   return 0;

        	}
		else if(flag1==7)
		{
         	   do
		   {
         		printf("Wrong Cordinates!!\n Input cordinates: ");
         		scanf("%c",&move[2]);
         		scanf("%c",&move[4]);

		   }while(flag1==7);
		}
//		else if(flag1=8)
//		{
//       	 	}


	  }while(1);



//free ths dezmeumenhs mnhmhs twn 2 array

	//main array
	  for(i=0; i<n; i++)
	  {
	    free(array[i]);
	  }
	  printf("\nbuff = %d\n",buff);

	  free(array);

	//ShowArray
	  for(i=0; i<n; i++)
          {
            free(ShowArray[i]);
          }
          printf("\nbuff = %d\n",buff);

          free(ShowArray);

//	}while();

   return 0;
}




void MemoryOfBoards(int n,int m)
{
	int i;

//malloc for the main array of game
	array=(int **)malloc(n*sizeof(int*));
        if(array==NULL)
        {
          printf("\nERROR in memory allocation for the table!");
          exit(1);
        }

	for(i=0; i<n; i++)
	{
          array[i]=(int*)malloc(m*sizeof(int));
          if(array[i]==NULL)
          {
	    printf("\nERROR in memory allocation for the table!");
            exit(1);
          }
	}

//malloc for the show array
	ShowArray=(int **)malloc(n*sizeof(int*));
        if(ShowArray==NULL)
        {
          printf("\nERROR in memory allocation for the table!");
          exit(1);
        }

        for(i=0; i<n; i++)
        {
          ShowArray[i]=(int*)malloc(m*sizeof(int));
          if(ShowArray[i]==NULL)
          {
            printf("\nERROR in memory allocation for the table!");
            exit(1);
          }
        }
}


void ArrayFill(int n, int m, int buff)
{

	int i,j,sn,sm;

//tuxaia arxikopoihsh boubaliwn ston pinaka
          for(i=0; i<buff; i++)
          {
                sn=rand()%n; // tuxaia 8esh nxm gia ta boubalia
                sm=rand()%m; // tuxaia 8esh nxm gia ta boubalia

                if(array[sn][sm] != '@')
                  array[sn][sm]='@';
                else
                {
                  i--;
                  continue;
                }
          }

//gemisma tou pinaka me thn timh 0(ektos apo auta pou exoun hdh boubalia) gia tis kampanes
          for(i=0; i<n; i++)
          {
                for(j=0; j<m; j++)
                {
                  if(array[i][j] != '@')
                  {
                        array[i][j]=0;
                  }
                }
          }

//gemisma pinaka me ton katalhlo ari8mo koudouniwn
          for(i=0; i<n; i++)
          {
                for(j=0; j<m; j++)
                {
                  if(array[i][j]=='@')
                  {
                        if(((i-1)>=0)&&(array[i-1][j] != '@'))
                          (array[i-1][j])++; //panw

                        if(((i+1)<n)&&(array[i+1][j] != '@'))
                          (array[i+1][j])++; //katw

                        if(((j-1)>=0)&&(array[i][j-1] != '@'))
                          (array[i][j-1])++; //aristera

                        if(((j+1)<m)&&(array[i][j+1] != '@'))
                          (array[i][j+1])++; //deksia

                        if(((i-1)>=0)&&((j+1)<m)&&(array[i-1][j+1] != '@')) //pano deksia diagwnios
                          (array[i-1][j+1])++;

                        if(((i-1)>=0)&&((j-1)>=0)&&(array[i-1][j-1] != '@')) //pano aristerh diagwnios
                          (array[i-1][j-1])++;

                        if(((i+1)<n)&&((j+1)<m)&&(array[i+1][j+1] != '@'))  //katw deksia diagwnios
                          (array[i+1][j+1])++;

                        if(((i+1)<n)&&((j-1)>=0)&&(array[i+1][j-1] != '@')) //katw aristerh diagwnios
                          (array[i+1][j-1])++;
                  }
                }
          }

//topo8ethsh ths . opou exei 0 o pinakas
          for(i=0; i<n; i++)
          {
                for(j=0; j<m; j++)
                {
                  if(array[i][j]==0)
                        array[i][j]='.';
                }
          }

}


void HastagShowArray(int n, int m)
{
	  int i,j;

//          for(i=0; i<n; i++)
//                for(j=0; j<m; j++)
//                        ShowArray[i][j]='#';


          printf("    ");

          if(m<=9)
          {
            for(i=1; i<=m; i++)
                printf("%2d",i);

            printf("\n");

            for(i=0; i<(2*m)+4; i++)
              printf("-");

            printf("\n");

            for(i=0; i<n; i++)
            {
              printf("%3d|",i+1);

              for(j=0; j<m; j++)
              {
                 printf("%2c",ShowArray[i][j]);
              }
              printf("\n");
            }
          }
          else
          {
            for(i=1; i<=9; i++)
              printf("%2d",i);

            for(i=10; i<=m; i++)
                printf("%3d",i);

            printf("\n");

            for(i=0; i<(22+((m-9)*3)); i++)
              printf("-");

            printf("\n");

            for(i=0; i<n; i++)
            {
              printf("%3d|",i+1);

              for(j=0; j<m; j++)
              {
                 if(j<=9)
                    printf("%2c",ShowArray[i][j]);

                 else
                    printf("%3c",ShowArray[i][j]);
              }
              printf("\n");
            }
          }

          printf("\n\n");
}



int NunOpen(int i, int j)
{
	int x,y;

        //oria tou board
        if(((i<0)||(i==n))||((j<0)||(j==m)))
                return 0;

        //vlepw ean to array sto i,j exei 1-8(bells)
	if(array[i][j]>=1 && array[i][j]<=8)
        {
                ShowArray[i][j]=array[i][j]+48;
                return 0;
        }

	if(ShowArray[i][j] == '.')
		return 0;

        if(array[i][j]=='.')
		ShowArray[i][j]=array[i][j];


        NunOpen(i-1,j); //panw
        NunOpen(i+1,j); //katw
        NunOpen(i,j-1); //aristera
        NunOpen(i,j+1); //deksia
        NunOpen(i-1,j+1); //panw deksia diagwnios
        NunOpen(i-1,j-1); //panw aristerh diagwnios
        NunOpen(i+1,j+1); //katw deksia diag
        NunOpen(i+1,j-1); //katw aristerh diag
}


int PlayerMoveCheck(char move[6])
{
    int x,y,flag1,r,i,j;

    x=move[2]-49;
    y=move[4]-49;

    if((move[0]=='s')|| (move[0]=='S'))
    {

      if(ShowArray[x][y] == '#')
      {
            if(array[x][y]=='@')
	    {
		for(i=0; i<n; i++)
		   for(j=0; j<m; j++)
			if(array[i][j]=='@')
                		ShowArray[i][j]=array[i][j];

		HastagShowArray(n,m);
                return 6; // return 6 = game over
            }
            else if(array[x][y]=='.')
	    {
            	r=NunOpen(x,y);
                HastagShowArray(n,m);
            }
	    else if((array[x][y]>=1) && (array[x][y]<=8))
	    {
		ShowArray[x][y]=array[x][y];
		HastagShowArray(n,m);
	    }
      }
      else
	return 7; // return 7 = na ksanadosi cords

    }
    else if(move[0]=='b'|| move[0]=='B')
    {

           if(ShowArray[x][y]=='#'){
               ShowArray[x][y]='*';
		HastagShowArray(n,m);

           }else if (ShowArray[x][y]=='*'){

               ShowArray[x][y]='#';
		HastagShowArray(n,m);

           }else{

              return 7;
           }


    }
    else if((move[0]=='x') || (move[0]=='X'))
        return 6;

    else if((move[0]=='h') || (move[0]=='H'))
    {
        flag1=1;
        Helper(flag1);
        return 8;


    }
    else if((move[0]=='w') || (move[0]=='W'))
    {
        flag1=2;
        Helper(flag1);
        return 8;

    }


}


void Helper(int flag1)
{

 int i,j,max,counter,x,y;

  if(flag1==1)
  {
	do
	{
	  i=rand()%n;
	  j=rand()%m;

	  if ((array[i][j]=='.') || ((array[i][j]>=1) && (array[i][j]<=8)))
	  {
              printf("You can goto %d %d\n\n",i+1,j+1);
	      break;
	  }

	}while(1);

  }

 max=0;
  if(flag1==2){
     for(i=0; i<n; i++){
          for(j=0; j<m; j++){
            if(array[i][j]=='.'){
               counter=AndromikiCounter(i,j);
                if(counter>max){
                    printf("max=%d",counter);
                    max=counter;
                    x=i+1;
                    y=j+1;
                }

            }
     }
     printf("The Best move is %d %d",x,y);

  }


}





int AndromikiCounter(int i, int j)
{
	int x;
  x=0;

        //oria tou board
        if(((i<0)||(i==n))||((j<0)||(j==m)))
                return 0;

        //vlepw ean to array sto i,j exei 1-8(bells)
	if(array[i][j]>=1 && array[i][j]<=8)
        {
                ShowArray[i][j]=array[i][j]+48;
                return 0;
        }

	if(ShowArray[i][j] == '.')
		return 0;

        if(array[i][j]=='.')
           x++;


        AndromikiCounter(i-1,j); //panw
        AndromikiCounter(i+1,j); //katw
        AndromikiCounter(i,j-1); //aristera
        AndromikiCounter(i,j+1); //deksia
        AndromikiCounter(i-1,j+1); //panw deksia diagwnios
        AndromikiCounter(i-1,j-1); //panw aristerh diagwnios
        AndromikiCounter(i+1,j+1); //katw deksia diag
        AndromikiCounter(i+1,j-1); //katw aristerh diag
        return x;
}



