#include<stdio.h>
#include<conio.h>
#include<math.h>

// All Declaration Here
int getDataSetValues();
void applyAll();
void applyEuclideanDistanceFormulae(int,float,float);

// Setting A Structure To Contain Dataset
struct Dataset{
	
	float maths[100], computer[100];
	int result[100],k;
}d1;

main()
{	
		float x=0.0,y=0.0;
		int i=0,n;
	
		n = getDataSetValues();
	
	// Get New Student Marks Or New Query To Predict Result

	printf("\n\n\t\t Enter New Student Marks In Mathematics: ");		
	scanf("%f", & x);

	printf("\n\n\t\t Enter New Student Marks In Computer: ");		
	scanf("%f", & y);
	
	printf("\n\n\t\t Enter Value Of K : ");
	scanf("%d", & d1.k);

	applyAll();
	
	printf("\n\n\t\t\t Getting Result Status Please Wait ");
	
	for(i=0;i<3;i++)
	{
		printf(".");	
		sleep(1);
	}	
	applyAll();		
	applyEuclideanDistanceFormulae(n,x,y);
}

//	Get DataSet Values From Here

int getDataSetValues()
{
	int i=0,n=0;
	
	printf("\n\n\t\t Enter Total Number Of Entries : ");
	scanf("%d", & n);
	
	for(i=0;i<n;i++)
	{
		printf("\n\n\t\t Enter Marks In Mathematics For Student %d: ",i+1);
		scanf("%f", & d1.maths[i]);

		printf("\n\n\t\t Enter Marks In Computer For Student %d: ",i+1);
		scanf("%f", & d1.computer[i]);

		printf("\n\n\t\t Enter Result Status 1 for Pass 0 For Fail For Student %d: ",i+1);
		scanf("%d", & d1.result[i]);

			applyAll();

	}
	
	printf("\n\n\t\t -*-*-*-*-*-  Your Data Is All Set For Prediction-*-*-*-*-*- ");
	applyAll();
	return n;
}

// Predict Result Status Using Euclidean Distance Formulae

void applyEuclideanDistanceFormulae(int n,float x,float y)
{

	int i=0,j=0,l=0;
	int index[10],status[10],countP=0,countF=0;
	float res[100],tempX=0.0,tempY=0.0,temp,min[10];
	
	for(i=0;i<n;i++)
	{
		index[i]=0;
		min[i]=0;
		// SquareRoot[SquareOf{(Observed Value 1 - Actual Value 1)} + SquareOf{(Observed Value 2 - Actual Value 2)}]

		// Calculate X Values		

		tempX = x - d1.maths[i];
		tempX = tempX * tempX;
		// Calculate Y Values
		
		tempY = y - d1.computer[i];
		tempY = tempY * tempY;
		
		// Adding X and Y Values	
		tempX=tempX+tempY;
		
		// Calculating SquareRoot and Storing Result	
		res[i] = sqrt(tempX);
	}

	
	// Calutating Smallest Number From Result	
	
		temp=res[0];
		
		for(j=0;j<d1.k;j++)
		{
			for(i=1;i<n;i++)
			{
				if(index[i]==i)
				{
					
				}	
				else
				{
					if(temp>res[i])
					{
						temp=res[i];
					}
				}
				min[i-1]=temp;
			    index[i-1]=i;
			}
		}
		
			// Fetching Results of the computated data

		for(i=0;i<d1.k;i++)
		{
			int temper=index[i];
			status[i] = d1.result[temper];
	
			// If Status Is Fail Increase Fail Counter else increase pass counter	
			if(status[i]==0)
			{
				countF=countF+1;	
			}
			else
			{
				countP=countP+1;
			}
		}
		
//		Checking If Pass Counter Is Greater Or Fail Counter Is Greater and Printing Result

		if(countP>countF)
		{
			printf("\n\n\t\t New Student Result Is Pass and Status Is 1");
		}
		else
		{
			printf("\n\n\t\t New Student Result Is Fail and Status Is 0");
		}
		


}


void applyAll()
{
	printf("\n\n\t\t -*-*-*-*-*-  Press Any Key To Continue-*-*-*-*-*- ");
	getch();
	system("cls");

}

