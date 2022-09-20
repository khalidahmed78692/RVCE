package RVCE;
import CSE.ThirdSem;

class CseDept extends ThirdSem{

    public void message(){
        super.message();
        System.out.println("Public method is overriding");
    }

    void defaultMethod(){
//        super.defaultMethod;// default method cannot be accessed from different package or subclass
        System.out.println("Default method is overriding");
    }

    protected void protectedMethod(){
        super.protectedMethod();
        System.out.println("Protected method is overriding");
    }

    private void privateMethod(){
//        super.privateMethod();// private method cannot be accessed from different package, or subclass, or world
        System.out.println("Private method is overriding");
    }

    void display(){
        System.out.println("Inside display");
        privateMethod();// this private method
    }
}

public class CSEDepartment {
    public static void main(String[] args) {
        CseDept cseDept=new CseDept();
        ThirdSem thirdSem=new ThirdSem();

        // Public method is available to the world --> public method of other package and other class is used here
        thirdSem.message();

        // default method is not available to the world
        // thirdSem.defaultMethod(); // if you remove this comment, it shows an error

        // protected method is not available to the world
//        thirdSem.protectedMethod(); // if you remove this comment , it shows an error

        // protected method is not available to the world
//        thirdSem.protectedMethod();// if you remove this comment, it shows an error

        cseDept.protectedMethod();// accessible within same package
        cseDept.defaultMethod();// accessible within same package
//        cseDept.privateMethod();// not accessible within same package only accessible with same class so below state
        // accesses private method indirectly
        cseDept.display();// display method and private method is in same class, so display can access privateMethod of the same class
        cseDept.message();
    }
}


/*

Output of the code:

Welcome to 3rd sem- Young budding engineers
Protected method is accessible
Protected method is overriding
Default method is overriding
Inside display
Protected method is overriding
Welcome to 3rd sem- Young budding engineers
Public method is overriding


*/
