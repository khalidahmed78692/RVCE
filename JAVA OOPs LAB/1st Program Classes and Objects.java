import java.util.Scanner;

class Complex{
    Complex(){

    }
    int Real,Imaginary;
    Complex(int real,int imaginary)
    {
        Real=real;
        Imaginary=imaginary;
    }
    Complex addition(Complex c1,Complex c2)
    {
        Complex temp=new Complex();
        temp.Real=c1.Real+c2.Real;
        temp.Imaginary=c1.Imaginary+c2.Imaginary;
        return temp;
    }
    Complex subtraction(Complex c1, Complex c2)
    {
        Complex temp=new Complex();
        temp.Real=c1.Real-c2.Real;
        temp.Imaginary=c1.Imaginary-c2.Imaginary;
        return temp;
    }
    void printComplexNumber()
    {
        System.out.println(this.Real+" + ("+this.Imaginary+")i");
    }
}

public class Program1 {                                                // make file name as Program1.java
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter first complex no: ");;
        int tempReal=sc.nextInt();
        int tempImaginary=sc.nextInt();
        Complex c1=new Complex(tempReal,tempImaginary);
        System.out.println("Enter second complex no: ");
        tempReal=sc.nextInt();
        tempImaginary=sc.nextInt();
        Complex c2=new Complex(tempReal,tempImaginary);
        System.out.println("First complex no is: ");
        c1.printComplexNumber();
        System.out.println("Second complex no is: ");
        c2.printComplexNumber();
        System.out.println("Addition of two complex number is: ");
        Complex c3=new Complex();
        c3=c3.addition(c1,c2);
        c3.printComplexNumber();
        System.out.println("Subtraction of two complex number is: ");
        c3=c3.subtraction(c1,c2);
        c3.printComplexNumber();
    }
}


/*
Output of the code:

Enter first complex no: 
8
45
Enter second complex no: 
879
63
First complex no is: 
8 + (45)i
Second complex no is: 
879 + (63)i
Addition of two complex number is: 
887 + (108)i
Subtraction of two complex number is: 
-871 + (-18)i





Enter first complex no: 
1
0
Enter second complex no: 
0
1
First complex no is: 
1 + (0)i
Second complex no is: 
0 + (1)i
Addition of two complex number is: 
1 + (1)i
Subtraction of two complex number is: 
1 + (-1)i

*/
