//Just Drive

#include<stdio.h>
#define N 3
struct car {
    char name[30];
    float cost;
    int seats;
    float mileage;
    char colour[30];
    char transmission[20];
}c[N];

void read() {
    
    for(int i=0; i < N; i++)
    {
        
        printf("\n\nEnter details for car # %d :- \n", i+1);
        
        printf("\nName : ");
        gets(c[i].name);
        
        printf("\nNumber of seats : ");
        scanf("%d",&c[i].seats);
        getchar();
        
        printf("\nColour : ");
        gets(c[i].colour);
        
        printf("\nMileage (kmpl) : ");
        scanf("%f",&c[i].mileage);
        getchar();
        
        printf("\nMode of Transmission : ");
        gets(c[i].transmission);
        
        printf("\nCost (Lakh) : ");
        scanf("%f",&c[i].cost);
        getchar();
    }
}

void display() {
    
    printf("\n%28s\t%16s\t%12s\t%20s\t%16s\t%12s\n","Name","No. of seats","Colour","Mileage (kmpl)","Transmission","Cost (Lakh)");
    
    for(int i=0; i < N; i++)
        printf("\n%28s\t%16d\t%12s\t%20.2f\t%16s\t%12.2f\n",c[i].name,c[i].seats,c[i].colour,c[i].mileage,c[i].transmission,c[i].cost);
    
}

int partitionMileage(int p, int r){
    float temp;
    struct car t;
    temp = c[r].mileage;
    int i = p-1;
    
    for(int j = p; j <= r-1; j++){
        if(c[j].mileage >= temp){
            i += 1;
            
            //exchange c[i] with c[j]
            t = c[i];
            c[i] = c[j];
            c[j] = t;
        }
    }
    
    //exchange c[i+1] with c[r]
    t = c[i+1];
    c[i+1] = c[r];
    c[r] = t;
    return i+1;
}

void sortMileage(int p,int r){
    int q;
    if(p < r){
        q = partitionMileage(p,r);
        sortMileage(p,q-1);
        sortMileage(q+1,r);
    }
}

int partitionCost(int p, int r){
    float temp;
    struct car t;
    temp = c[r].cost;
    int i = p-1;
    
    for(int j = p; j <= r-1; j++){
        if(c[j].cost <= temp){
            i += 1;
            
            //exchange c[i] with c[j]
            t = c[i];
            c[i] = c[j];
            c[j] = t;
        }
    }
    
    //exchange c[i+1] with c[r]
    t = c[i+1];
    c[i+1] = c[r];
    c[r] = t;
    return i+1;
}

void sortCost(int p,int r){
    int q;
    if(p < r){
        q = partitionCost(p,r);
        sortCost(p,q-1);
        sortCost(q+1,r);
    }
}

void main()
{
    int ch;
    read();
    display();
    
    do{
        
        printf("\n\nMenu :- \n\n1.Sort according to Mileage (Highest First) \n2.Sort according to Cost (Lowest First) \n3.Exit \n\nEnter choice : ");
        scanf("%d",&ch);
        
        switch(ch) {
            case 1:
                sortMileage(0,N-1);
                display();
                break;
                
            case 2:
                sortCost(0,N-1);
                display();
                break;
                
            case 3:
                break;
                
            default:
                printf("\nInvalid Choice.");
        }
    }while(ch != 3);
}

/*Output:-
 
 Enter details for car # 1 :-
 
 Name : Honda City A Class
 
 Number of seats : 4
 
 Colour : Chilli Red
 
 Mileage (kmpl) : 34.6
 
 Mode of Transmission : Manual
 
 Cost (Lakh) : 3.2
 
 
 Enter details for car # 2 :-
 
 Name : Hyundai Verna Diesel
 
 Number of seats : 7
 
 Colour : Matte Black
 
 Mileage (kmpl) : 23.8
 
 Mode of Transmission : Automatic
 
 Cost (Lakh) : 8.99
 
 
 Enter details for car # 3 :-
 
 Name : Maruti 800
 
 Number of seats : 4
 
 Colour : Gold
 
 Mileage (kmpl) : 45.7
 
 Mode of Transmission : Manual
 
 Cost (Lakh) : 2.12
 
 Name	    No. of seats	      Colour	      Mileage (kmpl)	    Transmission	 Cost (Lakh)
 
 Honda City A Class	               4	  Chilli Red	               34.60	          Manual	        3.20
 
 Hyundai Verna Diesel	               7	 Matte Black	               23.80	       Automatic	        8.99
 
 Maruti 800	               4	        Gold	               45.70	          Manual	        2.12
 
 
 Menu :-
 
 1.Sort according to Mileage (Highest First)
 2.Sort according to Cost (Lowest First)
 3.Exit
 
 Enter choice : 1
 
 Name	    No. of seats	      Colour	      Mileage (kmpl)	    Transmission	 Cost (Lakh)
 
 Maruti 800	               4	        Gold	               45.70	          Manual	        2.12
 
 Honda City A Class	               4	  Chilli Red	               34.60	          Manual	        3.20
 
 Hyundai Verna Diesel	               7	 Matte Black	               23.80	       Automatic	        8.99
 
 
 Menu :-
 
 1.Sort according to Mileage (Highest First)
 2.Sort according to Cost (Lowest First)
 3.Exit
 
 Enter choice : 2
 
 Name	    No. of seats	      Colour	      Mileage (kmpl)	    Transmission	 Cost (Lakh)
 
 Maruti 800	               4	        Gold	               45.70	          Manual	        2.12
 
 Honda City A Class	               4	  Chilli Red	               34.60	          Manual	        3.20
 
 Hyundai Verna Diesel	               7	 Matte Black	               23.80	       Automatic	        8.99
 */
