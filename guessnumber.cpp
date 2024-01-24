#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	int guess=0;
	int count=0;
	srand (time(NULL));
	int num =rand()%100+1;
	do{
	
	cout<<"Guess a number between 1 and 100"<<endl;

	cin>>guess;
	if (num==guess)
	{
		cout<<"Congrats guessed  it right"<<endl;
	}
	else if (num<guess)
	{
		cout<<"Try a smaller number"<<endl;
		count++;	
		
	}
		else if (num>guess)
	{
		cout<<"Try a bigger number"<<endl;
		count++;	
	}
} while(num!=guess);
cout<<"You guessed it right after turns:"<<count;
cout<<"\nThe number was: "<<num;
	
}