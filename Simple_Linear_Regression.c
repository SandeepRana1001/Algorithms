#include<stdio.h>
#include<conio.h>
#include<math.h>

//All Function Declaration Here

void getUserValues(int);
void applyAll();
void meanCalculations(int);
void otherCalculations(int);
void getModalReady();
void showRegressionLine();
void validateModel(int);
// Structure For User Variable

struct User{
	
	float x[100],y[100];
	float meanX , meanY;
	float meanCoordX,meanCoordY;
	float xSubMeanX , ySubMeanY , squareOfxSubMeanX , squareOfySubMeanY , product ;
	//     x-x bar      y-y bar  , (x-xbar)*(x-xbar) ,(y - ybar*y-ybar)  , (x-xbar)(y-ybar)
	
	float b1,b0;
	//For equation y cap = b0 + b1x
	
	float yCap[100]; 
	// Value Of y^

}u1;

main()
{
	int n=0,choice=0;

	printf("\n\n\t\t Enter Total Number Of Values : ");
	scanf("%d", & n );
	
	// Getting User Values

	getUserValues(n);
	
	// Mean Calcutations
	
	meanCalculations(n);

	otherCalculations(n);
	
	getModalReady(n);

		showRegressionLine();
		printf(" \n\n\t\t\t -*-*-*-*-*-*- BONUS -*-*-*-*-*-*-");
		printf("\n\n\t\t  -*-*-*-*-*-*- VALIDATE MODEL USING STANDARD ERROR  -*-*-*-*-*-*-");
		printf("\n\n\t\t Press 1 To Continue and 0 To Quit : ");
		scanf("%d", & choice);
		if(choice==1)
		{
			applyAll();
			validateModel(n);			
			showRegressionLine();
		}
		else
		{
			showRegressionLine();
			system("exit");
		}

}
// Getting User Values
void getUserValues(int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("\n\n\t\t Enter Value %d  Of X : ", i+1);
		scanf("%f", & u1.x[i]);
		
		printf("\n\n\t\t Enter Value %d  Of Y : ", i+1);
		scanf("%f", & u1.y[i]);
		
		applyAll();		
	}
	
		printf("\n\n\t\t Enter Mean Coordinate Of X : ");
		scanf("%f", & u1.meanCoordX);
		
		printf("\n\n\t\t Enter Mean Coordinate Of Y : ");
		scanf("%f", & u1.meanCoordY);

		applyAll();		
	
}

// Calculations and Means and Other Stuff
void meanCalculations(int n)
{
		int i=0;
		float temp=0.0,totX=0.0,totY=0.0;

		for(i=0;i<n;i++)
		{
			totX = u1.x[i]+totX;

			totY = u1.y[i]+totY;
		}
		
		u1.meanX=totX/n;
		u1.meanY=totY/n;	
		
}


//Other Calculations
void otherCalculations(int n)
{
	int i=0;
	float tempX=0.0,tempY=0.0,temp=0.0;
		
		u1.product=0;
		u1.squareOfxSubMeanX=0;

		for(i=0;i<n;i++)
		{
			temp = (u1.x[i] - u1.meanX) * (u1.y[i] - u1.meanY); //(x-xbar)(y-ybar)			
			u1.product = u1.product + temp;

			temp = (u1.x[i] - u1.meanX) * (u1.x[i] - u1.meanX); //(x-xbar)(x-xbar)  
			u1.squareOfxSubMeanX = u1.squareOfxSubMeanX + temp;		
		}
		
}

// Get Modal Ready
void getModalReady()
{
	// Finding b1 in equation ycap = b0 + b1x	
	
	// Formulae Of B1 = Sigma (x-xbar)(y-ybar) / sigma SquareOf[(x-xbar)]
	u1.b1 = u1.product/ u1.squareOfxSubMeanX;
	
	// Using value of b1 and mean coordinate given by user to give the modal equation
	//Using equation y cap = b0 + b1x we find b0
	
	u1.b0 = u1.meanCoordY - (u1.b1 * u1.meanCoordX);
	
		
}

// Showing Regression Line

void showRegressionLine()
{
	printf("\n\n\t\t Regression Line Is y^ = %f + %f x",u1.b0,u1.b1);	
}

// Validate Model
void validateModel(int n)
{
	//Predicting Y Cap Values By Assigning Values Of X Given By User In Regression Line Equation
	
	int i=0;
	
	float yCapSubY[100],squareyCapSubY[100],error=0.0,totalSquareDistance=0.0;
	
	for(i=0;i<n;i++)
	{
		u1.yCap[i] = u1.b0 + (u1.b1 * u1.x[i]); // y^ = b0 + b1x
	}
	
	// Calculating Difference using  y^ - y
	
	for(i=0;i<n;i++)
	{
		yCapSubY[i] = u1.yCap[i] - u1.y[i];

		// Squaring The Difference To Remove Negative Values
		
		squareyCapSubY[i] = yCapSubY[i]*yCapSubY[i];
		
		// Adding All Squared Values
		
		totalSquareDistance = totalSquareDistance + squareyCapSubY[i];
	}
	
	// Using Formulae Of Standard Error
	// SquareRoot[Sigma {Square(y^ - y)} / Square{No. Of Entries or Observation}]
	
	error = sqrt((totalSquareDistance)/(n*n));

	printf("\n\n\t\t Standard Error Is %f",error);
	
	if(error>1.0)
	{
		printf("\n\n\t\t Something Is Wrong With Your Model. Please Try Again");
	}	
	
	else
	{
		printf("\n\n\t\t The Model Is Working Perfectly");
	}
	
	
	
}
// Using This Function EveryWhere To Clear Screens
void applyAll()
{
	printf("\n\n\t\t Press Any Key To Continue : ");
	getch();
	system("cls");
}
