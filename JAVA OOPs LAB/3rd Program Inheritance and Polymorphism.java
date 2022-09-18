import java.util.Scanner;

class Circle{
    double radius;
    String color;

    Circle(){
        radius=10.0;
        color="blue";
    }

    Circle(double radius){
        this.radius=radius;
        color="blue";
    }

    Circle(double radius,String color){
        this.radius=radius;
        this.color=color;
    }

    double getRadius(){
        return radius;
    }

    double getArea(){
        return Math.PI*radius*radius;
    }
}

class Cylinder extends Circle{
    double height;

    Cylinder(){
        super();
        height=15.0;
    }

    Cylinder(double height){
        super();
        this.height=height;
    }

    Cylinder(double radius,double height)
    {
        super(radius);
        this.height=height;
    }

    Cylinder(double height, double radius, String color)
    {
        super(radius,color);
        this.height=height;
    }

    double getHeight(){
        return height;
    }

    double getArea(){
        return 2*Math.PI*radius*(radius+height);
    }

    double getVolume(){
        return super.getArea()*height;
    }

    void display(){
        System.out.println("Radius is: "+radius);
        System.out.println("Height is: "+height);
        System.out.println("Color is: "+color);
        System.out.println("Area is: "+getArea());
        System.out.println("Volume is: "+getVolume());
    }

    void check(Cylinder c1, Cylinder c2,int i,int j)
    {
        if(c1.radius==c2.radius&&c1.height==c2.height&&c1.color.equalsIgnoreCase(c2.color))
            System.out.println("Cylinders "+(i+1)+" and "+(j+1)+" are equal");
        else
            System.out.println("Cylinders "+(i+1)+" and "+(j+1)+" are not equal");
    }
}

public class Program3 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        Cylinder[] cyl=new Cylinder[4];

        cyl[0]=new Cylinder();
        cyl[1]=new Cylinder(15.0);
        cyl[2]=new Cylinder(1.0,5.0);

        System.out.println("Enter the radius of the cylinder 4: ");
        double radius=sc.nextDouble();
        System.out.println("Enter the height of the cylinder 4: ");
        double height=sc.nextDouble();
        sc.nextLine();
        System.out.println("Enter the color of the cylinder 4: ");
        String color=sc.nextLine();

        cyl[3]=new Cylinder(radius,height,color);

        int i;
        for(i=0;i<4;i++)
        {
            System.out.println("The dimension of cylinder "+(i+1)+" is: ");
            cyl[i].display();
        }

        for(i=0;i<4;i++)
            for(int j=i+1;j<4;j++)
                cyl[i].check(cyl[i],cyl[j],i,j);

    }
}


/*

Output of the code:

Enter the radius of the cylinder 4: 
12
Enter the height of the cylinder 4: 
13
Enter the color of the cylinder 4: 
red
The dimension of cylinder 1 is: 
Radius is: 10.0
Height is: 15.0
Color is: blue
Area is: 1570.7963267948965
Volume is: 4712.38898038469
The dimension of cylinder 2 is: 
Radius is: 10.0
Height is: 15.0
Color is: blue
Area is: 1570.7963267948965
Volume is: 4712.38898038469
The dimension of cylinder 3 is: 
Radius is: 1.0
Height is: 5.0
Color is: blue
Area is: 37.69911184307752
Volume is: 15.707963267948966
The dimension of cylinder 4 is: 
Radius is: 13.0
Height is: 12.0
Color is: red
Area is: 2042.0352248333656
Volume is: 6371.149901480101
Cylinders 1 and 2 are equal
Cylinders 1 and 3 are not equal
Cylinders 1 and 4 are not equal
Cylinders 2 and 3 are not equal
Cylinders 2 and 4 are not equal
Cylinders 3 and 4 are not equal

*/
