// Abstract Product Class
abstract class Product {
    public abstract void display();
}

// Concrete Products
class ConcreteProductA extends Product {
    @Override
    public void display() {
        System.out.println("This is Concrete Product A.");
    }
}

class ConcreteProductB extends Product {
    @Override
    public void display() {
        System.out.println("This is Concrete Product B.");
    }
}

// Creator Abstract Class
abstract class Creator {
    public abstract Product factoryMethod();
}

// Concrete Creators
class ConcreteCreatorA extends Creator {
    @Override
    public Product factoryMethod() {
        return new ConcreteProductA();
    }
}

class ConcreteCreatorB extends Creator {
    @Override
    public Product factoryMethod() {
        return new ConcreteProductB();
    }
}

// Client Code
public class FactoryMethodExample {
    public static void main(String[] args) {
        Creator creatorA = new ConcreteCreatorA();
        Product productA = creatorA.factoryMethod();
        productA.display();

        Creator creatorB = new ConcreteCreatorB();
        Product productB = creatorB.factoryMethod();
        productB.display();
    }
}
