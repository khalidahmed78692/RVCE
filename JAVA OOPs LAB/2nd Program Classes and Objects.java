import java.util.Scanner;

class Address{
    int streetNo;
    String city,state,country;
    Address(int streetNo,String city,String state, String country)
    {
        this.streetNo=streetNo;
        this.state=state;
        this.city=city;
        this.country=country;
    }
}

class Student{
    String name,USN;
    Address address;
    Student(String name,String USN,Address address)
    {
        this.name=name;
        this.USN=USN;
        this.address=address;
    }
}

class College {
    String name;
    Address address;

    College(String name, Address address)
    {
        this.name=name;
        this.address=address;
    }
}

class Employee{
    String name, empID;
    Address address;
    Employee(String name, String empID, Address address)
    {
        this.name=name;
        this.empID=empID;
        this.address=address;
    }
}

public class Program2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of objects: ");
        byte nObj=sc.nextByte();
        sc.nextLine();

        Address[] address=new Address[3*nObj];
        Student[] students=new Student[nObj];
        College[] colleges=new College[nObj];
        Employee[] employees=new Employee[nObj];

        byte i;
        int streetNo;
        String name,USN,city,state,country,empID;

        for(i=0;i<nObj;i++)
        {
            System.out.println("Enter the details of student "+(i+1)+" : ");
            System.out.println("Name: ");
            name=sc.nextLine();
            System.out.println("USN: ");
            USN=sc.nextLine();
            System.out.println("Address: ");
            System.out.println("Street Number: ");
            streetNo=sc.nextInt();
            sc.nextLine();
            System.out.println("City: ");
            city=sc.nextLine();
            System.out.println("State: ");
            state=sc.nextLine();
            System.out.println("Country: ");
            country=sc.nextLine();
            address[i]=new Address(streetNo,city,state,country);
            students[i]=new Student(name,USN,address[i]);
        }

        for(i=0;i<nObj;i++)
        {
            System.out.println("Enter the details of college "+(i+1)+" : ");
            System.out.println("Name: ");
            name=sc.nextLine();
            System.out.println("Address: ");
            System.out.println("Street Number: ");
            streetNo=sc.nextInt();
            sc.nextLine();
            System.out.println("City: ");
            city=sc.nextLine();
            System.out.println("State: ");
            state=sc.nextLine();
            System.out.println("Country: ");
            country=sc.nextLine();
            address[i]=new Address(streetNo,city,state,country);
            colleges[i]=new College(name,address[i]);
        }

        for(i=0;i<nObj;i++)
        {
            System.out.println("Enter the details of Employee "+(i+1)+" : ");
            System.out.println("Name: ");
            name=sc.nextLine();
            System.out.println("Employee ID: ");
            empID=sc.nextLine();
            System.out.println("Address: ");
            System.out.println("Street Number: ");
            streetNo=sc.nextInt();
            sc.nextLine();
            System.out.println("City: ");
            city=sc.nextLine();
            System.out.println("State: ");
            state=sc.nextLine();
            System.out.println("Country: ");
            country=sc.nextLine();
            address[i]=new Address(streetNo,city,state,country);
            employees[i]=new Employee(name,empID,address[i]);
        }

        byte choice;

        Loop:while(true)
        {
            System.out.println("1:Students\t2:College\t3:Employee");
            System.out.println("Enter the corresponding number of whose you want details: ");
            choice=sc.nextByte();
            switch (choice)
            {
                case 1:
                    System.out.println("Students details are:");
                    String format="|%1$-20s|%2$-15s|%3$-40s|\n";
                    for(i=0;i<nObj;i++)
                    {
                        System.out.format(format,"Name","USN","Address");
                        System.out.format(format,students[i].name,students[i].USN,students[i].address.streetNo+","+students[i].address.city+","+students[i].address.state+","+students[i].address.country);
                    }
                    break;
                case 2:
                    System.out.println("College details are: ");
                    String format1="|%1$-30s|%2$-30s|\n";
                    for(i=0;i<nObj;i++)
                    {
                        System.out.format(format1,"Name","Address");
                        System.out.format(format1,colleges[i].name,colleges[i].address.streetNo+","+colleges[i].address.city+","+colleges[i].address.state+","+colleges[i].address.country);
                    }
                    break ;
                case 3:
                    System.out.println("Employee details are: ");
                    String format2 = "|%1$-20s|%2$-15s|%3$-30s|\n";
                    for(i=0;i<nObj;i++) {
                        System.out.format(format2,"Name","Employee ID","Address");
                        System.out.format(format2,employees[i].name,employees[i].empID,employees[i].address.streetNo+","+employees[i].address.city+","+employees[i].address.state+","+employees[i].address.country);
                    }
                    break ;
                default:
                    return;
            }
        }
    }
}


/*

Output of the code:


Enter the number of objects: 
2
Enter the details of student 1 : 
Name: 
Khalid
USN: 
1RV20CS090
Address: 
Street Number: 
3
City: 
Bangalore
State: 
Karnataka
Country: 
India
Enter the details of student 2 : 
Name: 
Keerthi
USN: 
1RV20CS068
Address: 
Street Number: 
5
City: 
Chittradurga
State: 
Karnataka
Country: 
India
Enter the details of college 1 : 
Name: 
RVCE
Address: 
Street Number: 
2
City: 
Bangalore
State: 
Karnataka
Country: 
India
Enter the details of college 2 : 
Name: 
BMSCE
Address: 
Street Number: 
5
City: 
Bangalore
State: 
Karnataka
Country: 
India
Enter the details of Employee 1 : 
Name: 
Faizan
Employee ID: 
GOOGLE123
Address: 
Street Number: 
78
City: 
Hubli
State: 
Karnataka
Country: 
India
Enter the details of Employee 2 : 
Name: 
Darshan
Employee ID: 
Microsoft767
Address: 
Street Number: 
90
City: 
Hubli
State: 
karnataka
Country: 
India
1:Students	2:College	3:Employee
Enter the corresponding number of whose you want details: 
1
Students details are:
|Name                |USN            |Address                                 |
|Khalid              |1RV20CS090     |3,Bangalore,Karnataka,India             |
|Name                |USN            |Address                                 |
|Keerthi             |1RV20CS068     |5,Chittradurga,Karnataka,India          |
1:Students	2:College	3:Employee
Enter the corresponding number of whose you want details: 
2
College details are: 
|Name                          |Address                       |
|RVCE                          |2,Bangalore,Karnataka,India   |
|Name                          |Address                       |
|BMSCE                         |5,Bangalore,Karnataka,India   |
1:Students	2:College	3:Employee
Enter the corresponding number of whose you want details: 
3
Employee details are: 
|Name                |Employee ID    |Address                       |
|Faizan              |GOOGLE123      |78,Hubli,Karnataka,India      |
|Name                |Employee ID    |Address                       |
|Darshan             |Microsoft767   |90,Hubli,karnataka,India      |
1:Students	2:College	3:Employee
Enter the corresponding number of whose you want details: 
4


*/
