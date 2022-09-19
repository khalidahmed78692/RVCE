import java.util.Scanner;

interface PerformOperation{
    boolean operation(int a);
}

class check{
    PerformOperation isOdd=(int a)->a%2!=0;
}

public class Program8{
    public static void main(String[] args) {
        PerformOperation isPrime=(int a)->{
            for(int i=2;i<=a/2;i++)
                if(a%i==0)
                    return false;
            return true;
        };

        PerformOperation isPalindrome=(int a)->{
            int t=a,n=0;
            while(t>0)
            {
                n*=10;
                n+=t/10;
                t/=10;
            }
            return a==n;
        };

        Scanner sc=new Scanner(System.in);
        check c = new check();
        int num;
        byte choice;
        while(true)
        {
            System.out.println("1:isOdd\t2:isPrime\t3:isPalindrome");
            System.out.println("Enter your choice: ");
            choice=sc.nextByte();
            System.out.println("Enter the number: ");
            num=sc.nextInt();
            switch (choice){
                case 1:
                    System.out.println("isOdd is: "+c.isOdd.operation(num));
                    break;
                case 2:
                    System.out.println("isPrime is: "+isPrime.operation(num));
                    break;
                case 3:
                    System.out.println("isPalindrome is: "+isPalindrome.operation(num));
                    break;
                default:
                    System.exit(0);
            }
        }
    }
}


/*

Output of the code:

1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
1
Enter the number: 
456
isOdd is: false
1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
1
Enter the number: 
459
isOdd is: true
1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
2
Enter the number: 
1265
isPrime is: false
1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
1
Enter the number: 
17
isOdd is: true
1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
3
Enter the number: 
123321
isPalindrome is: true
1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
3
Enter the number: 
1654
isPalindrome is: false
1:isOdd	2:isPrime	3:isPalindrome
Enter your choice: 
4


*/
