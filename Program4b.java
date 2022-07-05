package RVCE;
import CSE.ThirdSem;

class Cse_dept extends ThirdSem {
    public void WelcomeMessage(){
        super.WelcomeMessage();
        System.out.println("Public Method is overriding\nWelcome to CSE Dept");
    }
    protected void methodProtected(){
        super.methodProtected();
        System.out.println("Protected Method is overriding");
    }
    void methodDefault(){
//        super.methodDefault(); because this is different package but subclass so only public
        // and protected is accessible
        System.out.println("Default method is overriding");
    }
    private void methodPrivate(){
//        super.methodPrivate();
        System.out.println("Private Method");
    }
    public void display(){
        System.out.print("Inside the display method: Calling private method: ");
        methodPrivate();
    }
}

public class CseDepartment{
    public static void main(String[] args){
        Cse_dept cse_dept = new Cse_dept();
        ThirdSem thirdSem = new ThirdSem();

        // Using public method
        cse_dept.display();

        // Using public method
        cse_dept.WelcomeMessage();

        // Using Protected method
        cse_dept.methodProtected();

        // Using Default method
        cse_dept.methodDefault();

        // cse_dept.methodPrivate(); is not accessible because this is same package but not same class
        // so only private is not accessible here

        thirdSem.WelcomeMessage();
//        thirdSem.methodPrivate();  because this is different package and different class which
//        thirdSem.methodDefault();  means world, so only public is accessible
//        thirdSem.methodProtected();
    }
}
