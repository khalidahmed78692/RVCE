package prog5;

interface Animal{
    void eat();
    void sound();
}

interface TiredAnimal extends Animal{
    void action();
}

class Lion implements TiredAnimal{
    int i=1;

    public void eat(){
        System.out.println("Lion: Hunting");
    }
    public void sound(){
        System.out.println("Roaring");
    }
    public void action(){
        System.out.println("Roaming");
    }
    void lDescription(){
        System.out.println("Runs swiftly");
    }

}

class Snake implements TiredAnimal{
    int i=2;

    public void eat(){
        System.out.println("Snake: Swallowing");
    }
    public void sound(){
        System.out.println("Hissing");
    }
    public void action(){
        System.out.println("Sleeping");
    }
    void sDescription(){
        System.out.println("Crawls on the ground");
    }

}

public class FifthProgramPackagesAndInterfaces {
    public static void main(String[] args) {
        Lion l = new Lion();
        Snake s = new Snake();
        System.out.print(l.i+" ");
        l.eat();
        l.sound();
        l.action();
        l.lDescription();
        System.out.print(s.i+" ");
        s.eat();
        s.sound();
        s.action();
        s.sDescription();
        
        
        // after implementing below code, you will get no warnings, because we implementing even interface methods, so no warnings.
//        Animal a;
//        a=l;
//        a.eat();
//        a.sound();
//        TiredAnimal b;
//        b=l;
//        b.action();
    }
}

/*
Output of the code:
1 Lion: Hunting
Roaring
Roaming
Runs swiftly
2 Snake: Swallowing
Hissing
Sleeping
Crawls on the ground
*/
